/********************************************************************************
 *  File Name:
 *    mock_stm32f4xx_hal_iwdg.cpp
 *
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32f4xx_hal_iwdg.hpp"

#if defined( GMOCK_TEST )

STM32F4_HAL_IWDG_Mock *STM32F4_HAL_IWDG_MockObj = nullptr;

HAL_StatusTypeDef HAL_IWDG_Init( IWDG_HandleTypeDef *hiwdg )
{
  return STM32F4_HAL_IWDG_MockObj->HAL_IWDG_Init( hiwdg );
}

HAL_StatusTypeDef HAL_IWDG_Refresh( IWDG_HandleTypeDef *hiwdg )
{
  return STM32F4_HAL_IWDG_MockObj->HAL_IWDG_Refresh( hiwdg );
}

#endif /* GMOCK_TEST */
