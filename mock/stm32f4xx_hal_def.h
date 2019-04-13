#pragma once
#ifndef mock_stm32_hal_DEF_H
#define mock_stm32_hal_DEF_H


#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx.h"
#include <stdio.h>

  typedef enum
  {
    HAL_OK      = 0x00U,
    HAL_ERROR   = 0x01U,
    HAL_BUSY    = 0x02U,
    HAL_TIMEOUT = 0x03U
  } HAL_StatusTypeDef;

  typedef enum
  {
    HAL_UNLOCKED = 0x00U,
    HAL_LOCKED   = 0x01U
  } HAL_LockTypeDef;

#define UNUSED( X ) ( void )X

#define HAL_MAX_DELAY 0xFFFFFFFFU
#define HAL_IS_BIT_SET( REG, BIT )
#define HAL_IS_BIT_CLR( REG, BIT )
#define __HAL_LINKDMA( __HANDLE__, __PPP_DMA_FIELD__, __DMA_HANDLE__ )
#define __HAL_RESET_HANDLE_STATE( __HANDLE__ )
#define __HAL_LOCK( __HANDLE__ )
#define __HAL_UNLOCK( __HANDLE__ )


#ifdef __cplusplus
}
#endif


#endif /* !mock_stm32_hal_DEF_H */
