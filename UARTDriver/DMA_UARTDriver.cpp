/** ********************************************************************************
* @file    DMA_UARTDriver.cpp
* @author  Noah
* @date    Nov 8, 2024
* @brief ******************************************************************************** */
/************************************ * INCLUDES ************************************/
#include "DMA_UARTDriver.hpp"
/************************************ * PRIVATE MACROS AND DEFINES ************************************/
/************************************ * VARIABLES ************************************/
/************************************ * FUNCTION DECLARATIONS ************************************/

/**
 * @brief Starts a DMA transmission
 * @param data The data to transmit
 * @param len The length of the data to transmit
 * @return True if the transmission was successful, False otherwise
 */
bool DMA_UARTDriver::Transmit(uint8_t* data, uint16_t len);

/**
 * @brief Reads a byte from a circular buffer, increments buffer for valid bytes (waits for valid data otherwise)
 * @return the byte value
 */
uint8_t DMA_UARTDriver::read_byte(uint8_t*& read_head, uint8_t* buffer, uint16_t bufferSize);

/**
* @brief Read the uart data buffer and store it in a passed data array
* @param charBuf buffer to store the read data
* @attention calling function must handle cases where the read message overflows charBuf
* @attention calling function should also call this until it returns true
*      allowing for the function to be called before a message is complete
* @param buffIdx the index in charBuf that is currently being wrote to
* @return TRUE if interrupt was successfully enabled, FALSE otherwise
*/
bool DMA_UARTDriver::Receive(uint8_t* charBuf, uint8_t& buffIdx);


/************************************ * FUNCTION DEFINITIONS ************************************/

bool DMA_UARTDriver::Transmit(uint8_t* data, uint16_t len)
{
	uint8_t metabytes = 0;
	if(!is_Debug){
		metabytes = 2; // add stop bytes for non-debug messages
	}

	// HAL DMA transmission
	// make sure the data wont overflow the buffer
	if(len + metabytes > MAX_DMA_BUFFER_LEN){
		return false;
	}

	// check if current transfer is complete
	for (int i = 0; HAL_UART_GetState(hUart_) != HAL_UART_STATE_READY; i++){
		if(i > 10000) break; // TEMP fix for hal uart not readying error
	}

	// copy the message to the buffer
	for(int i = 0; i < len; i++){
		lin_tx_buffer[i] = data[i]; // sets the data to the message buffer, with an offset if its not to serial
	}

	// set the stop bytes in the buffer
	// can ignore for terminal communications
	if(!isdebug){
		lin_tx_buffer[len] = '\r';
		lin_tx_buffer[len + 1] = '\n';
	}

	// starts the process of transmitting the data via DMA
	if(HAL_UART_Transmit_DMA(hUart_, (uint8_t*)lin_tx_buffer, len + metabytes)!= HAL_OK)
	  {
		/* Transfer error in transmission process */
		return false;
	  }

	return true;
}

bool UARTDriver::Receive(uint8_t* charBuf, uint8_t& buffIdx)
{

	if(HAL_UART_Receive_DMA(hUart_, (uint8_t *)rx_buffer, MAX_DMA_BUFFER_LEN) != HAL_OK){

	} // make sure we're receiving

	// read the next byte in the circular buffer
	charBuf[buffIdx] = read_byte(rx_read_head, rx_buffer, MAX_DMA_BUFFER_LEN);

	if(charBuf[buffIdx] && is_Debug) Transmit(charBuf+buffIdx, 1); // send input response to debug terminal

	// makes debug messages cleaner by eliminating the metadata
	// requires specific messages to work (ie '\r\n' terminated)
	// loop until end of line character
	while(charBuf[buffIdx] != '\n'){

		if(charBuf[buffIdx] == '\0') return false; // wait until message is finished

		buffIdx++;
		charBuf[buffIdx] = read_byte(rx_read_head, rx_buffer, MAX_DMA_BUFFER_LEN); // continue to copy data
	}

	charBuf[buffIdx-1] = '\0'; // null terminate for a string
	charBuf[buffIdx] = '\0';
	buffIdx = 0; // reset the buffer

	return true;
}

uint8_t UARTDriver::read_byte(uint8_t*& read_head, uint8_t* buffer, uint16_t bufferSize)
{
    // read the byte from the current read head
    uint8_t copy_to = *read_head;

    // return if the read data hasnt been updated (no unread data)
    if(copy_to == 0) return '\0';

    // reset the address to a read state
    *read_head = '\0';

    // increment the read head, loop it around the circular buffer
    if(read_head - buffer < bufferSize - 1){
        read_head++;
    }else{
        read_head = buffer;
    }

    return copy_to;
}