/********************************************************************************
 *  File Name:
 *    mock_stm32_hal.cpp
 *
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32_hal.hpp"

#if defined( GMOCK_TEST )

STM32_HAL_Mock *STM32_HAL_MockObj = nullptr;

HAL_StatusTypeDef HAL_Init( void )
{
  return STM32_HAL_MockObj->HAL_Init();
}

HAL_StatusTypeDef HAL_DeInit( void )
{
  return STM32_HAL_MockObj->HAL_DeInit();
}

void HAL_MspInit( void )
{
  STM32_HAL_MockObj->HAL_MspInit();
}

void HAL_MspDeInit( void )
{
  STM32_HAL_MockObj->HAL_MspDeInit();
}

HAL_StatusTypeDef HAL_InitTick( uint32_t TickPriority )
{
  return STM32_HAL_MockObj->HAL_InitTick( TickPriority );
}

void HAL_IncTick( void )
{
  STM32_HAL_MockObj->HAL_IncTick();
}

void HAL_Delay( uint32_t Delay )
{
  STM32_HAL_MockObj->HAL_Delay( Delay );
}

uint32_t HAL_GetTick( void )
{
  return STM32_HAL_MockObj->HAL_GetTick();
}

uint32_t HAL_GetTickPrio( void )
{
  return STM32_HAL_MockObj->HAL_GetTickPrio();
}

HAL_StatusTypeDef HAL_SetTickFreq( HAL_TickFreqTypeDef Freq )
{
  return STM32_HAL_MockObj->HAL_SetTickFreq( Freq );
}

HAL_TickFreqTypeDef HAL_GetTickFreq( void )
{
  return STM32_HAL_MockObj->HAL_GetTickFreq();
}

void HAL_SuspendTick( void )
{
  STM32_HAL_MockObj->HAL_SuspendTick();
}

void HAL_ResumeTick( void )
{
  STM32_HAL_MockObj->HAL_ResumeTick();
}

uint32_t HAL_GetHalVersion( void )
{
  return STM32_HAL_MockObj->HAL_GetHalVersion();
}

uint32_t HAL_GetREVID( void )
{
  return STM32_HAL_MockObj->HAL_GetREVID();
}

uint32_t HAL_GetDEVID( void )
{
  return STM32_HAL_MockObj->HAL_GetDEVID();
}

void HAL_DBGMCU_EnableDBGSleepMode( void )
{
  STM32_HAL_MockObj->HAL_DBGMCU_EnableDBGSleepMode();
}

void HAL_DBGMCU_DisableDBGSleepMode( void )
{
  STM32_HAL_MockObj->HAL_DBGMCU_DisableDBGSleepMode();
}

void HAL_DBGMCU_EnableDBGStopMode( void )
{
  STM32_HAL_MockObj->HAL_DBGMCU_EnableDBGStopMode();
}

void HAL_DBGMCU_DisableDBGStopMode( void )
{
  STM32_HAL_MockObj->HAL_DBGMCU_DisableDBGStopMode();
}

void HAL_DBGMCU_EnableDBGStandbyMode( void )
{
  STM32_HAL_MockObj->HAL_DBGMCU_EnableDBGStandbyMode();
}

void HAL_DBGMCU_DisableDBGStandbyMode( void )
{
  STM32_HAL_MockObj->HAL_DBGMCU_DisableDBGStandbyMode();
}

void HAL_EnableCompensationCell( void )
{
  STM32_HAL_MockObj->HAL_EnableCompensationCell();
}

void HAL_DisableCompensationCell( void )
{
  STM32_HAL_MockObj->HAL_DisableCompensationCell();
}

void HAL_GetUID( uint32_t *UID )
{
  STM32_HAL_MockObj->HAL_GetUID( UID );
}

void HAL_EnableMemorySwappingBank( void )
{
  STM32_HAL_MockObj->HAL_EnableMemorySwappingBank();
}

void HAL_DisableMemorySwappingBank( void )
{
  STM32_HAL_MockObj->HAL_DisableMemorySwappingBank();
}

#endif /* GMOCK_TEST */
