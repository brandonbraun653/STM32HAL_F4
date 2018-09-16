cmake_minimum_required(VERSION 3.12.2)

# Assign the Thor toolchain file if one isn't passed to the command line
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "../../../cmake/toolchain.cmake")
endif()

# Assign a dbg tag to delineate debug build outputs
if(NOT CMAKE_DEBUG_POSTFIX)
    set(CMAKE_DEBUG_POSTFIX _dbg)
endif()

# Assign a rel tag to delineate release build outputs
if(NOT CMAKE_RELEASE_POSTFIX)
    set(CMAKE_RELEASE_POSTFIX _rel)
endif()

project(stm32f4_hal)

set(STM32F4_COMPILE_OPTIONS
    --std=gnu11
    -fno-common
    -fmessage-length=0
    -fno-exceptions
    -ffunction-sections
    -fdata-sections
    -Wall
    -mcpu=cortex-m4
    -mthumb
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
)

set(STM32F4_COMPILE_DEFINITIONS
    -DUSE_FULL_LL_DRIVER
    -D${STM32_TARGET_DEVICE_UPPER}
)

# Build the relavent directories
set(CMSIS_ROOT "${CMAKE_CURRENT_LIST_DIR}/CMSIS")
set(HAL_ROOT "${CMAKE_CURRENT_LIST_DIR}/${STM32_TARGET_FAMILY_UPPER}xx_HAL_Driver")
set(DEV_ROOT "${CMAKE_CURRENT_LIST_DIR}/Device")

set(STM32F4_HAL_INC_DIRS 
    "${HAL_ROOT}/Inc"
    "${DEV_ROOT}/conf"
    "${CMSIS_ROOT}/Include" 
    "${CMSIS_ROOT}/Device/ST/${STM32_TARGET_FAMILY_UPPER}xx/Include"
)

# Grab all the files .h/.c
file(GLOB CMSIS_INC_1 "${CMSIS_ROOT}/Include/*.h")
file(GLOB CMSIS_INC_2 "${CMSIS_ROOT}/Device/ST/${STM32_TARGET_FAMILY_UPPER}xx/Include/*.h")
set(CMSIS_INC_FILES ${CMSIS_INC_1} ${CMSIS_INC_2})
file(GLOB HAL_INC_FILES "${HAL_ROOT}/Inc/*.h")
file(GLOB DEV_INC_FILES "${DEV_ROOT}/conf/*.h")


file(GLOB HAL_SRC_FILES "${HAL_ROOT}/Src/*.c")
set(DEV_SRC_FILES 
    "${DEV_ROOT}/sys/system_${STM32_TARGET_FAMILY_LOWER}xx.c"
    "${DEV_ROOT}/startup/startup_${STM32_TARGET_DEVICE_LOWER}.c"
)
set(STM32F4_HAL_SRC_FILES
    ${HAL_SRC_FILES}
    ${DEV_SRC_FILES}
)



# Create the output library
if(CMAKE_GENERATOR STREQUAL "Visual Studio 15 2017 ARM" OR
   CMAKE_GENERATOR STREQUAL "Visual Studio 15 2017 Win64" OR 
   CMAKE_GENERATOR STREQUAL "Visual Studio 14 2015 ARM" OR 
   CMAKE_GENERATOR STREQUAL "Visual Studio 14 2015 Win64"
  )
    source_group("Header Files\\CMSIS" FILES ${CMSIS_INC_FILES})
    source_group("Header Files\\HAL" FILES ${HAL_INC_FILES})
    source_group("Header Files\\Device" FILES ${DEV_INC_FILES})
    
    source_group("Source Files\\HAL" FILES ${HAL_SRC_FILES})
    source_group("Source Files\\Device" FILES ${DEV_SRC_FILES})

    add_library(${PROJECT_NAME} STATIC 
        ${HAL_SRC_FILES}
        ${DEV_SRC_FILES} 
        ${CMSIS_INC_FILES}
        ${HAL_INC_FILES}
        ${DEV_INC_FILES}
    )
endif()

if(CMAKE_GENERATOR STREQUAL "Unix Makefiles" OR CMAKE_GENERATOR STREQUAL "MinGW Makefiles")
    add_library(${PROJECT_NAME} STATIC ${HAL_SRC_FILES} ${DEV_SRC_FILES})
endif()


# Add the include directories, making sure other projects can see them
target_include_directories(${PROJECT_NAME} PUBLIC ${STM32F4_HAL_INC_DIRS})

# Add target/build specific compiler options
target_compile_options(${PROJECT_NAME} PRIVATE ${STM32F4_COMPILE_OPTIONS})
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-ggdb -Og>)
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:RELEASE>:-O3>)

# Add target/build specific definitions, making sure other projects can see them
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:DEBUG>: ${STM32F4_COMPILE_DEFINITIONS} -DDEBUG=1 -DDEBUG_DEFAULT_INTERRUPT_HANDLERS>)
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:RELEASE>: ${STM32F4_COMPILE_DEFINITIONS} -DNDEBUG=1 -DRELEASE=1>)