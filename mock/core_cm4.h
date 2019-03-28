/********************************************************************************
 *  File Name:
 *    core_cm4.h
 *
 *  Description:
 *    Dummy header that STM32F4 HAL needs to compile, but doesn't actually contain
 *    useful information for mocking purposes.
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#pragma once
#ifndef MOCK_CORE_CM4_H
#define MOCK_CORE_CM4_H

#include <cstdint>
#include <cstdlib>

#define __IO volatile

#define __STATIC_INLINE
#define __RAM_FUNC
#define __ALIGN_BEGIN
#define __ALIGN_END
#define __NOINLINE
#define __weak
#define __packed

#endif
