/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_flash.hpp
 *
 *  Description:
 *    
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32_HAL_FLASH_HPP
#define MOCK_STM32_HAL_FLASH_HPP

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

#include "stm32f4xx_hal_flash.h"

#ifdef __cplusplus
}
#endif

namespace STM32HAL_Mock
{
  class FlashInterface
  {
  public:
    virtual ~FlashInterface() = default;

    virtual HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data) = 0;
    virtual HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data) = 0;
    virtual void HAL_FLASH_IRQHandler(void) = 0;
    virtual void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue) = 0;
    virtual void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue) = 0;
    virtual HAL_StatusTypeDef HAL_FLASH_Unlock(void) = 0;
    virtual HAL_StatusTypeDef HAL_FLASH_Lock(void) = 0;
    virtual HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void) = 0;
    virtual HAL_StatusTypeDef HAL_FLASH_OB_Lock(void) = 0;
    virtual HAL_StatusTypeDef HAL_FLASH_OB_Launch(void) = 0;
    virtual uint32_t HAL_FLASH_GetError(void) = 0;
    virtual HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout) = 0;
  };

  class FlashMock : public FlashInterface
  {
  public:
    FlashMock();
    virtual ~FlashMock() = default;

    MOCK_METHOD3(HAL_FLASH_Program, HAL_StatusTypeDef(uint32_t TypeProgram, uint32_t Address, uint64_t Data));
    MOCK_METHOD3(HAL_FLASH_Program_IT, HAL_StatusTypeDef(uint32_t TypeProgram, uint32_t Address, uint64_t Data));
    MOCK_METHOD0(HAL_FLASH_IRQHandler, void(void));
    MOCK_METHOD1(HAL_FLASH_EndOfOperationCallback, void(uint32_t ReturnValue));
    MOCK_METHOD1(HAL_FLASH_OperationErrorCallback, void(uint32_t ReturnValue));
    MOCK_METHOD0(HAL_FLASH_Unlock, HAL_StatusTypeDef(void));
    MOCK_METHOD0(HAL_FLASH_Lock, HAL_StatusTypeDef(void));
    MOCK_METHOD0(HAL_FLASH_OB_Unlock, HAL_StatusTypeDef(void));
    MOCK_METHOD0(HAL_FLASH_OB_Lock, HAL_StatusTypeDef(void));
    MOCK_METHOD0(HAL_FLASH_OB_Launch, HAL_StatusTypeDef(void));
    MOCK_METHOD0(HAL_FLASH_GetError, uint32_t(void));
    MOCK_METHOD1(FLASH_WaitForLastOperation, HAL_StatusTypeDef(uint32_t Timeout));
  };

  using FlashNiceMock = ::testing::NiceMock<FlashMock>;
  using FlashNiceMock_sPtr = std::shared_ptr<FlashNiceMock>;

  extern FlashNiceMock_sPtr flashMockObj;
}

#endif /* GMOCK_TEST */

#endif /* !MOCK_STM32_HAL_FLASH_HPP */