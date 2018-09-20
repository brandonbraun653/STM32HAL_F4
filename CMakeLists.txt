cmake_minimum_required(VERSION 3.12.2)

# --------------------------------------
# Grab any global properties needed 
# --------------------------------------
get_property(STM32_CMAKE_TOOLS GLOBAL PROPERTY STM32_CMAKE_TOOLS_DIR)
get_property(STM32_DEVICE_FAMILY GLOBAL PROPERTY STM32_DEVICE_FAMILY)
get_property(STM32_DEVICE_ID GLOBAL PROPERTY STM32_DEVICE_ID)
get_property(STM32F4_COMPILER_OPTIONS GLOBAL PROPERTY STM32_COMPILER_OPTIONS)

if(NOT "${STM32_CMAKE_TOOLS}" STREQUAL "")
    include("${STM32_CMAKE_TOOLS}/gcc_stm32.cmake")
    include("${STM32_CMAKE_TOOLS}/gcc_stm32f4.cmake")
    message(STATUS "STM32F4: Found STM32 CMake Tools")
else()
    message(FATAL_ERROR "Could not find STM32_CMAKE_TOOLS")
endif()

# Generate the correct device id for compiler definitions
string(TOUPPER ${STM32_DEVICE_ID} STM32_DEVICE_ID)
string(REPLACE "XX" "xx" STM32_DEVICE_ID ${STM32_DEVICE_ID})

set(STM32F4_COMPILE_DEFINITIONS
    -DUSE_FULL_LL_DRIVER
    -D${STM32_DEVICE_ID}
)

# --------------------------------------
# Define directories
# --------------------------------------
set(CMSIS_ROOT "${CMAKE_CURRENT_LIST_DIR}/CMSIS")
set(HAL_ROOT "${CMAKE_CURRENT_LIST_DIR}/STM32${STM32_DEVICE_FAMILY}xx_HAL_Driver")
set(DEV_ROOT "${CMAKE_CURRENT_LIST_DIR}/Device")

set(STM32F4_HAL_INC_DIRS 
    "${HAL_ROOT}/Inc"
    "${DEV_ROOT}/conf"
    "${CMSIS_ROOT}/Include" 
    "${CMSIS_ROOT}/Device/ST/STM32${STM32_DEVICE_FAMILY}xx/Include"
    CACHE STRING "STM32F4_HAL_INC_DIRS"
)

# --------------------------------------
# Grab all the needed .h and .c files
# --------------------------------------
file(GLOB CMSIS_INC_1 "${CMSIS_ROOT}/Include/*.h")
file(GLOB CMSIS_INC_2 "${CMSIS_ROOT}/Device/ST/STM32${STM32_DEVICE_FAMILY}xx/Include/*.h")
set(CMSIS_INC_FILES ${CMSIS_INC_1} ${CMSIS_INC_2})
file(GLOB HAL_INC_FILES "${HAL_ROOT}/Inc/*.h")
file(GLOB DEV_INC_FILES "${DEV_ROOT}/conf/*.h")

file(GLOB HAL_SRC_FILES "${HAL_ROOT}/Src/*.c")
set(DEV_SRC_FILES 
    "${DEV_ROOT}/sys/system_stm32f4xx.c"
    "${DEV_ROOT}/startup/startup_${STM32_DEVICE_ID}.c"
)
set(STM32F4_HAL_SRC_FILES
    ${HAL_SRC_FILES}
    ${DEV_SRC_FILES}
)

# --------------------------------------
# Define the project
# --------------------------------------
project(STM32F4_HAL)

if(CMAKE_GENERATOR STREQUAL "Unix Makefiles" OR CMAKE_GENERATOR STREQUAL "MinGW Makefiles")
    add_library(${PROJECT_NAME} STATIC ${HAL_SRC_FILES} ${DEV_SRC_FILES})
endif()

# Add the include directories, making sure other projects can see them
target_include_directories(${PROJECT_NAME} PUBLIC ${STM32F4_HAL_INC_DIRS})

# Add target/build specific compiler options
target_compile_options(${PROJECT_NAME} PRIVATE ${STM32F4_COMPILER_OPTIONS} --std=gnu11)
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-ggdb -Og>)
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:RELEASE>:-O3>)

# Add target/build specific definitions, making sure other projects can see them
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>: ${STM32F4_COMPILE_DEFINITIONS} -DDEBUG=1 -DDEBUG_DEFAULT_INTERRUPT_HANDLERS>)
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:RELEASE>: ${STM32F4_COMPILE_DEFINITIONS} -DNDEBUG=1 -DRELEASE=1>)