/********************************************************************************
 *  File Name:
 *    mock_stm32f4xx_hal_gpio.cpp
 *
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32f4xx_hal_gpio.hpp"

#if defined( GMOCK_TEST )

STM32F4_HAL_GPIO_Mock *STM32F4_HAL_GPIO_MockObj = nullptr;

void HAL_GPIO_Init( GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init )
{
  STM32F4_HAL_GPIO_MockObj->HAL_GPIO_Init( GPIOx, GPIO_Init );
}

void HAL_GPIO_DeInit( GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin )
{
  STM32F4_HAL_GPIO_MockObj->HAL_GPIO_DeInit( GPIOx, GPIO_Pin );
}

GPIO_PinState HAL_GPIO_ReadPin( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin )
{
  return STM32F4_HAL_GPIO_MockObj->HAL_GPIO_ReadPin( GPIOx, GPIO_Pin );
}

void HAL_GPIO_WritePin( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState )
{
  STM32F4_HAL_GPIO_MockObj->HAL_GPIO_WritePin( GPIOx, GPIO_Pin, PinState );
}

void HAL_GPIO_TogglePin( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin )
{
  STM32F4_HAL_GPIO_MockObj->HAL_GPIO_TogglePin( GPIOx, GPIO_Pin );
}

HAL_StatusTypeDef HAL_GPIO_LockPin( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin )
{
  return STM32F4_HAL_GPIO_MockObj->HAL_GPIO_LockPin( GPIOx, GPIO_Pin );
}

void HAL_GPIO_EXTI_IRQHandler( uint16_t GPIO_Pin )
{
  STM32F4_HAL_GPIO_MockObj->HAL_GPIO_EXTI_IRQHandler( GPIO_Pin );
}

void HAL_GPIO_EXTI_Callback( uint16_t GPIO_Pin )
{
  STM32F4_HAL_GPIO_MockObj->HAL_GPIO_EXTI_Callback( GPIO_Pin );
}

#endif /* GMOCK_TEST */
