cmake_minimum_required(VERSION 3.13)

if (NOT PICO_SDK_PATH AND NOT DEFINED ENV{PICO_SDK_PATH})
    set(PICO_SDK_PATH "${CMAKE_CURRENT_LIST_DIR}/deps/pico-sdk" CACHE PATH "Path to the Raspberry Pi Pico SDK")
endif()

set(PICO_BOARD pico2_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(my_project C CXX ASM)

pico_sdk_init()

# ------------------------
# Executables
# ------------------------
add_executable(hello_pico
    src/main.c
)

add_executable(blink
    src/blink.c
)

add_executable(lcd_1602_i2c
    src/lcd_1602_i2c.c
)

add_executable(dht
    src/dht.c
)

add_executable(cds
    src/cds.c
)

add_executable(cds1
    src/cds1.c
)

add_executable(project0
    src/project0.c
)

add_executable(project1
    src/project1.c
)

# ------------------------
# Libraries
# ------------------------
target_link_libraries(hello_pico
    pico_stdlib
    hardware_i2c
    hardware_gpio
)

target_link_libraries(blink
    pico_stdlib
)

target_link_libraries(lcd_1602_i2c
    pico_stdlib
    hardware_i2c
    hardware_gpio
)

target_link_libraries(dht
    pico_stdlib
    hardware_gpio
)

target_link_libraries(cds
    pico_stdlib
    hardware_i2c
    hardware_gpio
    hardware_adc
)

target_link_libraries(cds1
    pico_stdlib
    hardware_i2c
    hardware_gpio
    hardware_adc
)

target_link_libraries(project0
    pico_stdlib
    hardware_gpio
    hardware_adc
)

target_link_libraries(project1
    pico_stdlib
    hardware_gpio
    hardware_adc
)

if (PICO_CYW43_SUPPORTED)
    target_link_libraries(blink
        pico_cyw43_arch_none
    )
endif()

# ------------------------
# USB / UART stdio
# ------------------------
pico_enable_stdio_usb(hello_pico 1)
pico_enable_stdio_uart(hello_pico 0)

pico_enable_stdio_usb(cds1 1)
pico_enable_stdio_uart(cds1 0)

pico_enable_stdio_usb(project0 1)
pico_enable_stdio_uart(project0 0)

pico_enable_stdio_usb(project1 1)
pico_enable_stdio_uart(project1 0)


# ------------------------
# Extra outputs
# ------------------------
pico_add_extra_outputs(hello_pico)
pico_add_extra_outputs(blink)
pico_add_extra_outputs(lcd_1602_i2c)
pico_add_extra_outputs(dht)
pico_add_extra_outputs(cds)
pico_add_extra_outputs(cds1)
pico_add_extra_outputs(project0)
pico_add_extra_outputs(project1)