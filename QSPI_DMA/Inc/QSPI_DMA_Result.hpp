#ifndef QSPI_DMA_Result_RESULT_HPP
#define QSPI_DMA_Result_RESULT_HPP

#include <stm32h7xx_hal.h>

/**
 * The `Ok` variant is the only truthy variant
 */
enum class QSPI_DMA_Result { Ok = 1, Err = -1, Busy = -2, Timeout = -3, Overflow = -4 };

inline bool operator!(QSPI_DMA_Result error) { return error != QSPI_DMA_Result::Ok; }

inline bool operator==(QSPI_DMA_Result error, bool value) {
  return (error == QSPI_DMA_Result::Ok) == value;
}

inline bool operator!=(QSPI_DMA_Result error, bool value) {
  return !(error == value);
}

#endif  // QSPI_DMA_Result_HPP
