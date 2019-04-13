/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_crc.cpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32_hal_crc.hpp"

#if defined( GMOCK_TEST )

STM32_HAL_CRC_Mock* STM32_HAL_CRC_MockObj = nullptr;

HAL_StatusTypeDef HAL_CRC_Init(CRC_HandleTypeDef* hcrc)
{
  return STM32_HAL_CRC_MockObj->HAL_CRC_Init(hcrc);
}

HAL_StatusTypeDef HAL_CRC_DeInit(CRC_HandleTypeDef* hcrc)
{
  return STM32_HAL_CRC_MockObj->HAL_CRC_DeInit(hcrc);
}

void HAL_CRC_MspInit(CRC_HandleTypeDef* hcrc)
{
  STM32_HAL_CRC_MockObj->HAL_CRC_MspInit(hcrc);
}

void HAL_CRC_MspDeInit(CRC_HandleTypeDef* hcrc)
{
  STM32_HAL_CRC_MockObj->HAL_CRC_MspDeInit(hcrc);
}

uint32_t HAL_CRC_Accumulate(CRC_HandleTypeDef* hcrc, uint32_t pBuffer[], uint32_t BufferLength)
{
  return STM32_HAL_CRC_MockObj->HAL_CRC_Accumulate(hcrc, pBuffer, BufferLength);
}

uint32_t HAL_CRC_Calculate(CRC_HandleTypeDef* hcrc, uint32_t pBuffer[], uint32_t BufferLength)
{
  return STM32_HAL_CRC_MockObj->HAL_CRC_Calculate(hcrc, pBuffer, BufferLength);
}

HAL_CRC_StateTypeDef HAL_CRC_GetState(CRC_HandleTypeDef* hcrc)
{
  return STM32_HAL_CRC_MockObj->HAL_CRC_GetState(hcrc);
}

#endif /* GMOCK_TEST */