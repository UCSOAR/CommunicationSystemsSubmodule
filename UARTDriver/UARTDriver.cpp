#include "UARTDriver.hpp"


uint8_t read_byte(uint8_t*& read_head, uint8_t* buffer, uint16_t bufferSize)
{
    // read the byte from the current read head
    uint8_t copy_to = *read_head;

    // increment the read head, loop it around the circular buffer
    if(read_head - buffer < bufferSize + 1){
        read_head++;
    }else{
        read_head = buffer;
    }

    return copy_to;
}

/**
 * @brief           Send data on DMA
 * @note            Contains API calls only for the H7xx chips
 * @return          `1` if transfer just started
 */
uint8_t UARTDriver::start_tx_data_transfer(uint16_t len, uint8_t* buffer_adr)
{
    /* Disable channel if enabled */
    LL_DMA_DisableStream(kDma_, DMA_DATA_STREAM_tx);

    /* Clear all flags */
    LL_DMA_ClearFlag_TC0(kDma_); // assuming DMA_DATA_STREAM == stream 0
    LL_DMA_ClearFlag_HT0(kDma_); // USART8
    LL_DMA_ClearFlag_TE0(kDma_);
    LL_DMA_ClearFlag_DME0(kDma_);
    LL_DMA_ClearFlag_FE0(kDma_);

    /* Prepare DMA data and length */
    LL_DMA_SetDataLength(kDma_, DMA_DATA_STREAM_tx, len);
    LL_DMA_SetMemoryAddress(kDma_, DMA_DATA_STREAM_tx, (uint32_t)buffer_adr);

    /* Start transfer */
    LL_DMA_EnableStream(kDma_, DMA_DATA_STREAM_tx);

    return true;
}

/**
 * @brief Transmits data via the DMA
 * @brief Should be called until returns non-zero
 * @param data, len The data to transmit, the length of data to transmit
 * @return 0 if any previous data is still transmitting, 1 if the transmit was successfully started, -1 if the data is too large to transmit
 * @note need to add protection from multiple threads calling this function at once
 */
bool UARTDriver::Transmit(uint8_t* data, uint16_t len)
{

	int n = SendData(data, len); // try to send the data
	for(int i = 0; !n; i++){
		n = SendData(data, len); // continually try, waiting for any current transfers to finish

		// set a timeout
		if(i > 1000) {
			SOAR_ASSERT(false, "Transmit operation timed out");
			return false;
		}
	}
	if(n == -1){
		SOAR_ASSERT(false, "Data too large to transmit\n"); // if this error is called, just set MAX_DMA_BUFFER_LEN to a number greater than 64
		return false;
	}

	return true;
}

char UARTDriver::SendData(uint8_t* data, uint16_t len){
    // make sure the data wont overflow the buffer
    if(len + 3 > MAX_DMA_BUFFER_LEN){
        return -1;
    }

    // make sure there is no current transmit on the DMA channel
    if (!LL_DMA_GetDataLength(kDma_, DMA_DATA_STREAM_tx)) {
        // "Once the stream is enabled, the return value indicates the remaining bytes to be transmitted."
        return 0; // if there are bytes remaining to be transmitted, dont start transmitting a new message
    }

    // set length bytes for the message
    lin_tx_buffer[0] = (uint8_t)(len & 0xFF00 >> 8);
    lin_tx_buffer[1] = (uint8_t)(len & 0x00FF);

    // copy the message to the buffer
    for(int i = 0; i < len; i++){
        lin_tx_buffer[i+2] = data[i];
    }

    // set the checkbyte in the buffer
    lin_tx_buffer[len+2] = data[len-2] | (uint8_t)(len & 0x00FF); // takes the last byte of data and &'s it with length byte to get some random check

    // starts the process of transmitting the data via DMA
    start_tx_data_transfer(len + 3, lin_tx_buffer);

    return 1;
}

/**
* @brief Reads the circular buffer and copies the data into charBuf
* @param charBuf, receiver
* @return TRUE if data was successfully read, false otherwise
* @note can make reading set the read head to some placeholder bit so read head wont advance until its not a placeholder bit
*/
bool UARTDriver::Receive(uint8_t* charBuf, UARTReceiverBase* receiver)
{
    // read the length bytes
    uint16_t len = read_byte(rx_read_head, rx_buffer, 64) << 8;
    len |= read_byte(rx_read_head, rx_buffer, 64);

    // copy the data bytes into charBuf
    for(int i = 0; i < len; i++){
        // if it is a placeholder byte, wait until it is not
        uint8_t byte = read_byte(rx_read_head, rx_buffer, 64);

            for(int j; byte == '\0'; byte = read_byte(rx_read_head, rx_buffer, 64), j++){
                if(i >= len -1 ) {break;} // skip the string null terminator
                if(j > 1000) return false; // configure a timeout
            }

        // write the current byte
        charBuf[i] = byte;

        // replace the just-read byte in the read buffer with 0 to indicate it doesnt contain data
        if(rx_read_head == rx_buffer){
            rx_buffer[MAX_DMA_BUFFER_LEN - 1] = 0;
        }else{
            *(rx_read_head - 1) = 0;
        }
    }
    // null terminate the message (replace the stop bit in the message '\r')
    charBuf[len-1] = '\0';

    // read the check byte
    if(read_byte(rx_read_head, rx_buffer, 64) != (charBuf[len - 2] | (len & 0x00FF))){
        DMA_DATA_OVERRUN_FLAG = true;
        return false; // returns false if the check byte is not what was calculated
    }                 // indicates that the write head overwrote the read head

    // set the pointer to the reciever object so we can call its interrupt
    rxReceiver_ = receiver;

    // returns true if the data was successfully read
    return true;
}

/**
 * @brief Clears any error flags that may have been set
 * @return true if flags had to be cleared, false otherwise
 */
bool UARTDriver::HandleAndClearRxError()
{
    bool shouldClearOverflowFlag = false;
    bool shouldClearFlags = false;
    if (LL_USART_IsActiveFlag_ORE(kUart_)) {
        shouldClearFlags = true;
    }
    if (LL_USART_IsActiveFlag_NE(kUart_)) {
        shouldClearFlags = true;
    }
    if(LL_USART_IsActiveFlag_FE(kUart_)) {
        shouldClearFlags = true;
    }
    if(LL_USART_IsActiveFlag_PE(kUart_)) {
        shouldClearFlags = true;
    }
    if(DMA_DATA_OVERRUN_FLAG)
        shouldClearOverflowFlag = true;

    // Clearing the ORE here also clears PE, NE, FE, IDLE
    if(shouldClearFlags)
        LL_USART_ClearFlag_ORE(kUart_);

    return !shouldClearFlags || !shouldClearOverflowFlag;
}

/**
 * @brief Checks UART Rx error flags, if any are set returns true
 * @return true if any error flags are set, false otherwise
 */
bool UARTDriver::GetRxErrors()
{
    bool hasErrors = false;

    if (LL_USART_IsActiveFlag_ORE(kUart_)) {
        hasErrors = true;
    }
    else if (LL_USART_IsActiveFlag_NE(kUart_)) {
        hasErrors = true;
    }
    else if(LL_USART_IsActiveFlag_FE(kUart_)) {
        hasErrors = true;
    }
    else if(LL_USART_IsActiveFlag_PE(kUart_)) {
        hasErrors = true;
    }else if(DMA_DATA_OVERRUN_FLAG){
        hasErrors = true;
    }

    return hasErrors;
}

/**
 * @brief Handles an interrupt for the UART
 * @attention MUST be called inside USARTx_IRQHandler
 */
void UARTDriver::HandleIRQ_UART()
{
        /* Check for IDLE line interrupt */
    if (LL_USART_IsEnabledIT_IDLE(kUart_) && LL_USART_IsActiveFlag_IDLE(kUart_)) {
        LL_USART_ClearFlag_IDLE(kUart_);        /* Clear IDLE line flag */
        usart_rx_check();                       /* Check for data to process */
    }

    // Call the callback if RXNE is set
    if (LL_USART_IsActiveFlag_RXNE(kUart_)) {
        // Call the receiver interrupt
        if(rxReceiver_ != nullptr) {
            rxReceiver_->InterruptRxData(GetRxErrors());
        }
    }
}

/**
 * @brief           DMA interrupt handler for USART TX
 */
void UARTDriver::DMA_Stream_tx_IRQHandler(void) {
    /* Check half-transfer complete interrupt */
    if (LL_DMA_IsEnabledIT_HT(kDma_, DMA_DATA_STREAM_tx) && LL_DMA_IsActiveFlag_HT0(kDma_)) {
        LL_DMA_ClearFlag_HT0(kDma_);             /* Clear half-transfer complete flag */
        usart_rx_check();                       /* Check for data to process */
    }

    /* Check transfer-complete interrupt */
    if (LL_DMA_IsEnabledIT_TC(kDma_, DMA_DATA_STREAM_tx) && LL_DMA_IsActiveFlag_TC0(kDma_)) {
        LL_DMA_ClearFlag_TC0(kDma_);             /* Clear transfer complete flag */
        usart_rx_check();                       /* Check for data to process */
    }

    /* Implement other events when needed */
}

/**
 * @brief           DMA interrupt handler for USART RX
 */
void UARTDriver::DMA1_Stream1_IRQHandler(void) {
    /* Check transfer complete */
    if (LL_DMA_IsEnabledIT_TC(kDma_, DMA_DATA_STREAM_rx) && LL_DMA_IsActiveFlag_TC1(kDma_)) {
        LL_DMA_ClearFlag_TC1(kDma_);             /* Clear transfer complete flag */
        lwrb_skip(&usart_tx_rb, usart_tx_dma_current_len);/* Skip sent data, mark as read */
        usart_tx_dma_current_len = 0;           /* Clear length variable */
        usart_start_tx_dma_transfer();          /* Start sending more data */
    }

    /* Implement other events when needed */
}

