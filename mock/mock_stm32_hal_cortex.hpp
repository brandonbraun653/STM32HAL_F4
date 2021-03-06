/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_cortex.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32_HAL_CORTEX_HPP
#define MOCK_STM32_HAL_CORTEX_HPP

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

namespace STM32HAL_Mock
{
	
	class CortexInterface
	{
	public:
	  virtual ~CortexInterface() = default;
	
    virtual void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup) = 0;
    virtual void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority) = 0;
    virtual void HAL_NVIC_EnableIRQ(IRQn_Type IRQn) = 0;
    virtual void HAL_NVIC_DisableIRQ(IRQn_Type IRQn) = 0;
    virtual void HAL_NVIC_SystemReset(void) = 0;
    virtual uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb) = 0;
    virtual uint32_t HAL_NVIC_GetPriorityGrouping(void) = 0;
    virtual void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority) = 0;
    virtual uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn) = 0;
    virtual void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn) = 0;
    virtual void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn) = 0;
    virtual uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn) = 0;
    virtual void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource) = 0;
    virtual void HAL_SYSTICK_IRQHandler(void) = 0;
    virtual void HAL_SYSTICK_Callback(void) = 0;
    virtual void HAL_MPU_Enable(uint32_t MPU_Control) = 0;
    virtual void HAL_MPU_Disable(void) = 0;
    virtual void HAL_MPU_ConfigRegion(MPU_Region_InitTypeDef* MPU_Init) = 0;
	};
	
	class CortexMock : public CortexInterface
	{
	public:
    CortexMock();
	  virtual ~CortexMock() = default;
	
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
	
  using CortexNiceMock = ::testing::NiceMock<CortexMock>;
  using CortexNiceMock_sPtr = std::shared_ptr<CortexNiceMock>;

	extern CortexNiceMock_sPtr cortexMockObj;
}

#endif /* GMOCK_TEST */

#endif /* !mock_stm32_hal_CORTEX_HPP */
