/** ********************************************************************************
 * @file    DMA_UARTDriver.hpp
 * @author  Noah
 * @date    Nov 8, 2024
 * @brief ******************************************************************************** */
#ifndef SOARCOMMUNICATIONS_UART_INC_DMA_UARTDRIVER_HPP_
#define SOARCOMMUNICATIONS_UART_INC_DMA_UARTDRIVER_HPP_
/************************************ * INCLUDES ************************************/
#include "SystemDefines.hpp"
#include "cmsis_os.h"
/************************************ * MACROS AND DEFINES ************************************/
#define MAX_DMA_BUFFER_LEN 64
/************************************ * TYPEDEFS ************************************/
/************************************ * CLASS DEFINITIONS ************************************/

/* UART Driver Class ------------------------------------------------------------------*/
/**
 * @brief This is a basic UART driver designed for DMA Rx and Tx
 *	      based on the STM32 HAL Library
 */
class DMA_UARTDriver
{
public:
	DMA_UARTDriver(UART_HandleTypeDef& uartInstance, bool debug = false) :
		hUart_(&uartInstance),
		is_Debug(debug) {
		// prime the reciever
		HAL_UART_Receive_DMA(hUart_, (uint8_t *)rx_buffer, MAX_DMA_BUFFER_LEN);
	}

	// DMA functions
	bool Transmit(uint8_t* data, uint16_t len);
	bool Receive(uint8_t* charBuf, uint8_t& buffIdx); // DMA reciever function

protected:
	// Helper Functions
	uint8_t read_byte(uint8_t*& read_head, uint8_t* buffer, uint16_t bufferSize);

	// Constants
	UART_HandleTypeDef* hUart_; // Stores the UART instance

	// Variables
	uint8_t rx_buffer[MAX_DMA_BUFFER_LEN]; // Stores a pointer to the buffer to store the received data
	uint8_t* rx_read_head = rx_buffer; 	// Circular buffer read head
	uint8_t lin_tx_buffer[MAX_DMA_BUFFER_LEN]; // static allocated buffer to store data to be sent (linear)
	bool is_Debug; // debug value for output formatting
};
/************************************ * FUNCTION DECLARATIONS ************************************/
#endif /* EXAMPLE_TASK_HPP_ */
