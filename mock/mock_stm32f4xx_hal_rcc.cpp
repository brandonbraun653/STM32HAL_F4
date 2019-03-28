/********************************************************************************
 *  File Name:
 *    mock_stm32f4xx_hal_rcc.cpp
 *
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32f4xx_hal_rcc.hpp"

#if defined( GMOCK_TEST )

STM32F4_HAL_RCC_Mock *STM32F4_HAL_RCC_MockObj = nullptr;

HAL_StatusTypeDef HAL_RCC_DeInit( void )
{
  return STM32F4_HAL_RCC_MockObj->HAL_RCC_DeInit();
}

HAL_StatusTypeDef HAL_RCC_OscConfig( RCC_OscInitTypeDef *RCC_OscInitStruct )
{
  return STM32F4_HAL_RCC_MockObj->HAL_RCC_OscConfig( RCC_OscInitStruct );
}

HAL_StatusTypeDef HAL_RCC_ClockConfig( RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency )
{
  return STM32F4_HAL_RCC_MockObj->HAL_RCC_ClockConfig( RCC_ClkInitStruct, FLatency );
}

void HAL_RCC_MCOConfig( uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv )
{
  STM32F4_HAL_RCC_MockObj->HAL_RCC_MCOConfig( RCC_MCOx, RCC_MCOSource, RCC_MCODiv );
}

void HAL_RCC_EnableCSS( void )
{
  STM32F4_HAL_RCC_MockObj->HAL_RCC_EnableCSS();
}

void HAL_RCC_DisableCSS( void )
{
  STM32F4_HAL_RCC_MockObj->HAL_RCC_DisableCSS();
}

uint32_t HAL_RCC_GetSysClockFreq( void )
{
  return STM32F4_HAL_RCC_MockObj->HAL_RCC_GetSysClockFreq();
}

uint32_t HAL_RCC_GetHCLKFreq( void )
{
  return STM32F4_HAL_RCC_MockObj->HAL_RCC_GetHCLKFreq();
}

uint32_t HAL_RCC_GetPCLK1Freq( void )
{
  return STM32F4_HAL_RCC_MockObj->HAL_RCC_GetPCLK1Freq();
}

uint32_t HAL_RCC_GetPCLK2Freq( void )
{
  return STM32F4_HAL_RCC_MockObj->HAL_RCC_GetPCLK2Freq();
}

void HAL_RCC_GetOscConfig( RCC_OscInitTypeDef *RCC_OscInitStruct )
{
  STM32F4_HAL_RCC_MockObj->HAL_RCC_GetOscConfig( RCC_OscInitStruct );
}

void HAL_RCC_GetClockConfig( RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t *pFLatency )
{
  STM32F4_HAL_RCC_MockObj->HAL_RCC_GetClockConfig( RCC_ClkInitStruct, pFLatency );
}

void HAL_RCC_NMI_IRQHandler( void )
{
  STM32F4_HAL_RCC_MockObj->HAL_RCC_NMI_IRQHandler();
}

void HAL_RCC_CSSCallback( void )
{
  STM32F4_HAL_RCC_MockObj->HAL_RCC_CSSCallback();
}

#endif /* GMOCK_TEST */
