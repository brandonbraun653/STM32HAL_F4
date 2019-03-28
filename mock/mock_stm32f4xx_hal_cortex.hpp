/********************************************************************************
 *  File Name:
 *    mock_stm32f4xx_hal_cortex.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32F4xx_HAL_CORTEX_HPP
#define MOCK_STM32F4xx_HAL_CORTEX_HPP

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

#include "stm32f4xx_hal_cortex.h"

#ifdef __cplusplus
}
#endif

class STM32F4_HAL_CORTEX_Interface
{
public:
  virtual ~STM32F4_HAL_CORTEX_Interface() = default;

  virtual void HAL_NVIC_SetPriorityGrouping( uint32_t PriorityGroup );
  virtual void HAL_NVIC_SetPriority( IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority );
  virtual void HAL_NVIC_EnableIRQ( IRQn_Type IRQn );
  virtual void HAL_NVIC_DisableIRQ( IRQn_Type IRQn );
  virtual void HAL_NVIC_SystemReset( void );
  virtual uint32_t HAL_SYSTICK_Config( uint32_t TicksNumb );
  virtual uint32_t HAL_NVIC_GetPriorityGrouping( void );
  virtual void HAL_NVIC_GetPriority( IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t *pPreemptPriority, uint32_t *pSubPriority );
  virtual uint32_t HAL_NVIC_GetPendingIRQ( IRQn_Type IRQn );
  virtual void HAL_NVIC_SetPendingIRQ( IRQn_Type IRQn );
  virtual void HAL_NVIC_ClearPendingIRQ( IRQn_Type IRQn );
  virtual uint32_t HAL_NVIC_GetActive( IRQn_Type IRQn );
  virtual void HAL_SYSTICK_CLKSourceConfig( uint32_t CLKSource );
  virtual void HAL_SYSTICK_IRQHandler( void );
  virtual void HAL_SYSTICK_Callback( void );
  virtual void HAL_MPU_Enable( uint32_t MPU_Control );
  virtual void HAL_MPU_Disable( void );
  virtual void HAL_MPU_ConfigRegion( MPU_Region_InitTypeDef *MPU_Init );
};

class STM32F4_HAL_CORTEX_Mock : public STM32F4_HAL_CORTEX_Interface
{
public:
  virtual ~STM32F4_HAL_CORTEX_Mock() = default;

  MOCK_METHOD1( HAL_NVIC_SetPriorityGrouping, void( uint32_t PriorityGroup ) );
  MOCK_METHOD3( HAL_NVIC_SetPriority, void( IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority ) );
  MOCK_METHOD1( HAL_NVIC_EnableIRQ, void( IRQn_Type IRQn ) );
  MOCK_METHOD1( HAL_NVIC_DisableIRQ, void( IRQn_Type IRQn ) );
  MOCK_METHOD0( HAL_NVIC_SystemReset, void( void ) );
  MOCK_METHOD1( HAL_SYSTICK_Config, uint32_t( uint32_t TicksNumb ) );
  MOCK_METHOD0( HAL_NVIC_GetPriorityGrouping, uint32_t( void ) );
  MOCK_METHOD4( HAL_NVIC_GetPriority,
                void( IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t *pPreemptPriority, uint32_t *pSubPriority ) );
  MOCK_METHOD1( HAL_NVIC_GetPendingIRQ, uint32_t( IRQn_Type IRQn ) );
  MOCK_METHOD1( HAL_NVIC_SetPendingIRQ, void( IRQn_Type IRQn ) );
  MOCK_METHOD1( HAL_NVIC_ClearPendingIRQ, void( IRQn_Type IRQn ) );
  MOCK_METHOD1( HAL_NVIC_GetActive, uint32_t( IRQn_Type IRQn ) );
  MOCK_METHOD1( HAL_SYSTICK_CLKSourceConfig, void( uint32_t CLKSource ) );
  MOCK_METHOD0( HAL_SYSTICK_IRQHandler, void( void ) );
  MOCK_METHOD0( HAL_SYSTICK_Callback, void( void ) );
  MOCK_METHOD1( HAL_MPU_Enable, void( uint32_t MPU_Control ) );
  MOCK_METHOD0( HAL_MPU_Disable, void( void ) );
  MOCK_METHOD1( HAL_MPU_ConfigRegion, void( MPU_Region_InitTypeDef *MPU_Init ) );
};

extern STM32F4_HAL_CORTEX_Mock *STM32F4_HAL_CORTEX_MockObj;

#endif /* GMOCK_TEST */

#endif /* !MOCK_STM32F4xx_HAL_CORTEX_HPP */
