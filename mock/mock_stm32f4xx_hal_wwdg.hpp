/********************************************************************************
 *  File Name:
 *    mock_stm32f4xx_hal_wwdg.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32F4xx_HAL_WWDG_HPP
#define MOCK_STM32F4xx_HAL_WWDG_HPP

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

#include "stm32f4xx_hal_wwdg.h"

#ifdef __cplusplus
}
#endif

class STM32F4_HAL_WWDG_Interface
{
public:
  virtual ~STM32F4_HAL_WWDG_Interface() = default;

  virtual HAL_StatusTypeDef HAL_WWDG_Init( WWDG_HandleTypeDef *hwwdg );
  virtual void HAL_WWDG_MspInit( WWDG_HandleTypeDef *hwwdg );
  virtual HAL_StatusTypeDef HAL_WWDG_Refresh( WWDG_HandleTypeDef *hwwdg );
  virtual void HAL_WWDG_IRQHandler( WWDG_HandleTypeDef *hwwdg );
  virtual void HAL_WWDG_EarlyWakeupCallback( WWDG_HandleTypeDef *hwwdg );
};

class STM32F4_HAL_WWDG_Mock : public STM32F4_HAL_WWDG_Interface
{
public:
  virtual ~STM32F4_HAL_WWDG_Mock() = default;

  MOCK_METHOD1( HAL_WWDG_Init, HAL_StatusTypeDef( WWDG_HandleTypeDef *hwwdg ) );
  MOCK_METHOD1( HAL_WWDG_MspInit, void( WWDG_HandleTypeDef *hwwdg ) );
  MOCK_METHOD1( HAL_WWDG_Refresh, HAL_StatusTypeDef( WWDG_HandleTypeDef *hwwdg ) );
  MOCK_METHOD1( HAL_WWDG_IRQHandler, void( WWDG_HandleTypeDef *hwwdg ) );
  MOCK_METHOD1( HAL_WWDG_EarlyWakeupCallback, void( WWDG_HandleTypeDef *hwwdg ) );
};

extern STM32F4_HAL_WWDG_Mock *STM32F4_HAL_IWDG_MockObj;

#endif /* GMOCK_TEST */

#endif /* !MOCK_STM32F4xx_HAL_WWDG_HPP */
