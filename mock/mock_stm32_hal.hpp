/********************************************************************************
 *  File Name:
 *    mock_stm32f4xx_hal.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32_HAL_HPP
#define MOCK_STM32_HAL_HPP

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

#include "stm32f4xx_hal.h"

#ifdef __cplusplus
}
#endif

class STM32_HAL_Interface
{
public:
  virtual ~STM32_HAL_Interface() = default;

  virtual HAL_StatusTypeDef HAL_Init( void );
  virtual HAL_StatusTypeDef HAL_DeInit( void );
  virtual void HAL_MspInit( void );
  virtual void HAL_MspDeInit( void );
  virtual HAL_StatusTypeDef HAL_InitTick( uint32_t TickPriority );
  virtual void HAL_IncTick( void );
  virtual void HAL_Delay( uint32_t Delay );
  virtual uint32_t HAL_GetTick( void );
  virtual uint32_t HAL_GetTickPrio( void );
  virtual HAL_StatusTypeDef HAL_SetTickFreq( HAL_TickFreqTypeDef Freq );
  virtual HAL_TickFreqTypeDef HAL_GetTickFreq( void );
  virtual void HAL_SuspendTick( void );
  virtual void HAL_ResumeTick( void );
  virtual uint32_t HAL_GetHalVersion( void );
  virtual uint32_t HAL_GetREVID( void );
  virtual uint32_t HAL_GetDEVID( void );
  virtual void HAL_DBGMCU_EnableDBGSleepMode( void );
  virtual void HAL_DBGMCU_DisableDBGSleepMode( void );
  virtual void HAL_DBGMCU_EnableDBGStopMode( void );
  virtual void HAL_DBGMCU_DisableDBGStopMode( void );
  virtual void HAL_DBGMCU_EnableDBGStandbyMode( void );
  virtual void HAL_DBGMCU_DisableDBGStandbyMode( void );
  virtual void HAL_EnableCompensationCell( void );
  virtual void HAL_DisableCompensationCell( void );
  virtual void HAL_GetUID( uint32_t *UID );
  virtual void HAL_EnableMemorySwappingBank( void );
  virtual void HAL_DisableMemorySwappingBank( void );
};

class STM32_HAL_Mock : public STM32_HAL_Interface
{
public:
  virtual ~STM32_HAL_Mock() = default;

  MOCK_METHOD0( HAL_Init, HAL_StatusTypeDef( void ) );
  MOCK_METHOD0( HAL_DeInit, HAL_StatusTypeDef( void ) );
  MOCK_METHOD0( HAL_MspInit, void( void ) );
  MOCK_METHOD0( HAL_MspDeInit, void( void ) );
  MOCK_METHOD1( HAL_InitTick, HAL_StatusTypeDef( uint32_t TickPriority ) );
  MOCK_METHOD0( HAL_IncTick, void( void ) );
  MOCK_METHOD1( HAL_Delay, void( uint32_t Delay ) );
  MOCK_METHOD0( HAL_GetTick, uint32_t( void ) );
  MOCK_METHOD0( HAL_GetTickPrio, uint32_t( void ) );
  MOCK_METHOD1( HAL_SetTickFreq, HAL_StatusTypeDef( HAL_TickFreqTypeDef Freq ) );
  MOCK_METHOD0( HAL_GetTickFreq, HAL_TickFreqTypeDef( void ) );
  MOCK_METHOD0( HAL_SuspendTick, void( void ) );
  MOCK_METHOD0( HAL_ResumeTick, void( void ) );
  MOCK_METHOD0( HAL_GetHalVersion, uint32_t( void ) );
  MOCK_METHOD0( HAL_GetREVID, uint32_t( void ) );
  MOCK_METHOD0( HAL_GetDEVID, uint32_t( void ) );
  MOCK_METHOD0( HAL_DBGMCU_EnableDBGSleepMode, void( void ) );
  MOCK_METHOD0( HAL_DBGMCU_DisableDBGSleepMode, void( void ) );
  MOCK_METHOD0( HAL_DBGMCU_EnableDBGStopMode, void ( void ) );
  MOCK_METHOD0( HAL_DBGMCU_DisableDBGStopMode, void( void ) );
  MOCK_METHOD0( HAL_DBGMCU_EnableDBGStandbyMode, void( void ) );
  MOCK_METHOD0( HAL_DBGMCU_DisableDBGStandbyMode, void( void ) );
  MOCK_METHOD0( HAL_EnableCompensationCell, void( void ) );
  MOCK_METHOD0( HAL_DisableCompensationCell, void( void ) );
  MOCK_METHOD1( HAL_GetUID, void( uint32_t *UID ) );
  MOCK_METHOD0( HAL_EnableMemorySwappingBank, void( void ) );
  MOCK_METHOD0( HAL_DisableMemorySwappingBank, void( void ) );
};

extern STM32_HAL_Mock *STM32_HAL_MockObj;

#endif /* GMOCK_TEST */

#endif /* !mock_stm32_hal_HPP */
