/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_uart.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32_HAL_UART_HPP
#define MOCK_STM32_HAL_UART_HPP

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
#include "stm32f4xx_hal_uart.h"

#ifdef __cplusplus
}
#endif

class STM32_HAL_UART_Interface
{
public:
  virtual ~STM32_HAL_UART_Interface() = default;

  virtual HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef* huart, uint32_t BreakDetectLength) = 0;
  virtual HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef* huart, uint8_t Address, uint32_t WakeUpMethod) = 0;
  virtual HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_MspInit(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_MspDeInit(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef* huart, uint8_t* pData, uint16_t Size, uint32_t Timeout) = 0;
  virtual HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef* huart, uint8_t* pData, uint16_t Size, uint32_t Timeout) = 0;
  virtual HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef* huart, uint8_t* pData, uint16_t Size) = 0;
  virtual HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef* huart, uint8_t* pData, uint16_t Size) = 0;
  virtual HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef* huart, uint8_t* pData, uint16_t Size) = 0;
  virtual HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef* huart, uint8_t* pData, uint16_t Size) = 0;
  virtual HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_IRQHandler(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_TxCpltCallback(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_ErrorCallback(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_AbortCpltCallback(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef* huart) = 0;
  virtual void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef* huart) = 0;
  virtual HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef* huart) = 0;
  virtual HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef* huart) = 0;
  virtual uint32_t HAL_UART_GetError(UART_HandleTypeDef* huart) = 0;
};

class STM32_HAL_UART_Mock : public STM32_HAL_UART_Interface
{
public:
  virtual ~STM32_HAL_UART_Mock() = default;

  MOCK_METHOD1( HAL_UART_Init, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_HalfDuplex_Init, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD2( HAL_LIN_Init, HAL_StatusTypeDef( UART_HandleTypeDef *huart, uint32_t BreakDetectLength ) );
  MOCK_METHOD3( HAL_MultiProcessor_Init,
                HAL_StatusTypeDef( UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod ) );
  MOCK_METHOD1( HAL_UART_DeInit, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_MspInit, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_MspDeInit, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD4( HAL_UART_Transmit,
                HAL_StatusTypeDef( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
  MOCK_METHOD4( HAL_UART_Receive,
                HAL_StatusTypeDef( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
  MOCK_METHOD3( HAL_UART_Transmit_IT, HAL_StatusTypeDef( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size ) );
  MOCK_METHOD3( HAL_UART_Receive_IT, HAL_StatusTypeDef( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size ) );
  MOCK_METHOD3( HAL_UART_Transmit_DMA, HAL_StatusTypeDef( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size ) );
  MOCK_METHOD3( HAL_UART_Receive_DMA, HAL_StatusTypeDef( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size ) );
  MOCK_METHOD1( HAL_UART_DMAPause, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_DMAResume, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_DMAStop, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_Abort, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_AbortTransmit, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_AbortReceive, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_Abort_IT, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_AbortTransmit_IT, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_AbortReceive_IT, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_IRQHandler, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_TxCpltCallback, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_TxHalfCpltCallback, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_RxCpltCallback, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_RxHalfCpltCallback, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_ErrorCallback, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_AbortCpltCallback, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_AbortTransmitCpltCallback, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_AbortReceiveCpltCallback, void( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_LIN_SendBreak, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_MultiProcessor_EnterMuteMode, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_MultiProcessor_ExitMuteMode, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_HalfDuplex_EnableTransmitter, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_HalfDuplex_EnableReceiver, HAL_StatusTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_GetState, HAL_UART_StateTypeDef( UART_HandleTypeDef *huart ) );
  MOCK_METHOD1( HAL_UART_GetError, uint32_t( UART_HandleTypeDef *huart ) );
};

extern ::testing::NiceMock<STM32_HAL_UART_Mock>* STM32_HAL_UART_MockObj;

#endif /* GMOCK_TEST */

#endif /* !mock_stm32_hal_UART_HPP */
