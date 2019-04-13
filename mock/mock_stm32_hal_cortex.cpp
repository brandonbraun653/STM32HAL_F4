/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_cortex.cpp
 *
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32_hal_cortex.hpp"

#if defined( GMOCK_TEST )

STM32_HAL_CORTEX_Mock *STM32_HAL_CORTEX_MockObj = nullptr;

void HAL_NVIC_SetPriorityGrouping( uint32_t PriorityGroup )
{
  STM32_HAL_CORTEX_MockObj->HAL_NVIC_SetPriorityGrouping( PriorityGroup );
}

void HAL_NVIC_SetPriority( IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority )
{
  STM32_HAL_CORTEX_MockObj->HAL_NVIC_SetPriority( IRQn, PreemptPriority, SubPriority );
}

void HAL_NVIC_EnableIRQ( IRQn_Type IRQn )
{
  STM32_HAL_CORTEX_MockObj->HAL_NVIC_EnableIRQ( IRQn );
}

void HAL_NVIC_DisableIRQ( IRQn_Type IRQn )
{
  STM32_HAL_CORTEX_MockObj->HAL_NVIC_DisableIRQ( IRQn );
}

void HAL_NVIC_SystemReset( void )
{
  STM32_HAL_CORTEX_MockObj->HAL_NVIC_SystemReset();
}

uint32_t HAL_SYSTICK_Config( uint32_t TicksNumb )
{
  return STM32_HAL_CORTEX_MockObj->HAL_SYSTICK_Config( TicksNumb );
}

uint32_t HAL_NVIC_GetPriorityGrouping( void )
{
  return STM32_HAL_CORTEX_MockObj->HAL_NVIC_GetPriorityGrouping();
}

void HAL_NVIC_GetPriority( IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t *pPreemptPriority, uint32_t *pSubPriority )
{
  STM32_HAL_CORTEX_MockObj->HAL_NVIC_GetPriority( IRQn, PriorityGroup, pPreemptPriority, pSubPriority );
}

uint32_t HAL_NVIC_GetPendingIRQ( IRQn_Type IRQn )
{
  return STM32_HAL_CORTEX_MockObj->HAL_NVIC_GetPendingIRQ( IRQn );
}

void HAL_NVIC_SetPendingIRQ( IRQn_Type IRQn )
{
  STM32_HAL_CORTEX_MockObj->HAL_NVIC_SetPendingIRQ( IRQn );
}

void HAL_NVIC_ClearPendingIRQ( IRQn_Type IRQn )
{
  STM32_HAL_CORTEX_MockObj->HAL_NVIC_ClearPendingIRQ( IRQn );
}

uint32_t HAL_NVIC_GetActive( IRQn_Type IRQn )
{
  return STM32_HAL_CORTEX_MockObj->HAL_NVIC_GetActive( IRQn );
}

void HAL_SYSTICK_CLKSourceConfig( uint32_t CLKSource )
{
  STM32_HAL_CORTEX_MockObj->HAL_SYSTICK_CLKSourceConfig( CLKSource );
}

void HAL_SYSTICK_IRQHandler( void )
{
  STM32_HAL_CORTEX_MockObj->HAL_SYSTICK_IRQHandler();
}

void HAL_SYSTICK_Callback( void )
{
  STM32_HAL_CORTEX_MockObj->HAL_SYSTICK_Callback();
}

void HAL_MPU_Enable( uint32_t MPU_Control )
{
  STM32_HAL_CORTEX_MockObj->HAL_MPU_Enable( MPU_Control );
}

void HAL_MPU_Disable( void )
{
  STM32_HAL_CORTEX_MockObj->HAL_MPU_Disable();
}

void HAL_MPU_ConfigRegion( MPU_Region_InitTypeDef *MPU_Init )
{
  STM32_HAL_CORTEX_MockObj->HAL_MPU_ConfigRegion( MPU_Init );
}

#endif /* GMOCK_TEST */
