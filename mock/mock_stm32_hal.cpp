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

namespace STM32HAL_Mock
{
	CoreMock *coreMockObj = nullptr;
}

HAL_StatusTypeDef HAL_Init( void )
{
  return STM32HAL_Mock::coreMockObj->HAL_Init();
}

HAL_StatusTypeDef HAL_DeInit( void )
{
  return STM32HAL_Mock::coreMockObj->HAL_DeInit();
}

void HAL_MspInit( void )
{
  STM32HAL_Mock::coreMockObj->HAL_MspInit();
}

void HAL_MspDeInit( void )
{
  STM32HAL_Mock::coreMockObj->HAL_MspDeInit();
}

HAL_StatusTypeDef HAL_InitTick( uint32_t TickPriority )
{
  return STM32HAL_Mock::coreMockObj->HAL_InitTick( TickPriority );
}

void HAL_IncTick( void )
{
  STM32HAL_Mock::coreMockObj->HAL_IncTick();
}

void HAL_Delay( uint32_t Delay )
{
  STM32HAL_Mock::coreMockObj->HAL_Delay( Delay );
}

uint32_t HAL_GetTick( void )
{
  return STM32HAL_Mock::coreMockObj->HAL_GetTick();
}

uint32_t HAL_GetTickPrio( void )
{
  return STM32HAL_Mock::coreMockObj->HAL_GetTickPrio();
}

HAL_StatusTypeDef HAL_SetTickFreq( HAL_TickFreqTypeDef Freq )
{
  return STM32HAL_Mock::coreMockObj->HAL_SetTickFreq( Freq );
}

HAL_TickFreqTypeDef HAL_GetTickFreq( void )
{
  return STM32HAL_Mock::coreMockObj->HAL_GetTickFreq();
}

void HAL_SuspendTick( void )
{
  STM32HAL_Mock::coreMockObj->HAL_SuspendTick();
}

void HAL_ResumeTick( void )
{
  STM32HAL_Mock::coreMockObj->HAL_ResumeTick();
}

uint32_t HAL_GetHalVersion( void )
{
  return STM32HAL_Mock::coreMockObj->HAL_GetHalVersion();
}

uint32_t HAL_GetREVID( void )
{
  return STM32HAL_Mock::coreMockObj->HAL_GetREVID();
}

uint32_t HAL_GetDEVID( void )
{
  return STM32HAL_Mock::coreMockObj->HAL_GetDEVID();
}

void HAL_DBGMCU_EnableDBGSleepMode( void )
{
  STM32HAL_Mock::coreMockObj->HAL_DBGMCU_EnableDBGSleepMode();
}

void HAL_DBGMCU_DisableDBGSleepMode( void )
{
  STM32HAL_Mock::coreMockObj->HAL_DBGMCU_DisableDBGSleepMode();
}

void HAL_DBGMCU_EnableDBGStopMode( void )
{
  STM32HAL_Mock::coreMockObj->HAL_DBGMCU_EnableDBGStopMode();
}

void HAL_DBGMCU_DisableDBGStopMode( void )
{
  STM32HAL_Mock::coreMockObj->HAL_DBGMCU_DisableDBGStopMode();
}

void HAL_DBGMCU_EnableDBGStandbyMode( void )
{
  STM32HAL_Mock::coreMockObj->HAL_DBGMCU_EnableDBGStandbyMode();
}

void HAL_DBGMCU_DisableDBGStandbyMode( void )
{
  STM32HAL_Mock::coreMockObj->HAL_DBGMCU_DisableDBGStandbyMode();
}

void HAL_EnableCompensationCell( void )
{
  STM32HAL_Mock::coreMockObj->HAL_EnableCompensationCell();
}

void HAL_DisableCompensationCell( void )
{
  STM32HAL_Mock::coreMockObj->HAL_DisableCompensationCell();
}

void HAL_GetUID( uint32_t *UID )
{
  STM32HAL_Mock::coreMockObj->HAL_GetUID( UID );
}

void HAL_EnableMemorySwappingBank( void )
{
  STM32HAL_Mock::coreMockObj->HAL_EnableMemorySwappingBank();
}

void HAL_DisableMemorySwappingBank( void )
{
  STM32HAL_Mock::coreMockObj->HAL_DisableMemorySwappingBank();
}

#endif /* GMOCK_TEST */
