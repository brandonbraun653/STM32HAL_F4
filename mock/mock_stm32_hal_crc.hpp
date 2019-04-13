/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_crc.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef mock_stm32_hal_CRC_HPP
#define mock_stm32_hal_CRC_HPP

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

#include "stm32f4xx_hal_crc.h"

#ifdef __cplusplus
}
#endif

class STM32_HAL_CRC_Interface
{
public:
  virtual ~STM32_HAL_CRC_Interface() = default;
  
  virtual HAL_StatusTypeDef HAL_CRC_Init(CRC_HandleTypeDef* hcrc);
  virtual HAL_StatusTypeDef HAL_CRC_DeInit(CRC_HandleTypeDef* hcrc);
  virtual void HAL_CRC_MspInit(CRC_HandleTypeDef* hcrc);
  virtual void HAL_CRC_MspDeInit(CRC_HandleTypeDef* hcrc);
  virtual uint32_t HAL_CRC_Accumulate(CRC_HandleTypeDef* hcrc, uint32_t pBuffer[], uint32_t BufferLength);
  virtual uint32_t HAL_CRC_Calculate(CRC_HandleTypeDef* hcrc, uint32_t pBuffer[], uint32_t BufferLength);
  virtual HAL_CRC_StateTypeDef HAL_CRC_GetState(CRC_HandleTypeDef* hcrc);
  
};

class STM32_HAL_CRC_Mock : public STM32_HAL_CRC_Interface
{
public:
  virtual ~STM32_HAL_CRC_Mock() = default;

  MOCK_METHOD1(HAL_CRC_Init, HAL_StatusTypeDef(CRC_HandleTypeDef* hcrc));
  MOCK_METHOD1(HAL_CRC_DeInit, HAL_StatusTypeDef(CRC_HandleTypeDef* hcrc));
  MOCK_METHOD1(HAL_CRC_MspInit, void(CRC_HandleTypeDef* hcrc));
  MOCK_METHOD1(HAL_CRC_MspDeInit, void(CRC_HandleTypeDef* hcrc));
  MOCK_METHOD3(HAL_CRC_Accumulate, uint32_t(CRC_HandleTypeDef* hcrc, uint32_t pBuffer[], uint32_t BufferLength));
  MOCK_METHOD3(HAL_CRC_Calculate, uint32_t(CRC_HandleTypeDef* hcrc, uint32_t pBuffer[], uint32_t BufferLength));
  MOCK_METHOD1(HAL_CRC_GetState, HAL_CRC_StateTypeDef(CRC_HandleTypeDef* hcrc));
};

extern STM32_HAL_CRC_Mock* STM32_HAL_CRC_MockObj;

#endif /* GMOCK_TEST */

#endif /* !mock_stm32_hal_CRC_HPP */