#include "UARTDriver.hpp"

// can get current data length with LL_DMA_GetDataLength(DMA1, LL_DMA_CHANNEL_2)


void write_byte(uint8_t byte, uint8_t*& write_head, uint8_t* buffer, uint16_t bufferSize)
{
    // write the byte to the current write head
    *write_head = byte;

    // increment the write head, loop it around the circular buffer
    if(write_head - buffer < bufferSize + 1){
        write_head++;
    }else{
        write_head = buffer;
    }
}

uint8_t read_byte(uint8_t*& read_head, uint8_t* buffer, uint16_t bufferSize)
{
    // read the byte from the current read head
    uint8_t copy_to = *read_head;

    // after reading the byte, set the byte at the read head to some placeholder bit
    *read_head = 0xFF;

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
uint8_t
usart_start_tx_dma_transfer(uint16_t len, uint16_t* buffer_adr) 
{
    /* Disable channel if enabled */
    LL_DMA_DisableStream(kDma_, DMA_DATA_STREAM);

    /* Clear all flags */
    LL_DMA_ClearFlag_TC1(kDma_);
    LL_DMA_ClearFlag_HT1(kDma_);
    LL_DMA_ClearFlag_TE1(kDma_);
    LL_DMA_ClearFlag_DME1(kDma_);
    LL_DMA_ClearFlag_FE1(kDma_);
    
    /* Prepare DMA data and length */
    LL_DMA_SetDataLength(kDma_, DMA_DATA_STREAM, len);
    LL_DMA_SetMemoryAddress(kDma_, DMA_DATA_STREAM, buffer_adr);

    /* Start transfer */
    LL_DMA_EnableChannel(kDma_, DMA_DATA_STREAM);

    return true;
}


/**
 * @brief Transmits data via the DMA
 * @brief Should be called until returns non-zero
 * @param data, len The data to transmit, the length of data to transmit
 * @return 0 if any previous data is still transmitting, 1 if the transmit was successfully started, -1 if the data is too large to transmit
 * @note need to add protection from multiple threads calling this function at once
 */
char UARTDriver::Transmit(uint8_t* data, uint16_t len)
{
    // make sure the data wont overflow the buffer
    if(len + 3 > MAX_DMA_BUFFER_LEN){
        return -1;
    }

    // make sure there is no current transmit on the DMA channel
    if (!LL_DMA_GetDataLength(_kDma, DMA_DATA_STREAM)) {
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
    lin_tx_buffer[len+2] = data[len-1] | (uint8_t)(len & 0x00FF); // takes the last byte of data and &'s it with length byte to get some random check

    // starts the process of transmitting the data via DMA
    usart_start_tx_dma_transfer(len + 3, lin_tx_buffer);

    return true;
}

/**
* @brief Reads the circular buffer and copies the data into charBuf
* @param charBuf, receiver
* @return TRUE if interrupt was successfully enabled, FALSE otherwise
* @note can make reading set the read head to some placeholder bit so read head wont advance until its not a placeholder bit
*/
bool UARTDriver::Receive(uint8_t* charBuf, UARTReceiverBase* receiver)
{
    // read the length bytes
    uint16_t len = read_byte(rx_read_head, rx_buffer, 64) << 8;
    len |= read_byte(rx_read_head, rx_buffer, 64);

    // copy the data bytes into charBuf
    for(int i = 0; i < len; i++){
        charBuf[i] = read_byte(rx_read_head, rx_buffer, 64);
    }
    // read the check byte
    if(read_byte(rx_read_head, rx_buffer, 64) != charBuf[len - 1] | (len & 0x00FF)){
        DMA_DATA_OVERRUN_FLAG = true;
        return false; // returns false if the check byte is not what was calculated
    }                 // indicates that the write head overwrote the read head

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
    // Call the callback if RXNE is set
    if (LL_USART_IsActiveFlag_RXNE(kUart_)) {
        // Read the data from the data register
        if (rxCharBuf_ != nullptr) {
            *rxCharBuf_ = LL_USART_ReceiveData8(kUart_);
        }

        // Call the receiver interrupt
        if(rxReceiver_ != nullptr) {
            rxReceiver_->InterruptRxData(GetRxErrors());
        }
    }
}