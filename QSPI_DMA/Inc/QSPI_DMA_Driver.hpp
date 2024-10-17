#ifndef QSPI_DMA_DRIVER_HPP
#define QSPI_DMA_DRIVER_HPP

#include <stm32h7xx_hal_qspi.h>

// https://github.com/STMicroelectronics/STM32CubeH7/tree/master/Projects/STM32H743I-EVAL/Examples/QSPI

class QSPI_DMA_Driver
{
private:
	QSPI_HandleTypeDef &handle;

public:
	QSPI_DMA_Driver(QSPI_HandleTypeDef *hqspi) : handle(*hqspi) {}
};

#endif // QPSI_DMA_DRIVER_HPP
