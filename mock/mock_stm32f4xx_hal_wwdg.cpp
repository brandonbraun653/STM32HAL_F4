/********************************************************************************
 *  File Name:
 *    mock_stm32f4xx_hal_wwdg.cpp
 *
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32f4xx_hal_wwdg.hpp"

#if defined( GMOCK_TEST )

STM32F4_HAL_WWDG_Mock *STM32F4_HAL_WWDG_MockObj = nullptr;

HAL_StatusTypeDef HAL_WWDG_Init( WWDG_HandleTypeDef *hwwdg )
 {
  return STM32F4_HAL_WWDG_MockObj->HAL_WWDG_Init( hwwdg );
}

void HAL_WWDG_MspInit( WWDG_HandleTypeDef *hwwdg )
{
  STM32F4_HAL_WWDG_MockObj->HAL_WWDG_MspInit( hwwdg );
}

HAL_StatusTypeDef HAL_WWDG_Refresh( WWDG_HandleTypeDef *hwwdg )
{
  return STM32F4_HAL_WWDG_MockObj->HAL_WWDG_Refresh( hwwdg );
}

void HAL_WWDG_IRQHandler( WWDG_HandleTypeDef *hwwdg )
{
  STM32F4_HAL_WWDG_MockObj->HAL_WWDG_IRQHandler( hwwdg );
}

void HAL_WWDG_EarlyWakeupCallback( WWDG_HandleTypeDef *hwwdg )
{
  STM32F4_HAL_WWDG_MockObj->HAL_WWDG_EarlyWakeupCallback( hwwdg );
}

#endif /* GMOCK_TEST */
