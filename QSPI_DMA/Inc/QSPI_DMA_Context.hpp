#ifndef QSPI_DMA_CONTEXT_HPP
#define QSPI_DMA_CONTEXT_HPP

#include <stm32h7xx_hal_qspi.h>

#include "./QSPI_DMA_Result.hpp"

// https://github.com/STMicroelectronics/STM32CubeH7/tree/master/Projects/STM32H743I-EVAL/Examples/QSPI

class QSPI_DMA_Context
{
private:
	QSPI_HandleTypeDef &qspi_handle;
	DMA_HandleTypeDef &dma_handle;

	uint8_t *src_buffer;
	uint8_t *dest_buffer;

	// Total flash capacity in bytes
	size_t flash_capacity;

	// Amount of bytes that
	size_t amount_used;

public:
	QSPI_DMA_Context(
			QSPI_HandleTypeDef *hqspi,
			DMA_HandleTypeDef *hdma,
			uint8_t *src_buffer,
			uint8_t *dest_buffer,
			size_t flash_capacity,
	) :
		qspi_handle(*hqspi),
		dma_handle(*hdma),
		src_buffer(src_buffer),
		dest_buffer(dest_buffer),
		flash_capacity(flash_capacity),
		amount_used(0)
	{}

	QSPI_DMA_Result transfer(size_t bytes, uint64_t max_delay = HAL_MAX_DELAY);
};

#endif // QPSI_DMA_CONTEXT_HPP
