/********************************************************************************
 *  File Name:
 *    mock_stm32f4xx_hal_iwdg.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32F4xx_HAL_IWDG_HPP
#define MOCK_STM32F4xx_HAL_IWDG_HPP

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

#include "stm32f4xx_hal_iwdg.h"

#ifdef __cplusplus
}
#endif

class STM32F4_HAL_IWDG_Interface
{
public:
  virtual ~STM32F4_HAL_IWDG_Interface() = default;

  virtual HAL_StatusTypeDef HAL_IWDG_Init( IWDG_HandleTypeDef *hiwdg );
  virtual HAL_StatusTypeDef HAL_IWDG_Refresh( IWDG_HandleTypeDef *hiwdg );
};

class STM32F4_HAL_IWDG_Mock : public STM32F4_HAL_IWDG_Interface
{
public:
  virtual ~STM32F4_HAL_IWDG_Mock() = default;

  MOCK_METHOD1( HAL_IWDG_Init, HAL_StatusTypeDef( IWDG_HandleTypeDef *hiwdg ) );
  MOCK_METHOD1( HAL_IWDG_Refresh, HAL_StatusTypeDef( IWDG_HandleTypeDef *hiwdg ) );
};

extern STM32F4_HAL_IWDG_Mock *STM32F4_HAL_IWDG_MockObj;

#endif /* GMOCK_TEST */

#endif /* !MOCK_STM32F4xx_HAL_IWDG_HPP */
