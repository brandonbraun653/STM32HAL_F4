/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_flash_ex.hpp
 *
 *  Description:
 *    
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32_HAL_FLASH_EX_HPP
#define MOCK_STM32_HAL_FLASH_EX_HPP

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

#include "stm32f4xx_hal_flash_ex.h"

#ifdef __cplusplus
}
#endif

namespace STM32HAL_Mock
{
  class FlashExInterface
  {
  public:
    virtual ~FlashExInterface() = default;

    virtual HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef* pEraseInit, uint32_t* SectorError) = 0;
    virtual HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef* pEraseInit) = 0;
    virtual HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef* pOBInit) = 0;
    virtual void              HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef* pOBInit) = 0;
  };

  class FlashExMock : public FlashExInterface
  {
  public:
    FlashExMock();
    virtual ~FlashExMock() = default;

    MOCK_METHOD2(HAL_FLASHEx_Erase, HAL_StatusTypeDef(FLASH_EraseInitTypeDef* pEraseInit, uint32_t* SectorError));
    MOCK_METHOD1(HAL_FLASHEx_Erase_IT, HAL_StatusTypeDef(FLASH_EraseInitTypeDef* pEraseInit));
    MOCK_METHOD1(HAL_FLASHEx_OBProgram, HAL_StatusTypeDef(FLASH_OBProgramInitTypeDef* pOBInit));
    MOCK_METHOD1(HAL_FLASHEx_OBGetConfig, void(FLASH_OBProgramInitTypeDef* pOBInit));
  };

  using FlashExNiceMock = ::testing::NiceMock<FlashExMock>;
  using FlashExNiceMock_sPtr = std::shared_ptr<FlashExNiceMock>;

  extern FlashExNiceMock_sPtr flashExMockObj;
}

#endif /* GMOCK_TEST */

#endif /* !MOCK_STM32_HAL_FLASH_EX_HPP */