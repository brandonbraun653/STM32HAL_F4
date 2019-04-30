/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_flash.cpp
 *
 *  Description:
 *    
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32_hal_flash.hpp"

#if defined(GMOCK_TEST)
namespace STM32HAL_Mock
{
  using ::testing::Return;
  using ::testing::_;

  FlashNiceMock_sPtr flashMockObj = nullptr;

  FlashMock::FlashMock()
  {
    ON_CALL(*this, HAL_FLASH_Program(_, _, _)).WillByDefault(Return(HAL_OK));
    ON_CALL(*this, HAL_FLASH_Program_IT(_, _, _)).WillByDefault(Return(HAL_OK));
    ON_CALL(*this, HAL_FLASH_Unlock()).WillByDefault(Return(HAL_OK));
    ON_CALL(*this, HAL_FLASH_Lock()).WillByDefault(Return(HAL_OK));
    ON_CALL(*this, HAL_FLASH_OB_Unlock()).WillByDefault(Return(HAL_OK));
    ON_CALL(*this, HAL_FLASH_OB_Lock()).WillByDefault(Return(HAL_OK));
    ON_CALL(*this, HAL_FLASH_OB_Launch()).WillByDefault(Return(HAL_OK));
    ON_CALL(*this, FLASH_WaitForLastOperation(_)).WillByDefault(Return(HAL_OK));
    ON_CALL(*this, HAL_FLASH_GetError()).WillByDefault(Return(0u));
  }
}


HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data)
{
  return STM32HAL_Mock::flashMockObj->HAL_FLASH_Program(TypeProgram, Address, Data);
}

HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data)
{
  return STM32HAL_Mock::flashMockObj->HAL_FLASH_Program_IT(TypeProgram, Address, Data);
}

void HAL_FLASH_IRQHandler(void)
{
  STM32HAL_Mock::flashMockObj->HAL_FLASH_IRQHandler();
}

void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue)
{
  STM32HAL_Mock::flashMockObj->HAL_FLASH_EndOfOperationCallback(ReturnValue);
}

void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue)
{
  STM32HAL_Mock::flashMockObj->HAL_FLASH_OperationErrorCallback(ReturnValue);
}

HAL_StatusTypeDef HAL_FLASH_Unlock(void)
{
  return STM32HAL_Mock::flashMockObj->HAL_FLASH_Unlock();
}

HAL_StatusTypeDef HAL_FLASH_Lock(void)
{
  return STM32HAL_Mock::flashMockObj->HAL_FLASH_Lock();
}

HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void)
{
  return STM32HAL_Mock::flashMockObj->HAL_FLASH_OB_Unlock();
}

HAL_StatusTypeDef HAL_FLASH_OB_Lock(void)
{
  return STM32HAL_Mock::flashMockObj->HAL_FLASH_OB_Lock();
}

HAL_StatusTypeDef HAL_FLASH_OB_Launch(void)
{
  return STM32HAL_Mock::flashMockObj->HAL_FLASH_OB_Launch();
}

uint32_t HAL_FLASH_GetError(void)
{
  return STM32HAL_Mock::flashMockObj->HAL_FLASH_GetError();
}

HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout)
{
  return STM32HAL_Mock::flashMockObj->FLASH_WaitForLastOperation(Timeout);
}



#endif /* GMOCK_TEST */