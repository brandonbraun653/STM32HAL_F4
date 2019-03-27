/********************************************************************************
 *  File Name:
 *    mock_stm32f4xx_hal_uart.h
 *
 *  Description:
 *    Mocks the STM32 UART HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32F4_HAL_UART_HPP
#define MOCK_STM32F4_HAL_UART_HPP

/* Mock Includes */
#include <gmock/gmock.h>
#include "mock_stm32f4_hal_uart_defs.hpp"

/* STM32 Includes */
#include "stm32f4xx_hal_uart.h"

class STM32HAL_F4_UART_Interface
{
public:
  virtual ~STM32HAL_F4_UART_Interface() = default;

  virtual HAL_StatusTypeDef HAL_UART_Init( UART_HandleTypeDef *huart );

};

class STM32HAL_F4_MOCK_UART : public STM32HAL_F4_UART_Interface
{
public:
  virtual ~STM32HAL_F4_MOCK_UART() = default;

  MOCK_METHOD1( HAL_UART_Init, HAL_StatusTypeDef( UART_HandleTypeDef * ) );
};


extern STM32HAL_F4_MOCK_UART *uartMock;

#endif /* !MOCK_STM32F4_HAL_UART_HPP */