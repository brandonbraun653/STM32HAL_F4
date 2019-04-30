/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_flash_ex.cpp
 *
 *  Description:
 *    
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32_hal_flash_ex.hpp"

#if defined(GMOCK_TEST)
namespace STM32HAL_Mock
{
  using ::testing::Return;
  using ::testing::_;
  
  FlashExNiceMock_sPtr flashExMockObj = nullptr;

  FlashExMock::FlashExMock()
  {
    ON_CALL(*this, HAL_FLASHEx_Erase(_, _)).WillByDefault(Return(HAL_OK));
    ON_CALL(*this, HAL_FLASHEx_Erase_IT(_)).WillByDefault(Return(HAL_OK));
    ON_CALL(*this, HAL_FLASHEx_OBProgram(_)).WillByDefault(Return(HAL_OK));
  }
}

HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef* pEraseInit, uint32_t* SectorError)
{
  return STM32HAL_Mock::flashExMockObj->HAL_FLASHEx_Erase(pEraseInit, SectorError);
}

HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef* pEraseInit)
{
  return STM32HAL_Mock::flashExMockObj->HAL_FLASHEx_Erase_IT(pEraseInit);
}

HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef* pOBInit)
{
  return STM32HAL_Mock::flashExMockObj->HAL_FLASHEx_OBProgram(pOBInit);
}

void HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef* pOBInit)
{
  STM32HAL_Mock::flashExMockObj->HAL_FLASHEx_OBGetConfig(pOBInit);
}

#endif /* GMOCK_TEST */