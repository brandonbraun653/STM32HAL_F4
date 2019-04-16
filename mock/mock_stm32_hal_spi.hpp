/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_spi.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32_HAL_SPI_HPP
#define MOCK_STM32_HAL_SPI_HPP

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
#include "stm32f4xx_hal_spi.h"

#ifdef __cplusplus
}
#endif

class STM32_HAL_SPI_Interface
{
public:
  virtual ~STM32_HAL_SPI_Interface() = default;
  virtual HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef* hspi) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_DeInit(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_MspDeInit(SPI_HandleTypeDef* hspi) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size, uint32_t Timeout) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size, uint32_t Timeout) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData, uint16_t Size, uint32_t Timeout) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_Transmit_IT(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_Receive_IT(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_TransmitReceive_IT(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData, uint16_t Size) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_Transmit_DMA(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_Receive_DMA(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_TransmitReceive_DMA(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData, uint16_t Size) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_DMAPause(SPI_HandleTypeDef* hspi) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_DMAResume(SPI_HandleTypeDef* hspi) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_DMAStop(SPI_HandleTypeDef* hspi) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_Abort(SPI_HandleTypeDef* hspi) = 0;
  virtual HAL_StatusTypeDef HAL_SPI_Abort_IT(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_IRQHandler(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_TxHalfCpltCallback(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_RxHalfCpltCallback(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_TxRxHalfCpltCallback(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_ErrorCallback(SPI_HandleTypeDef* hspi) = 0;
  virtual void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef* hspi) = 0;
  virtual HAL_SPI_StateTypeDef HAL_SPI_GetState(SPI_HandleTypeDef* hspi) = 0;
  virtual uint32_t             HAL_SPI_GetError(SPI_HandleTypeDef* hspi) = 0;
};

class STM32_HAL_SPI_Mock : public STM32_HAL_SPI_Interface
{
public:
  STM32_HAL_SPI_Mock();
  virtual ~STM32_HAL_SPI_Mock() = default;

  MOCK_METHOD1(HAL_SPI_Init, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_DeInit, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi));
  MOCK_METHOD4(HAL_SPI_Transmit, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size, uint32_t Timeout));
  MOCK_METHOD4(HAL_SPI_Receive, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size, uint32_t Timeout));
  MOCK_METHOD5(HAL_SPI_TransmitReceive, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData, uint16_t Size, uint32_t Timeout));
  MOCK_METHOD3(HAL_SPI_Transmit_IT, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size));
  MOCK_METHOD3(HAL_SPI_Receive_IT, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size));
  MOCK_METHOD4(HAL_SPI_TransmitReceive_IT, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData, uint16_t Size));
  MOCK_METHOD3(HAL_SPI_Transmit_DMA, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size));
  MOCK_METHOD3(HAL_SPI_Receive_DMA, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size));
  MOCK_METHOD4(HAL_SPI_TransmitReceive_DMA, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData, uint16_t Size));
  MOCK_METHOD1(HAL_SPI_DMAPause, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_DMAResume, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_DMAStop, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_Abort, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_Abort_IT, HAL_StatusTypeDef(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_GetState, HAL_SPI_StateTypeDef(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_IRQHandler, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_TxCpltCallback, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_RxCpltCallback, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_TxRxCpltCallback, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_TxHalfCpltCallback, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_RxHalfCpltCallback, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_TxRxHalfCpltCallback, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_ErrorCallback, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_AbortCpltCallback, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_MspInit, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_MspDeInit, void(SPI_HandleTypeDef* hspi));
  MOCK_METHOD1(HAL_SPI_GetError, uint32_t(SPI_HandleTypeDef* hspi));
};

extern ::testing::NiceMock<STM32_HAL_SPI_Mock>* STM32_HAL_SPI_MockObj;

#endif /* GMOCK_TEST */

#endif /* !MOCK_STM32_HAL_SPI_HPP */
