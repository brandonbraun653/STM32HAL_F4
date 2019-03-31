/********************************************************************************
 *  File Name:
 *    mock_stm32f4xx_hal_usart.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32F4xx_HAL_USART_HPP
#define MOCK_STM32F4xx_HAL_USART_HPP

/* C++ Includes */
#include <cstdint>
#include <cstdlib>

/* Mock Includes */
#if defined( GMOCK_TEST )
#include <gmock/gmock.h>

/* STM32 Includes */
#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_usart.h"

#ifdef __cplusplus
}
#endif

class STM32F4_HAL_USART_Interface
{
public:
  virtual ~STM32F4_HAL_USART_Interface() = default;

  virtual HAL_StatusTypeDef HAL_USART_Init( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_HalfDuplex_Init( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_LIN_Init( USART_HandleTypeDef *huart, uint32_t BreakDetectLength );
  virtual HAL_StatusTypeDef HAL_MultiProcessor_Init( USART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod );
  virtual HAL_StatusTypeDef HAL_USART_DeInit( USART_HandleTypeDef *huart );
  virtual void HAL_USART_MspInit( USART_HandleTypeDef *huart );
  virtual void HAL_USART_MspDeInit( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_USART_Transmit( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout );
  virtual HAL_StatusTypeDef HAL_USART_Receive( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout );
  virtual HAL_StatusTypeDef HAL_USART_Transmit_IT( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size );
  virtual HAL_StatusTypeDef HAL_USART_Receive_IT( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size );
  virtual HAL_StatusTypeDef HAL_USART_Transmit_DMA( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size );
  virtual HAL_StatusTypeDef HAL_USART_Receive_DMA( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size );
  virtual HAL_StatusTypeDef HAL_USART_DMAPause( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_USART_DMAResume( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_USART_DMAStop( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_USART_Abort( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_USART_AbortTransmit( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_USART_AbortReceive( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_USART_Abort_IT( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_USART_AbortTransmit_IT( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_USART_AbortReceive_IT( USART_HandleTypeDef *huart );
  virtual void HAL_USART_IRQHandler( USART_HandleTypeDef *huart );
  virtual void HAL_USART_TxCpltCallback( USART_HandleTypeDef *huart );
  virtual void HAL_USART_TxHalfCpltCallback( USART_HandleTypeDef *huart );
  virtual void HAL_USART_RxCpltCallback( USART_HandleTypeDef *huart );
  virtual void HAL_USART_RxHalfCpltCallback( USART_HandleTypeDef *huart );
  virtual void HAL_USART_ErrorCallback( USART_HandleTypeDef *huart );
  virtual void HAL_USART_AbortCpltCallback( USART_HandleTypeDef *huart );
  virtual void HAL_USART_AbortTransmitCpltCallback( USART_HandleTypeDef *huart );
  virtual void HAL_USART_AbortReceiveCpltCallback( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_LIN_SendBreak( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter( USART_HandleTypeDef *huart );
  virtual HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver( USART_HandleTypeDef *huart );
  virtual HAL_USART_StateTypeDef HAL_USART_GetState( USART_HandleTypeDef *huart );
  virtual uint32_t HAL_USART_GetError( USART_HandleTypeDef *huart );
};

class STM32F4_HAL_USART_Mock : public STM32F4_HAL_USART_Interface
{
public:
  virtual ~STM32F4_HAL_USART_Mock() = default;

  MOCK_METHOD1( HAL_USART_Init, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_HalfDuplex_Init, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD2( HAL_LIN_Init, HAL_StatusTypeDef( USART_HandleTypeDef *huart, uint32_t BreakDetectLength ) );
  MOCK_METHOD3( HAL_MultiProcessor_Init,
                HAL_StatusTypeDef( USART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod ) );
  MOCK_METHOD1( HAL_USART_DeInit, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_MspInit, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_MspDeInit, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD4( HAL_USART_Transmit,
                HAL_StatusTypeDef( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
  MOCK_METHOD4( HAL_USART_Receive,
                HAL_StatusTypeDef( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
  MOCK_METHOD3( HAL_USART_Transmit_IT, HAL_StatusTypeDef( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size ) );
  MOCK_METHOD3( HAL_USART_Receive_IT, HAL_StatusTypeDef( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size ) );
  MOCK_METHOD3( HAL_USART_Transmit_DMA, HAL_StatusTypeDef( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size ) );
  MOCK_METHOD3( HAL_USART_Receive_DMA, HAL_StatusTypeDef( USART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size ) );
  MOCK_METHOD1( HAL_USART_DMAPause, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_DMAResume, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_DMAStop, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_Abort, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_AbortTransmit, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_AbortReceive, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_Abort_IT, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_AbortTransmit_IT, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_AbortReceive_IT, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_IRQHandler, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_TxCpltCallback, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_TxHalfCpltCallback, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_RxCpltCallback, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_RxHalfCpltCallback, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_ErrorCallback, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_AbortCpltCallback, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_AbortTransmitCpltCallback, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_AbortReceiveCpltCallback, void( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_LIN_SendBreak, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_MultiProcessor_EnterMuteMode, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_MultiProcessor_ExitMuteMode, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_HalfDuplex_EnableTransmitter, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_HalfDuplex_EnableReceiver, HAL_StatusTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_GetState, HAL_USART_StateTypeDef( USART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_USART_GetError, uint32_t( USART_HandleTypeDef *huart ) );
};

extern STM32F4_HAL_USART_Mock *STM32F4_HAL_USARTMockObj;

#endif /* GMOCK_TEST */

#endif /* !MOCK_STM32F4xx_HAL_UART_HPP */
