cmake_minimum_required(VERSION 3.13)

project(HalStm32 LANGUAGES C ASM)

# Compute the family name
string(SUBSTRING ${HAL_STM32_MCU} 0 7 family)
string(APPEND family xx)

# Compute the upper hal mcu
string(TOUPPER ${HAL_STM32_MCU} hal_mcu_upper)
string(REPLACE X x hal_mcu_upper ${hal_mcu_upper})

add_library(HalStm32
    cmsis/src/${family}/system_stm32f1xx.c
    cmsis/src/${family}/${CMAKE_C_COMPILER_ID}/startup_${HAL_STM32_MCU}.s
    hal/src/${family}/legacy/stm32f1xx_hal_can.c
    hal/src/${family}/stm32f1xx_hal.c
    hal/src/${family}/stm32f1xx_hal_adc.c
    hal/src/${family}/stm32f1xx_hal_adc_ex.c
    hal/src/${family}/stm32f1xx_hal_can.c
    hal/src/${family}/stm32f1xx_hal_cec.c
    hal/src/${family}/stm32f1xx_hal_cortex.c
    hal/src/${family}/stm32f1xx_hal_crc.c
    hal/src/${family}/stm32f1xx_hal_dac.c
    hal/src/${family}/stm32f1xx_hal_dac_ex.c
    hal/src/${family}/stm32f1xx_hal_dma.c
    hal/src/${family}/stm32f1xx_hal_eth.c
    hal/src/${family}/stm32f1xx_hal_exti.c
    hal/src/${family}/stm32f1xx_hal_flash.c
    hal/src/${family}/stm32f1xx_hal_flash_ex.c
    hal/src/${family}/stm32f1xx_hal_gpio.c
    hal/src/${family}/stm32f1xx_hal_gpio_ex.c
    hal/src/${family}/stm32f1xx_hal_hcd.c
    hal/src/${family}/stm32f1xx_hal_i2c.c
    hal/src/${family}/stm32f1xx_hal_i2s.c
    hal/src/${family}/stm32f1xx_hal_irda.c
    hal/src/${family}/stm32f1xx_hal_iwdg.c
    hal/src/${family}/stm32f1xx_hal_mmc.c
    # hal/src/${family}/stm32f1xx_hal_msp_template.c
    hal/src/${family}/stm32f1xx_hal_nand.c
    hal/src/${family}/stm32f1xx_hal_nor.c
    hal/src/${family}/stm32f1xx_hal_pccard.c
    hal/src/${family}/stm32f1xx_hal_pcd.c
    hal/src/${family}/stm32f1xx_hal_pcd_ex.c
    hal/src/${family}/stm32f1xx_hal_pwr.c
    hal/src/${family}/stm32f1xx_hal_rcc.c
    hal/src/${family}/stm32f1xx_hal_rcc_ex.c
    hal/src/${family}/stm32f1xx_hal_rtc.c
    hal/src/${family}/stm32f1xx_hal_rtc_ex.c
    hal/src/${family}/stm32f1xx_hal_sd.c
    hal/src/${family}/stm32f1xx_hal_smartcard.c
    hal/src/${family}/stm32f1xx_hal_spi.c
    hal/src/${family}/stm32f1xx_hal_sram.c
    hal/src/${family}/stm32f1xx_hal_tim.c
    # hal/src/${family}/stm32f1xx_hal_timebase_rtc_alarm_template.c
    # hal/src/${family}/stm32f1xx_hal_timebase_tim_template.c
    hal/src/${family}/stm32f1xx_hal_tim_ex.c
    hal/src/${family}/stm32f1xx_hal_uart.c
    hal/src/${family}/stm32f1xx_hal_usart.c
    hal/src/${family}/stm32f1xx_hal_wwdg.c
    hal/src/${family}/stm32f1xx_ll_adc.c
    hal/src/${family}/stm32f1xx_ll_crc.c
    hal/src/${family}/stm32f1xx_ll_dac.c
    hal/src/${family}/stm32f1xx_ll_dma.c
    hal/src/${family}/stm32f1xx_ll_exti.c
    hal/src/${family}/stm32f1xx_ll_fsmc.c
    hal/src/${family}/stm32f1xx_ll_gpio.c
    hal/src/${family}/stm32f1xx_ll_i2c.c
    hal/src/${family}/stm32f1xx_ll_pwr.c
    hal/src/${family}/stm32f1xx_ll_rcc.c
    hal/src/${family}/stm32f1xx_ll_rtc.c
    hal/src/${family}/stm32f1xx_ll_sdmmc.c
    hal/src/${family}/stm32f1xx_ll_spi.c
    hal/src/${family}/stm32f1xx_ll_tim.c
    hal/src/${family}/stm32f1xx_ll_usart.c
    hal/src/${family}/stm32f1xx_ll_usb.c
    hal/src/${family}/stm32f1xx_ll_utils.c
)

target_link_options(HalStm32
    INTERFACE
        $<$<STREQUAL:${CMAKE_C_COMPILER_ID},GNU>:-T ${CMAKE_CURRENT_SOURCE_DIR}/cmsis/src/${family}/${CMAKE_C_COMPILER_ID}/linker/${HAL_STM32_MCU}.ld>
)

target_include_directories(HalStm32
    PUBLIC
        cmsis/include
        cmsis/include/${family}
        hal/include
        hal/include/${family}
        hal/include/${family}/legacy
)

target_compile_definitions(HalStm32
    PUBLIC
        ${hal_mcu_upper}
)

add_library(HalStm32::HalStm32 ALIAS HalStm32)
