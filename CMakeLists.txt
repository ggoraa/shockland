cmake_minimum_required(VERSION 3.16)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
 
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
# set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_ASM_FLAGS "${CFLAGS} -x assembler-with-cpp")
set(CMAKE_CXX_FLAGS "-Wno-volatile")
 
project(Shockland LANGUAGES C CXX ASM VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-O0 -g)
endif ()

set(CPU cortex-m3)
set(MCU STM32F103xB)

file(GLOB SOURCES
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_adc.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_adc_ex.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.c"
    "Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.c"
    "Core/Src/*.c"
    "startup_stm32f103xb.s"
)

set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/STM32F103C8Tx_FLASH.ld)

add_compile_options(-mcpu=${CPU} -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0)

add_compile_definitions(USE_HAL_DRIVER ${MCU})

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/shockland.map)
add_link_options(-specs=nosys.specs -lstdc++ -mcpu=${CPU} -mthumb -mthumb-interwork -T ${LINKER_SCRIPT})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F1xx_HAL_Driver/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32F1xx/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Include
)

# link_libraries(
#     ${CMAKE_SOURCE_DIR}/STM32_Cryptographic/lib/libSTM32Cryptographic_CM3.a
# )

add_executable(shockland.elf ${SOURCES} ${LINKER_SCRIPT})

set(HEX_FILE ${PROJECT_BINARY_DIR}/shockland.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/shockland.bin)

add_custom_command(TARGET shockland.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:shockland.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:shockland.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")