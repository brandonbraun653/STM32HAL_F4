/********************************************************************************
 *  File Name:
 *    mock_stm32f4_hal_uart_defs.hpp
 *
 *  Description:
 *    Provides includes, macros, and type definitions needed to compile UART mock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32F4_HAL_UART_DEFS_HPP
#define MOCK_STM32F4_HAL_UART_DEFS_HPP

#include <cstdint>
#include <cstdlib>

#define __IO volatile

typedef struct __DMA_HandleTypeDef
{
} DMA_HandleTypeDef;

#endif /* !MOCK_STM32F4_HAL_UART_DEFS_HPP */