#ifndef CUBE_UART_DRIVER_DMA_HPP_
#define CUBE_UART_DRIVER_DMA_HPP_

#include "SystemDefines.hpp"
#include "cmsis_os.h"
#include <stdlib.h>

#define ARRAY_LEN(x)            (sizeof(x) / sizeof((x)[0]))
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
void write_byte(uint8_t byte, uint8_t*& write_head, uint8_t* buffer, uint16_t bufferSize);

class UARTDriver{
public:
    UARTDriver(USART_TypeDef* uartInstance, DMA_TypeDef* dmaInstance, uint16_t DMA_DATA_STREAM) :
		kUart_(uartInstance),
    	kDma_(dmaInstance),
        DMA_DATA_STREAM(DMA_DATA_STREAM) {}

    // DMA (buffer reading/writing) Functions
    bool Transmit(uint8_t* data, uint16_t len);
    bool Recieve(uint8_t* charBuf);

    // Interrupt Handlers
    void HandleIRQ_UART(); // This MUST be called inside USARTx_IRQHandler

protected:
    // Flag? for the DMA buffer filled over the bytes being read
    bool DMA_DATA_OVERRUN_FLAG = false;

    // Helper Functions
    bool HandleAndClearRxError();
    bool GetRxErrors();

    // constants
    USART_TypeDef* kUart_; // Stores the UART instance
    DMA_TypeDef* kDma_; // Stores the DMA instance
    
	/* DMA buffers */
	/**
	 * @brief DMA buffers
	 * @details Messages will be in the form (bytewise): [message length1][message length0][message data][checkbit/stopbit]
	 */
    uint8_t rx_buffer[MAX_DMA_BUFFER_LEN]; // need a static allocated buffer to store recieved data while we aren't recieveing data (circular)
    uint8_t lin_tx_buffer[MAX_DMA_BUFFER_LEN]; // static allocated buffer to store data to be sent (linear)

	// Circular buffer read and write heads
	uint8_t* rx_read_head = usart_rx_dma_buffer; // pointer to read from rx_buffer

    uint16_t DMA_DATA_STREAM;

	// UNUSED VARIABLES
	/* Message queue ID */
    osMessageQueueId_t usart_rx_dma_queue_id;
};

#endif