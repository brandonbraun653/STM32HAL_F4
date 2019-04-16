/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_gpio.cpp
 *
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32_hal_spi.hpp"

#if defined( GMOCK_TEST )
using ::testing::Return;
using ::testing::_;

::testing::NiceMock<STM32_HAL_SPI_Mock>* STM32_HAL_SPI_MockObj = nullptr;

STM32_HAL_SPI_Mock::STM32_HAL_SPI_Mock()
{
  ON_CALL(*this, HAL_SPI_Init(_)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_DeInit(_)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_Transmit(_, _, _, _)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_Receive(_, _, _, _)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_TransmitReceive(_, _, _, _, _)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_Transmit_IT(_, _, _)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_Receive_IT(_, _, _)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_TransmitReceive_IT(_, _, _, _)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_Transmit_DMA(_, _, _)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_Receive_DMA(_, _, _)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_TransmitReceive_DMA(_, _, _, _)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_DMAPause(_)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_DMAResume(_)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_DMAStop(_)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_Abort(_)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_Abort_IT(_)).WillByDefault(Return(HAL_OK));
  ON_CALL(*this, HAL_SPI_GetState(_)).WillByDefault(Return(HAL_SPI_STATE_READY));
  ON_CALL(*this, HAL_SPI_GetError(_)).WillByDefault(Return(0u));
}

HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef* hspi)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_Init(hspi);
}

HAL_StatusTypeDef HAL_SPI_DeInit(SPI_HandleTypeDef* hspi)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_DeInit(hspi);
}

void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_MspInit(hspi);
}

void HAL_SPI_MspDeInit(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_MspDeInit(hspi);
}

HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size, uint32_t Timeout)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_Transmit(hspi, pData, Size, Timeout);
}

HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size, uint32_t Timeout)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_Receive(hspi, pData, Size, Timeout);
}

HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData, uint16_t Size, uint32_t Timeout)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_TransmitReceive(hspi, pTxData, pRxData, Size, Timeout);
}

HAL_StatusTypeDef HAL_SPI_Transmit_IT(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_Transmit_IT(hspi, pData, Size);
}

HAL_StatusTypeDef HAL_SPI_Receive_IT(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_Receive_IT(hspi, pData, Size);
}

HAL_StatusTypeDef HAL_SPI_TransmitReceive_IT(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData, uint16_t Size)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_TransmitReceive_IT(hspi, pTxData, pRxData, Size);
}

HAL_StatusTypeDef HAL_SPI_Transmit_DMA(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_Transmit_DMA(hspi, pData, Size);
}

HAL_StatusTypeDef HAL_SPI_Receive_DMA(SPI_HandleTypeDef* hspi, uint8_t* pData, uint16_t Size)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_Receive_DMA(hspi, pData, Size);
}

HAL_StatusTypeDef HAL_SPI_TransmitReceive_DMA(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData, uint16_t Size)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_TransmitReceive_DMA(hspi, pTxData, pRxData, Size);
}

HAL_StatusTypeDef HAL_SPI_DMAPause(SPI_HandleTypeDef* hspi)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_DMAPause(hspi);
}

HAL_StatusTypeDef HAL_SPI_DMAResume(SPI_HandleTypeDef* hspi)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_DMAResume(hspi);
}

HAL_StatusTypeDef HAL_SPI_DMAStop(SPI_HandleTypeDef* hspi)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_DMAStop(hspi);
}

HAL_StatusTypeDef HAL_SPI_Abort(SPI_HandleTypeDef* hspi)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_Abort(hspi);
}

HAL_StatusTypeDef HAL_SPI_Abort_IT(SPI_HandleTypeDef* hspi)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_Abort_IT(hspi);
}

void HAL_SPI_IRQHandler(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_IRQHandler(hspi);
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_TxCpltCallback(hspi);
}

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_RxCpltCallback(hspi);
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_TxRxCpltCallback(hspi);
}

void HAL_SPI_TxHalfCpltCallback(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_TxHalfCpltCallback(hspi);
}

void HAL_SPI_RxHalfCpltCallback(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_RxHalfCpltCallback(hspi);
}

void HAL_SPI_TxRxHalfCpltCallback(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_TxRxHalfCpltCallback(hspi);
}

void HAL_SPI_ErrorCallback(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_ErrorCallback(hspi);
}

void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef* hspi)
{
  STM32_HAL_SPI_MockObj->HAL_SPI_AbortCpltCallback(hspi);
}

HAL_SPI_StateTypeDef HAL_SPI_GetState(SPI_HandleTypeDef* hspi)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_GetState(hspi);
}

uint32_t HAL_SPI_GetError(SPI_HandleTypeDef* hspi)
{
  return STM32_HAL_SPI_MockObj->HAL_SPI_GetError(hspi);
}

#endif /* GMOCK_TEST */
