/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_rcc.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef mock_stm32_hal_RCC_HPP
#define mock_stm32_hal_RCC_HPP

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

#include "stm32f4xx_hal_rcc.h"

#ifdef __cplusplus
}
#endif

class STM32_HAL_RCC_Interface
{
public:
  virtual ~STM32_HAL_RCC_Interface() = default;

  virtual HAL_StatusTypeDef HAL_RCC_DeInit( void );
  virtual HAL_StatusTypeDef HAL_RCC_OscConfig( RCC_OscInitTypeDef *RCC_OscInitStruct );
  virtual HAL_StatusTypeDef HAL_RCC_ClockConfig( RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency );
  virtual void HAL_RCC_MCOConfig( uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv );
  virtual void HAL_RCC_EnableCSS( void );
  virtual void HAL_RCC_DisableCSS( void );
  virtual uint32_t HAL_RCC_GetSysClockFreq( void );
  virtual uint32_t HAL_RCC_GetHCLKFreq( void );
  virtual uint32_t HAL_RCC_GetPCLK1Freq( void );
  virtual uint32_t HAL_RCC_GetPCLK2Freq( void );
  virtual void HAL_RCC_GetOscConfig( RCC_OscInitTypeDef *RCC_OscInitStruct );
  virtual void HAL_RCC_GetClockConfig( RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t *pFLatency );
  virtual void HAL_RCC_NMI_IRQHandler( void );
  virtual void HAL_RCC_CSSCallback( void );
};

class STM32_HAL_RCC_Mock : public STM32_HAL_RCC_Interface
{
public:
  virtual ~STM32_HAL_RCC_Mock() = default;

  MOCK_METHOD0(HAL_RCC_DeInit, HAL_StatusTypeDef( void ));
  MOCK_METHOD1(HAL_RCC_OscConfig, HAL_StatusTypeDef( RCC_OscInitTypeDef *RCC_OscInitStruct ));
  MOCK_METHOD2(HAL_RCC_ClockConfig, HAL_StatusTypeDef( RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency ));
  MOCK_METHOD3(HAL_RCC_MCOConfig, void( uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv ));
  MOCK_METHOD0(HAL_RCC_EnableCSS, void( void ));
  MOCK_METHOD0(HAL_RCC_DisableCSS, void( void ));
  MOCK_METHOD0(HAL_RCC_GetSysClockFreq, uint32_t( void ));
  MOCK_METHOD0(HAL_RCC_GetHCLKFreq, uint32_t( void ));
  MOCK_METHOD0(HAL_RCC_GetPCLK1Freq, uint32_t( void ));
  MOCK_METHOD0(HAL_RCC_GetPCLK2Freq, uint32_t( void ));
  MOCK_METHOD1(HAL_RCC_GetOscConfig, void( RCC_OscInitTypeDef *RCC_OscInitStruct ));
  MOCK_METHOD2(HAL_RCC_GetClockConfig, void( RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t *pFLatency ));
  MOCK_METHOD0(HAL_RCC_NMI_IRQHandler, void( void ));
  MOCK_METHOD0(HAL_RCC_CSSCallback, void( void ));
};

extern STM32_HAL_RCC_Mock *STM32_HAL_RCC_MockObj;

#endif /* GMOCK_TEST */

#endif /* !mock_stm32_hal_RCC_HPP */
