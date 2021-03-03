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

add_executable(pico-mcp2515 main.cpp mcp2515.cpp)

pico_set_program_name(pico-mcp2515 "pico-mcp2515")
pico_set_program_version(pico-mcp2515 "0.1")

pico_enable_stdio_uart(pico-mcp2515 1)
pico_enable_stdio_usb(pico-mcp2515 0)

# Add libraries
target_link_libraries(pico-mcp2515 pico_stdlib hardware_spi)

pico_add_extra_outputs(pico-mcp2515)

