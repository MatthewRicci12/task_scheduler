cmake_minimum_required(VERSION 3.15)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arm-toolchain.cmake)
project(project_1 C CXX ASM)

set(CMAKE_CXX_STANDARD 14)
set(FREERTOS_PORT GCC_ARM_CM4F CACHE STRING "")
set(FREERTOS_HEAP 4 CACHE STRING "")

# Tell the kernel where your FreeRTOSConfig.h lives
add_library(freertos_config INTERFACE)
target_include_directories(freertos_config SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(FreeRTOS-Kernel)

# FreeRTOSConfig.h at end optional, just makes CLion happy.
# Wire up startup file and linker.
add_executable(project_1
        src/main.cpp
        FreeRTOSConfig.h
        startup_stm32f405xx.s
)

target_link_options(project_1 PRIVATE
        -T${CMAKE_SOURCE_DIR}/STM32F405RGTx_FLASH.ld
        -Wl,--gc-sections
        -Wl,-Map=${CMAKE_BINARY_DIR}/project_1.map
        -nostdlib
)

target_link_libraries(project_1 PRIVATE
        freertos_kernel
        -lgcc
        -specs=nosys.specs
        -specs=nano.specs
)