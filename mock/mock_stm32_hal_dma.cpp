/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_dma.cpp
 *
 *  Description:
 *    Provides stubs for the STM32HAL driver that call into the mocking framework
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include "mock_stm32_hal_dma.hpp"

#if defined( GMOCK_TEST )

namespace STM32HAL_Mock
{
  using ::testing::_;
  using ::testing::Return;

  DMANiceMock_sPtr dmaMockObj = nullptr;

  DMAMock::DMAMock()
  {
    ON_CALL( *this, HAL_DMA_Init( _ ) ).WillByDefault( Return( HAL_OK ) );
    ON_CALL( *this, HAL_DMA_DeInit( _ ) ).WillByDefault( Return( HAL_OK ) );
    ON_CALL( *this, HAL_DMA_Start( _, _, _, _ ) ).WillByDefault( Return( HAL_OK ) );
    ON_CALL( *this, HAL_DMA_Start_IT( _, _, _, _ ) ).WillByDefault( Return( HAL_OK ) );
    ON_CALL( *this, HAL_DMA_Abort( _ ) ).WillByDefault( Return( HAL_OK ) );
    ON_CALL( *this, HAL_DMA_Abort_IT( _ ) ).WillByDefault( Return( HAL_OK ) );
    ON_CALL( *this, HAL_DMA_PollForTransfer( _, _, _ ) ).WillByDefault( Return( HAL_OK ) );
    ON_CALL( *this, HAL_DMA_CleanCallbacks( _ ) ).WillByDefault( Return( HAL_OK ) );
    ON_CALL( *this, HAL_DMA_RegisterCallback( _, _, _ ) ).WillByDefault( Return( HAL_OK ) );
    ON_CALL( *this, HAL_DMA_UnRegisterCallback( _, _ ) ).WillByDefault( Return( HAL_OK ) );
    ON_CALL( *this, HAL_DMA_GetState( _ ) ).WillByDefault( Return( HAL_DMA_STATE_READY ) );
    ON_CALL( *this, HAL_DMA_GetError( _ ) ).WillByDefault( Return( 0u ) );
  }
}    // namespace STM32HAL_Mock

HAL_StatusTypeDef HAL_DMA_Init( DMA_HandleTypeDef *hdma )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_Init( hdma );
}

HAL_StatusTypeDef HAL_DMA_DeInit( DMA_HandleTypeDef *hdma )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_DeInit( hdma );
}

HAL_StatusTypeDef HAL_DMA_Start( DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_Start( hdma, SrcAddress, DstAddress, DataLength );
}

HAL_StatusTypeDef HAL_DMA_Start_IT( DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_Start_IT( hdma, SrcAddress, DstAddress, DataLength );
}

HAL_StatusTypeDef HAL_DMA_Abort( DMA_HandleTypeDef *hdma )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_Abort( hdma );
}

HAL_StatusTypeDef HAL_DMA_Abort_IT( DMA_HandleTypeDef *hdma )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_Abort_IT( hdma );
}

HAL_StatusTypeDef HAL_DMA_PollForTransfer( DMA_HandleTypeDef *hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel,
                                           uint32_t Timeout )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_PollForTransfer( hdma, CompleteLevel, Timeout );
}

void HAL_DMA_IRQHandler( DMA_HandleTypeDef *hdma )
{
  STM32HAL_Mock::dmaMockObj->HAL_DMA_IRQHandler( hdma );
}

HAL_StatusTypeDef HAL_DMA_CleanCallbacks( DMA_HandleTypeDef *hdma )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_CleanCallbacks( hdma );
}

HAL_StatusTypeDef HAL_DMA_RegisterCallback( DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID,
                                            void ( *pCallback )( DMA_HandleTypeDef *_hdma ) )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_RegisterCallback( hdma, CallbackID, pCallback );
}

HAL_StatusTypeDef HAL_DMA_UnRegisterCallback( DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_UnRegisterCallback( hdma, CallbackID );
}

HAL_DMA_StateTypeDef HAL_DMA_GetState( DMA_HandleTypeDef *hdma )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_GetState( hdma );
}

uint32_t HAL_DMA_GetError( DMA_HandleTypeDef *hdma )
{
  return STM32HAL_Mock::dmaMockObj->HAL_DMA_GetError( hdma );
}

#endif /* GMOCK_TEST */
