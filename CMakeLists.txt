# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# Pull in Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico-mcp2515 C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

set(PICO_CXX_ENABLE_RTTI 1)

# Initialise the Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(pico-can-read pico-can-read.cpp mcp2515.cpp)
add_executable(pico-can-write pico-can-write.cpp mcp2515.cpp)

pico_set_program_name(pico-can-read "pico-can-read")
pico_set_program_version(pico-can-read "0.1")

pico_enable_stdio_uart(pico-can-read 1)
pico_enable_stdio_usb(pico-can-read 0)

pico_set_program_name(pico-can-write "pico-can-write")
pico_set_program_version(pico-can-write "0.1")

pico_enable_stdio_uart(pico-can-write 1)
pico_enable_stdio_usb(pico-can-write 0)

# Add libraries
target_link_libraries(pico-can-read pico_stdlib hardware_spi)
target_link_libraries(pico-can-write pico_stdlib hardware_spi)

pico_add_extra_outputs(pico-can-read)
pico_add_extra_outputs(pico-can-write)
