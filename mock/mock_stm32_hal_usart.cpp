/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_usart.cpp
 *
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32_hal_usart.hpp"

#if defined( GMOCK_TEST )

namespace STM32HAL_Mock
{
  USARTNiceMock_sPtr usartMockObj = nullptr;
}

HAL_StatusTypeDef HAL_USART_Init( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_Init( huart );
}

HAL_StatusTypeDef HAL_HalfDuplex_Init( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_HalfDuplex_Init( huart );
}

HAL_StatusTypeDef HAL_LIN_Init( USART_HandleTypeDef *huart, uint32_t BreakDetectLength )
{
  return STM32HAL_Mock::usartMockObj->HAL_LIN_Init( huart, BreakDetectLength );
}

HAL_StatusTypeDef HAL_MultiProcessor_Init( USART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod )
{
  return STM32HAL_Mock::usartMockObj->HAL_MultiProcessor_Init( huart, Address, WakeUpMethod );
}

HAL_StatusTypeDef HAL_USART_DeInit( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_DeInit( huart );
}

void HAL_USART_MspInit( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_MspInit( huart );
}

void HAL_USART_MspDeInit( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_MspDeInit( huart );
}

HAL_StatusTypeDef HAL_USART_Transmit( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_Transmit( huart, pData, Size, Timeout );
}

HAL_StatusTypeDef HAL_USART_Receive( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_Receive( huart, pData, Size, Timeout );
}

HAL_StatusTypeDef HAL_USART_Transmit_IT( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_Transmit_IT( huart, pData, Size );
}

HAL_StatusTypeDef HAL_USART_Receive_IT( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_Receive_IT( huart, pData, Size );
}

HAL_StatusTypeDef HAL_USART_Transmit_DMA( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_Transmit_DMA( huart, pData, Size );
}

HAL_StatusTypeDef HAL_USART_Receive_DMA( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_Receive_DMA( huart, pData, Size );
}

HAL_StatusTypeDef HAL_USART_DMAPause( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_DMAPause( huart );
}

HAL_StatusTypeDef HAL_USART_DMAResume( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_DMAResume( huart );
}

HAL_StatusTypeDef HAL_USART_DMAStop( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_DMAStop( huart );
}

HAL_StatusTypeDef HAL_USART_Abort( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_Abort( huart );
}

HAL_StatusTypeDef HAL_USART_AbortTransmit( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_AbortTransmit( huart );
}

HAL_StatusTypeDef HAL_USART_AbortReceive( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_AbortReceive( huart );
}

HAL_StatusTypeDef HAL_USART_Abort_IT( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_Abort_IT( huart );
}

HAL_StatusTypeDef HAL_USART_AbortTransmit_IT( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_AbortTransmit_IT( huart );
}

HAL_StatusTypeDef HAL_USART_AbortReceive_IT( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_AbortReceive_IT( huart );
}

void HAL_USART_IRQHandler( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_IRQHandler( huart );
}

void HAL_USART_TxCpltCallback( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_TxCpltCallback( huart );
}

void HAL_USART_TxHalfCpltCallback( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_TxHalfCpltCallback( huart );
}

void HAL_USART_RxCpltCallback( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_RxCpltCallback( huart );
}

void HAL_USART_RxHalfCpltCallback( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_RxHalfCpltCallback( huart );
}

void HAL_USART_ErrorCallback( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_ErrorCallback( huart );
}

void HAL_USART_AbortCpltCallback( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_AbortCpltCallback( huart );
}

void HAL_USART_AbortTransmitCpltCallback( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_AbortTransmitCpltCallback( huart );
}

void HAL_USART_AbortReceiveCpltCallback( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_AbortReceiveCpltCallback( huart );
}

HAL_StatusTypeDef HAL_LIN_SendBreak( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_LIN_SendBreak( huart );
}

HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_MultiProcessor_EnterMuteMode( huart );
}

HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_MultiProcessor_ExitMuteMode( huart );
}

HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_HalfDuplex_EnableTransmitter( huart );
}

HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_HalfDuplex_EnableReceiver( huart );
}

HAL_USART_StateTypeDef HAL_USART_GetState( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_GetState( huart );
}

uint32_t HAL_USART_GetError( USART_HandleTypeDef *huart )
{
  return STM32HAL_Mock::usartMockObj->HAL_USART_GetError(huart);
}

#endif /* GMOCK_TEST */
