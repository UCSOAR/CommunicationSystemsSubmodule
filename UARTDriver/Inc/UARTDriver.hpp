#ifndef CUBE_UART_DRIVER_DMA_HPP_
#define CUBE_UART_DRIVER_DMA_HPP_

#include "SystemDefines.hpp"
#include "cmsis_os.h"
#include <stdlib.h>

#define MAX_DMA_BUFFER_LEN     64
#define STM_H7xx

/* UART Receiver Base Class ------------------------------------------------------------------*/
/**
 * @brief Any classes that are expected to receive using a UART driver
 *		  must derive from this base class and provide an implementation
 *		  for InterruptRxData
 */
class UARTReceiverBase
{
public:
	virtual void InterruptRxData(uint8_t errors) = 0;
};

/* Functions to Read from and Write to circular buffers */
uint8_t read_byte(uint8_t*& read_head, uint8_t* buffer, uint16_t bufferSize);

class UARTDriver{
public:
    UARTDriver(USART_TypeDef* uartInstance, DMA_TypeDef* dmaInstance, uint16_t DMA_DATA_STREAM_tx, uint16_t DMA_DATA_STREAM_rx) :
		kUart_(uartInstance),
    	kDma_(dmaInstance),
        DMA_DATA_STREAM_tx(DMA_DATA_STREAM_tx),
        DMA_DATA_STREAM_rx(DMA_DATA_STREAM_rx),
        rxReceiver_(nullptr) {}

    // DMA (buffer reading/writing) Functions
    bool Transmit(uint8_t* data, uint16_t len);
    bool Receive(uint8_t* charBuf, UARTReceiverBase* receiver);

    // Interrupt Handlers
    void HandleIRQ_UART(); // This MUST be called inside USARTx_IRQHandler

protected:
    // Flag? for the DMA buffer filled over the bytes being read
    bool DMA_DATA_OVERRUN_FLAG = false;

    // Helper Functions
    bool HandleAndClearRxError();
    bool GetRxErrors();
    uint8_t start_tx_data_transfer(uint16_t len, uint8_t* buffer_adr);
    char SendData(uint8_t* data, uint16_t len);

    // constants
    USART_TypeDef* kUart_; // Stores the UART instance
    DMA_TypeDef* kDma_; // Stores the DMA instance
    uint16_t DMA_DATA_STREAM; // stores a variable to the DMA_DATA_STREAM so its not hard coded

	/**
	 * @brief DMA buffers
	 * @details Messages will be in the form (bytewise): [message length1][message length0][message data][checkbit/stopbit]
	 */
    uint8_t rx_buffer[MAX_DMA_BUFFER_LEN]; // need a static allocated buffer to store recieved data while we aren't recieveing data (circular)
    uint8_t lin_tx_buffer[MAX_DMA_BUFFER_LEN]; // static allocated buffer to store data to be sent (linear)

    // variables
	uint8_t* rx_read_head = rx_buffer; 	// Circular buffer read head
	UARTReceiverBase* rxReceiver_; // Stores a pointer to the receiver object
};

#endif
