/********************************************************************************
 *  File Name:
 *    mock_stm32f4_hal_uart.cpp
 *  
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *  
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32f4_hal_uart.hpp"

STM32HAL_F4_MOCK_UART *uartMock = nullptr;

HAL_StatusTypeDef HAL_UART_Init( UART_HandleTypeDef *huart )
{
  return uartMock->HAL_UART_Init( huart );
}