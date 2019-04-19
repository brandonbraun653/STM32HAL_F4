/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_gpio.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32_HAL_GPIO_HPP
#define MOCK_STM32_HAL_GPIO_HPP

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

#include "stm32f4xx_hal_gpio.h"

#ifdef __cplusplus
}
#endif

namespace STM32HAL_Mock
{
	class GPIOInterface
	{
	public:
	  virtual ~GPIOInterface() = default;
	
	  virtual void HAL_GPIO_Init( GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init ) = 0;
	  virtual void HAL_GPIO_DeInit( GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin ) = 0;
	  virtual GPIO_PinState HAL_GPIO_ReadPin( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin ) = 0;
	  virtual void HAL_GPIO_WritePin( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState ) = 0;
	  virtual void HAL_GPIO_TogglePin( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin ) = 0;
	  virtual HAL_StatusTypeDef HAL_GPIO_LockPin( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin ) = 0;
	  virtual void HAL_GPIO_EXTI_IRQHandler( uint16_t GPIO_Pin ) = 0;
	  virtual void HAL_GPIO_EXTI_Callback( uint16_t GPIO_Pin ) = 0;
	};
	
	class GPIOMock : public GPIOInterface
	{
	public:
	  GPIOMock();
	  virtual ~GPIOMock() = default;
	
	  MOCK_METHOD2( HAL_GPIO_Init, void( GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init ));
	  MOCK_METHOD2( HAL_GPIO_DeInit, void( GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin ));
	  MOCK_METHOD2( HAL_GPIO_ReadPin, GPIO_PinState( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin ));
	  MOCK_METHOD3( HAL_GPIO_WritePin, void( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState ));
	  MOCK_METHOD2( HAL_GPIO_TogglePin, void( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin ));
	  MOCK_METHOD2( HAL_GPIO_LockPin, HAL_StatusTypeDef( GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin ));
	  MOCK_METHOD1( HAL_GPIO_EXTI_IRQHandler, void( uint16_t GPIO_Pin ));
	  MOCK_METHOD1( HAL_GPIO_EXTI_Callback, void( uint16_t GPIO_Pin ));
	};
	
  using GPIONiceMock = ::testing::NiceMock<GPIOMock>;
  using GPIONiceMock_sPtr = std::shared_ptr<GPIONiceMock>;

	extern GPIONiceMock_sPtr gpioMockObj;
}

#endif /* GMOCK_TEST */

#endif /* !mock_stm32_hal_GPIO_HPP */
