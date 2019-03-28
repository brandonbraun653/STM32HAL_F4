/********************************************************************************
 *  File Name:
 *    mock_stm32f4_hal_uart.cpp
 *
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32f4xx_hal_uart.hpp"

#if defined( GMOCK_TEST )

STM32F4_HAL_UART_Mock *STM32F4_HAL_UARTMockObj = nullptr;


HAL_StatusTypeDef HAL_UART_Init( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_Init( huart );
}

HAL_StatusTypeDef HAL_HalfDuplex_Init( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_HalfDuplex_Init( huart );
}

HAL_StatusTypeDef HAL_LIN_Init( UART_HandleTypeDef *huart, uint32_t BreakDetectLength )
{
  return STM32F4_HAL_UARTMockObj->HAL_LIN_Init( huart, BreakDetectLength );
}

HAL_StatusTypeDef HAL_MultiProcessor_Init( UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod )
{
  return STM32F4_HAL_UARTMockObj->HAL_MultiProcessor_Init( huart, Address, WakeUpMethod );
}

HAL_StatusTypeDef HAL_UART_DeInit( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_DeInit( huart );
}

void HAL_UART_MspInit( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_MspInit( huart );
}

void HAL_UART_MspDeInit( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_MspDeInit( huart );
}

HAL_StatusTypeDef HAL_UART_Transmit( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_Transmit( huart, pData, Size, Timeout );
}

HAL_StatusTypeDef HAL_UART_Receive( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_Receive( huart, pData, Size, Timeout );
}

HAL_StatusTypeDef HAL_UART_Transmit_IT( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_Transmit_IT( huart, pData, Size );
}

HAL_StatusTypeDef HAL_UART_Receive_IT( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_Receive_IT( huart, pData, Size );
}

HAL_StatusTypeDef HAL_UART_Transmit_DMA( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_Transmit_DMA( huart, pData, Size );
}

HAL_StatusTypeDef HAL_UART_Receive_DMA( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_Receive_DMA( huart, pData, Size );
}

HAL_StatusTypeDef HAL_UART_DMAPause( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_DMAPause( huart );
}

HAL_StatusTypeDef HAL_UART_DMAResume( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_DMAResume( huart );
}

HAL_StatusTypeDef HAL_UART_DMAStop( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_DMAStop( huart );
}

HAL_StatusTypeDef HAL_UART_Abort( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_Abort( huart );
}

HAL_StatusTypeDef HAL_UART_AbortTransmit( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_AbortTransmit( huart );
}

HAL_StatusTypeDef HAL_UART_AbortReceive( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_AbortReceive( huart );
}

HAL_StatusTypeDef HAL_UART_Abort_IT( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_Abort_IT( huart );
}

HAL_StatusTypeDef HAL_UART_AbortTransmit_IT( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_AbortTransmit_IT( huart );
}

HAL_StatusTypeDef HAL_UART_AbortReceive_IT( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_AbortReceive_IT( huart );
}

void HAL_UART_IRQHandler( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_IRQHandler( huart );
}

void HAL_UART_TxCpltCallback( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_TxCpltCallback( huart );
}

void HAL_UART_TxHalfCpltCallback( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_TxHalfCpltCallback( huart );
}

void HAL_UART_RxCpltCallback( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_RxCpltCallback( huart );
}

void HAL_UART_RxHalfCpltCallback( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_RxHalfCpltCallback( huart );
}

void HAL_UART_ErrorCallback( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_ErrorCallback( huart );
}

void HAL_UART_AbortCpltCallback( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_AbortCpltCallback( huart );
}

void HAL_UART_AbortTransmitCpltCallback( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_AbortTransmitCpltCallback( huart );
}

void HAL_UART_AbortReceiveCpltCallback( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_AbortReceiveCpltCallback( huart );
}

HAL_StatusTypeDef HAL_LIN_SendBreak( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_LIN_SendBreak( huart );
}

HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_MultiProcessor_EnterMuteMode( huart );
}

HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_MultiProcessor_ExitMuteMode( huart );
}

HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_HalfDuplex_EnableTransmitter( huart );
}

HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_HalfDuplex_EnableReceiver( huart );
}

HAL_UART_StateTypeDef HAL_UART_GetState( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_GetState( huart );
}

uint32_t HAL_UART_GetError( UART_HandleTypeDef *huart )
{
  return STM32F4_HAL_UARTMockObj->HAL_UART_GetError(huart);
}

#endif /* GMOCK_TEST */
