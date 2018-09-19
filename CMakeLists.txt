cmake_minimum_required(VERSION 3.12.2)
if(${STM32_CMAKE_TOOLS_DIR})
    include("${STM32_CMAKE_TOOLS_DIR}/gcc_stm32.cmake")
else()
    message(FATAL_ERROR "Could not find STM32_CMAKE_TOOLS_DIR")
endif()


project(STM32F4_HAL)

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
    CACHE STRING "STM32F4_HAL_INC_DIRS"
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



## TODO: Currently doesn't actually build in VS...need to figure something out
# Create the output library
# if(CMAKE_GENERATOR STREQUAL "Visual Studio 15 2017 ARM" OR
#    CMAKE_GENERATOR STREQUAL "Visual Studio 15 2017 Win64" OR 
#    CMAKE_GENERATOR STREQUAL "Visual Studio 14 2015 ARM" OR 
#    CMAKE_GENERATOR STREQUAL "Visual Studio 14 2015 Win64"
#   )
#     source_group("Header Files\\CMSIS" FILES ${CMSIS_INC_FILES})
#     source_group("Header Files\\HAL" FILES ${HAL_INC_FILES})
#     source_group("Header Files\\Device" FILES ${DEV_INC_FILES})
    
#     source_group("Source Files\\HAL" FILES ${HAL_SRC_FILES})
#     source_group("Source Files\\Device" FILES ${DEV_SRC_FILES})

#     add_library(${PROJECT_NAME} STATIC 
#         ${HAL_SRC_FILES}
#         ${DEV_SRC_FILES} 
#         ${CMSIS_INC_FILES}
#         ${HAL_INC_FILES}
#         ${DEV_INC_FILES}
#     )
# endif()

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