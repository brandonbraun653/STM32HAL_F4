/********************************************************************************
 *  File Name:
 *    mock_stm32_hal_dma.hpp
 *
 *  Description:
 *    Mocks the STM32 HAL with GMock
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_STM32_HAL_DMA_HPP
#define MOCK_STM32_HAL_DMA_HPP

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

#include "stm32f4xx_hal_dma.h"

#ifdef __cplusplus
}
#endif

namespace STM32HAL_Mock
{
  class DMAInterface
  {
  public:
    virtual ~DMAInterface() = default;

    virtual HAL_StatusTypeDef HAL_DMA_Init( DMA_HandleTypeDef *hdma ) = 0;
    virtual HAL_StatusTypeDef HAL_DMA_DeInit( DMA_HandleTypeDef *hdma ) = 0;
    virtual HAL_StatusTypeDef HAL_DMA_Start( DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress,
                                             uint32_t DataLength ) = 0;
    virtual HAL_StatusTypeDef HAL_DMA_Start_IT( DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress,
                                                uint32_t DataLength ) = 0;
    virtual HAL_StatusTypeDef HAL_DMA_Abort( DMA_HandleTypeDef *hdma ) = 0;
    virtual HAL_StatusTypeDef HAL_DMA_Abort_IT( DMA_HandleTypeDef *hdma ) = 0;
    virtual HAL_StatusTypeDef HAL_DMA_PollForTransfer( DMA_HandleTypeDef *hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel,
                                                       uint32_t Timeout ) = 0;
    virtual void HAL_DMA_IRQHandler( DMA_HandleTypeDef *hdma ) = 0;
    virtual HAL_StatusTypeDef HAL_DMA_CleanCallbacks( DMA_HandleTypeDef *hdma ) = 0;
    virtual HAL_StatusTypeDef HAL_DMA_RegisterCallback( DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID,
                                                        void ( *pCallback )( DMA_HandleTypeDef *_hdma ) ) = 0;
    virtual HAL_StatusTypeDef HAL_DMA_UnRegisterCallback( DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID ) = 0;
    virtual HAL_DMA_StateTypeDef HAL_DMA_GetState( DMA_HandleTypeDef *hdma ) = 0;
    virtual uint32_t HAL_DMA_GetError( DMA_HandleTypeDef *hdma ) = 0;
  };

  class DMAMock : public DMAInterface
  {
  public:
    DMAMock();
    virtual ~DMAMock() = default;

    MOCK_METHOD1( HAL_DMA_Init, HAL_StatusTypeDef( DMA_HandleTypeDef *hdma ) );
    MOCK_METHOD1( HAL_DMA_DeInit, HAL_StatusTypeDef( DMA_HandleTypeDef *hdma ) );
    MOCK_METHOD4( HAL_DMA_Start,
                  HAL_StatusTypeDef( DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength ) );
    MOCK_METHOD4( HAL_DMA_Start_IT,
                  HAL_StatusTypeDef( DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength ) );
    MOCK_METHOD1( HAL_DMA_Abort, HAL_StatusTypeDef( DMA_HandleTypeDef *hdma ) );
    MOCK_METHOD1( HAL_DMA_Abort_IT, HAL_StatusTypeDef( DMA_HandleTypeDef *hdma ) );
    MOCK_METHOD3( HAL_DMA_PollForTransfer,
                  HAL_StatusTypeDef( DMA_HandleTypeDef *hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel, uint32_t Timeout ) );
    MOCK_METHOD1( HAL_DMA_IRQHandler, void( DMA_HandleTypeDef *hdma ) );
    MOCK_METHOD1( HAL_DMA_CleanCallbacks, HAL_StatusTypeDef( DMA_HandleTypeDef *hdma ) );
    MOCK_METHOD3( HAL_DMA_RegisterCallback, HAL_StatusTypeDef( DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID,
                                                               void ( *pCallback )( DMA_HandleTypeDef *_hdma ) ) );
    MOCK_METHOD2( HAL_DMA_UnRegisterCallback,
                  HAL_StatusTypeDef( DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID ) );
    MOCK_METHOD1( HAL_DMA_GetState, HAL_DMA_StateTypeDef( DMA_HandleTypeDef *hdma ) );
    MOCK_METHOD1( HAL_DMA_GetError, uint32_t( DMA_HandleTypeDef *hdma ) );
  };

  using DMANiceMock      = ::testing::NiceMock<DMAMock>;
  using DMANiceMock_sPtr = std::shared_ptr<DMANiceMock>;

  extern DMANiceMock_sPtr dmaMockObj;
}    // namespace STM32HAL_Mock

#endif /* GMOCK_TEST */

#endif /* !mock_stm32_hal_DMA_HPP */
