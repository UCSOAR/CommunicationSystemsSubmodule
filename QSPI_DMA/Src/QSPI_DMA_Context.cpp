#include "../Inc/QSPI_DMA_Context.hpp"

QSPI_DMA_Result QSPI_DMA_Context::transfer(size_t bytes, uint64_t max_delay = HAL_MAX_DELAY) {
	const size_t new_bytes_used = this->amount_used + bytes;

	if (new_bytes_used > this->flash_capacity) {
		return QSPI_DMA_Result::Overflow;
	}

	HAL_DMA_Start(&this->dma_handle, (uint32_t) this->src_buffer, (uint32_t) this->dest_buffer, bytes);

	HAL_StatusTypeDef status = HAL_BUSY;

	while (status != HAL_OK) {
		status = HAL_DMA_PollForTransfer(&this->dma_handle, HAL_DMA_FULL_TRANSFER, max_delay);
	  __NOP();
	}

	if (!status) {
		return QSPI_DMA_Result::Err;
	}

	this->amount_used = new_bytes_used;

	return QSPI_DMA_Result::Ok;
}
