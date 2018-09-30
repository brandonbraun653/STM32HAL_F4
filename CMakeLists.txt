cmake_minimum_required(VERSION 3.12.2)

# --------------------------------------
# Properties for this file
# --------------------------------------
set(STM32_FAMILY "F4")
set(HAL_VERSION "1.21.0")
set(PRJ_ROOT "${CMAKE_CURRENT_LIST_DIR}")

if(NOT INSTALL_CMAKE_DIR)
    if(WIN32)
        set(INSTALL_CMAKE_DIR "C:/CMakeModules/stm32hal_f4/${HAL_VERSION}")
    elseif(UNIX)
        set(INSTALL_CMAKE_DIR "/home/$ENV{USER}/CMakeModules/stm32hal_f4/${HAL_VERSION}")
    else()
        message(WARNING "No install directory is set! You will be able to build locally but not install.")
    endif()
endif()

# --------------------------------------
# Pull the STM32 toolchain and some needed functions
# --------------------------------------
include("${PRJ_ROOT}/stm32-cmake/cmake/gcc_stm32.cmake")
include("${PRJ_ROOT}/stm32-cmake/cmake/gcc_stm32f4.cmake")
include("${PRJ_ROOT}/stm32-cmake/cmake/toolchain.cmake")

# --------------------------------------
# Define directories. These are relative on purpose so that the install command
# can prepend the INSTALL_PREFIX to it. 
# --------------------------------------
set(STM32_INC_DIR "STM32F4xx_HAL_Driver/Inc")
set(STM32_SRC_DIR "STM32F4xx_HAL_Driver/Src")
set(STM32_LEGACY_INC_DIR "STM32F4xx_HAL_Driver/Inc/Legacy")
set(STM32_LEGACY_SRC_DIR "STM32F4xx_HAL_Driver/Src/Legacy")
set(DEVICE_INC_DIR "Device/conf")
set(CMSIS_INC_DIR "CMSIS/Include")
set(CMSIS_DEVICE_INC_DIR "CMSIS/Device/ST/STM32F4xx/Include")

# --------------------------------------
# Grab all the needed .c files. These are used for the compiler to build 
# all the supported static libraries.
# --------------------------------------
set(HAL_SRC_FILES 
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_adc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_adc_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_can.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_cec.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_cortex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_crc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_cryp.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_cryp_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_dac.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_dac_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_dcmi.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_dcmi_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_dfsdm.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_dma.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_dma2d.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_dma_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_dsi.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_eth.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_flash.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_flash_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_flash_ramfunc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_fmpi2c.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_fmpi2c_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_gpio.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_hash.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_hash_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_hcd.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_i2c.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_i2c_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_i2s.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_i2s_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_irda.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_iwdg.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_lptim.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_ltdc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_ltdc_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_mmc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_nand.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_nor.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_pccard.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_pcd.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_pcd_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_pwr.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_pwr_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_qspi.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_rcc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_rcc_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_rng.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_rtc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_rtc_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_sai.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_sai_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_sd.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_sdram.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_smartcard.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_spdifrx.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_spi.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_sram.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_tim.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_tim_ex.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_uart.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_usart.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_hal_wwdg.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_adc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_crc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_dac.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_dma.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_dma2d.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_exti.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_fmc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_fsmc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_gpio.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_i2c.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_lptim.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_pwr.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_rcc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_rng.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_rtc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_sdmmc.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_spi.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_tim.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_usart.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_usb.c"
    "${PRJ_ROOT}/${STM32_SRC_DIR}/stm32f4xx_ll_utils.c"
)

# --------------------------------------
# These .c files are found inside of "gcc_stm32f4.cmake" since they depend 
# on the chip name, but are listed here for the sake of clarity.
# --------------------------------------
# set(DEV_SRC_FILES 
#     "${PRJ_ROOT}/Device/sys/system_stm32f4xx.c"
#     "${PRJ_ROOT}/Device/startup/startup_stm32f${PROJECT_CHIP_TYPE}.c"
# )

set(STM32_HAL_SRC_FILES ${HAL_SRC_FILES}) # ${DEV_SRC_FILES}

# --------------------------------------
# Grab all the needed .h files. This is for the purpose of installing all the 
# targets into the INSTALL_CMAKE_DIR and need to be relative paths.
# --------------------------------------
set(HAL_INC_FILES
    "${STM32_INC_DIR}/stm32f4xx_hal.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_adc.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_adc_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_can.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_cec.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_cortex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_crc.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_cryp.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_cryp_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_dac.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_dac_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_dcmi.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_dcmi_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_def.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_dfsdm.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_dma.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_dma2d.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_dma_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_dsi.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_eth.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_flash.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_flash_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_flash_ramfunc.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_fmpi2c.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_fmpi2c_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_gpio.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_gpio_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_hash.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_hash_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_hcd.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_i2c.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_i2c_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_i2s.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_i2s_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_irda.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_iwdg.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_lptim.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_ltdc.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_ltdc_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_mmc.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_nand.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_nor.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_pccard.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_pcd.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_pcd_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_pwr.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_pwr_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_qspi.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_rcc.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_rcc_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_rng.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_rtc.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_rtc_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_sai.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_sai_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_sd.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_sdram.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_smartcard.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_spdifrx.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_spi.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_sram.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_tim.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_tim_ex.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_uart.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_usart.h"
    "${STM32_INC_DIR}/stm32f4xx_hal_wwdg.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_adc.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_bus.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_cortex.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_crc.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_dac.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_dma.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_dma2d.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_exti.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_fmc.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_fsmc.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_gpio.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_i2c.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_iwdg.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_lptim.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_pwr.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_rcc.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_rng.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_rtc.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_sdmmc.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_spi.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_system.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_tim.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_usart.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_usb.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_utils.h"
    "${STM32_INC_DIR}/stm32f4xx_ll_wwdg.h"
)

set(HAL_LEGACY_INC_FILES
    "${STM32_LEGACY_INC_DIR}/stm32_hal_legacy.h"
    "${STM32_LEGACY_INC_DIR}/stm32f4xx_hal_can_legacy.h"
)

set(DEV_INC_FILES
    "${DEVICE_INC_DIR}/stm32f4xx_hal_conf.h"
)

set(CMSIS_INC_FILES
    "${CMSIS_INC_DIR}/arm_common_tables.h"
    "${CMSIS_INC_DIR}/arm_const_structs.h"
    "${CMSIS_INC_DIR}/arm_math.h"
    "${CMSIS_INC_DIR}/cmsis_armcc.h"
    "${CMSIS_INC_DIR}/cmsis_armcc_V6.h"
    "${CMSIS_INC_DIR}/cmsis_gcc.h"
    "${CMSIS_INC_DIR}/core_cm0.h"
    "${CMSIS_INC_DIR}/core_cm0plus.h"
    "${CMSIS_INC_DIR}/core_cm3.h"
    "${CMSIS_INC_DIR}/core_cm4.h"
    "${CMSIS_INC_DIR}/core_cm7.h"
    "${CMSIS_INC_DIR}/core_cmFunc.h"
    "${CMSIS_INC_DIR}/core_cmInstr.h"
    "${CMSIS_INC_DIR}/core_cmSimd.h"
    "${CMSIS_INC_DIR}/core_sc000.h"
    "${CMSIS_INC_DIR}/core_sc300.h"
)

set(CMSIS_DEVICE_INC_FILES
    "${CMSIS_DEVICE_INC_DIR}/stm32f401xc.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f401xe.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f405xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f407xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f410cx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f410rx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f410tx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f411xe.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f412cx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f412rx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f412vx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f412zx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f413xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f415xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f417xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f423xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f427xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f429xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f437xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f439xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f446xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f469xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f479xx.h"
    "${CMSIS_DEVICE_INC_DIR}/stm32f4xx.h"
    "${CMSIS_DEVICE_INC_DIR}/system_stm32f4xx.h"
)

# --------------------------------------
# Set the include directories for both install and build
# --------------------------------------
# This is for local builds
set(STM32_HAL_BUILD_INC_DIRS 
    "${PRJ_ROOT}/${STM32_INC_DIR}"
    "${PRJ_ROOT}/${STM32_LEGACY_INC_DIR}"
    "${PRJ_ROOT}/${DEVICE_INC_DIR}"
    "${PRJ_ROOT}/${CMSIS_INC_DIR}" 
    "${PRJ_ROOT}/${CMSIS_DEVICE_INC_DIR}"
)

# These are for the install command
set(STM32_HAL_INSTALL_INC_DIRS
    "${INSTALL_CMAKE_DIR}/${STM32_INC_DIR}"
    "${INSTALL_CMAKE_DIR}/${STM32_LEGACY_INC_DIR}"
    "${INSTALL_CMAKE_DIR}/${DEVICE_INC_DIR}"
    "${INSTALL_CMAKE_DIR}/${CMSIS_INC_DIR}" 
    "${INSTALL_CMAKE_DIR}/${CMSIS_DEVICE_INC_DIR}"
)

# --------------------------------------
# Define the project
# --------------------------------------
project(STM32F4_HAL LANGUAGES C)

# Generates targets/libraries for every supported chip and sets up the export installation definitions.
# Additionally, generates two targets that build all debug/release static libraries locally. This
# is useful for integration systems like Jenkins.
STM32F4_GENERATE_ALL_TARGETS(
    "${PRJ_ROOT}"
    "${STM32_HAL_SRC_FILES}" 
    "${STM32_HAL_BUILD_INC_DIRS}" 
    "${STM32_HAL_INSTALL_INC_DIRS}"
)

# Install the header files for use with find_package()
install(FILES ${HAL_INC_FILES} DESTINATION ${INSTALL_CMAKE_DIR}/${STM32_INC_DIR})
install(FILES ${HAL_LEGACY_INC_FILES} DESTINATION ${INSTALL_CMAKE_DIR}/${STM32_LEGACY_INC_DIR})
install(FILES ${DEV_INC_FILES} DESTINATION ${INSTALL_CMAKE_DIR}/${DEVICE_INC_DIR})
install(FILES ${CMSIS_INC_FILES} DESTINATION ${INSTALL_CMAKE_DIR}/${CMSIS_INC_DIR})
install(FILES ${CMSIS_DEVICE_INC_FILES} DESTINATION ${INSTALL_CMAKE_DIR}/${CMSIS_DEVICE_INC_DIR})