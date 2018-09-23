cmake_minimum_required(VERSION 3.12.2)

# --------------------------------------
# Grab any global properties needed 
# --------------------------------------
get_property(STM32_CMAKE_TOOLS GLOBAL PROPERTY STM32_CMAKE_TOOLS_DIR)
get_property(STM32_DEVICE_FAMILY GLOBAL PROPERTY STM32_DEVICE_FAMILY)
get_property(STM32_HAL_DEVICE_DEFINITION GLOBAL PROPERTY STM32_HAL_DEVICE_DEFINITION)
get_property(STM32F4_COMPILER_OPTIONS GLOBAL PROPERTY STM32_COMPILER_OPTIONS)

if(NOT "${STM32_CMAKE_TOOLS}" STREQUAL "")
    include("${STM32_CMAKE_TOOLS}/gcc_stm32.cmake")
    include("${STM32_CMAKE_TOOLS}/gcc_stm32f4.cmake")
    message(STATUS "STM32F4: Found STM32 CMake Tools")
else()
    message(FATAL_ERROR "Could not find STM32_CMAKE_TOOLS")
endif()

set(STM32F4_COMPILER_DEFINITIONS
    -DUSE_FULL_LL_DRIVER
    -D${STM32_HAL_DEVICE_DEFINITION}
)
set(STM32F4_COMPILER_DEFINITIONS ${STM32F4_COMPILER_DEFINITIONS} $<$<CONFIG:DEBUG>: -DDEBUG_DEFAULT_INTERRUPT_HANDLERS>)
set(STM32F4_COMPILER_DEFINITIONS ${STM32F4_COMPILER_DEFINITIONS} $<$<CONFIG:RELEASE>: >)
set_property(GLOBAL PROPERTY STM32_HAL_COMPILER_DEFINITIONS "${STM32F4_COMPILER_DEFINITIONS}")

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
)
set_property(GLOBAL PROPERTY STM32_HAL_INC_DIRS "${STM32F4_HAL_INC_DIRS}")

# --------------------------------------
# Grab all the needed .c files
# --------------------------------------
set(HAL_SRC_FILES 
    "${HAL_ROOT}/Src/stm32f4xx_hal.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_adc.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_adc_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_can.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_cec.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_cortex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_crc.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_cryp.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_cryp_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_dac.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_dac_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_dcmi.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_dcmi_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_dfsdm.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_dma.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_dma2d.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_dma_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_dsi.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_eth.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_flash.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_flash_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_flash_ramfunc.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_fmpi2c.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_fmpi2c_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_gpio.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_hash.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_hash_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_hcd.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_i2c.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_i2c_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_i2s.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_i2s_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_irda.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_iwdg.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_lptim.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_ltdc.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_ltdc_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_mmc.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_nand.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_nor.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_pccard.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_pcd.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_pcd_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_pwr.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_pwr_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_qspi.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_rcc.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_rcc_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_rng.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_rtc.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_rtc_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_sai.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_sai_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_sd.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_sdram.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_smartcard.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_spdifrx.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_spi.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_sram.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_tim.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_tim_ex.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_uart.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_usart.c"
    "${HAL_ROOT}/Src/stm32f4xx_hal_wwdg.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_adc.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_crc.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_dac.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_dma.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_dma2d.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_exti.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_fmc.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_fsmc.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_gpio.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_i2c.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_lptim.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_pwr.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_rcc.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_rng.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_rtc.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_sdmmc.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_spi.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_tim.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_usart.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_usb.c"
    "${HAL_ROOT}/Src/stm32f4xx_ll_utils.c"
)

string(TOLOWER "${STM32_HAL_DEVICE_DEFINITION}" STM32_HAL_DEVICE_DEFINITION_LOWER)
set(DEV_SRC_FILES 
    "${DEV_ROOT}/sys/system_stm32f4xx.c"
    "${DEV_ROOT}/startup/startup_${STM32_HAL_DEVICE_DEFINITION_LOWER}.c"
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
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>: ${STM32F4_COMPILER_DEFINITIONS} -DDEBUG=1>)
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:RELEASE>: ${STM32F4_COMPILER_DEFINITIONS} -DNDEBUG=1 -DRELEASE=1>)