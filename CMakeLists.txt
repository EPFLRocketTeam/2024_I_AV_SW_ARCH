# New CMake build file for Icarus
cmake_minimum_required(VERSION 3.22)

project(2024_I_AV_SW VERSION 0.1 LANGUAGES C CXX)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb")

# Library for Common Things
add_library(2024_I_AV_SW_COMMON include/common/core/system.hpp src/common/core/system.cpp include/common/core/fsm.hpp include/common/logger.hpp src/common/core/base_board.cpp include/common/core/base_board.hpp include/common/channel/modifier/command_handler.hpp src/common/channel/modifier/command_handler.cpp include/common/types.hpp include/common/channel/base_data_channel.hpp include/common/channel/base_intranet_channel.hpp include/common/channel/circular_buffer.hpp src/common/channel/base_intranet_channel.cpp)
target_include_directories(2024_I_AV_SW_COMMON PUBLIC include/common)

# Library for the RPI
add_library(2024_I_AV_SW_RPI include/rpi/base_rpi_board.hpp)
target_link_libraries(2024_I_AV_SW_RPI PUBLIC 2024_I_AV_SW_COMMON)
target_include_directories(2024_I_AV_SW_RPI PUBLIC include/rpi)

# Library for the Teensy
add_library(2024_I_AV_SW_TEENSY include/teensy/base_teensy_board.hpp include/teensy/base_teensy_telecom.hpp
        include/teensy/base_teensy_sensors.hpp)
target_link_libraries(2024_I_AV_SW_TEENSY PUBLIC 2024_I_AV_SW_COMMON)
target_include_directories(2024_I_AV_SW_TEENSY PUBLIC include/teensy)


# Defining tests
enable_testing()

add_executable(DEMO_TEENSY_MASTER test/demo_teensy_master.cpp)
target_link_libraries(DEMO_TEENSY_MASTER PUBLIC 2024_I_AV_SW_TEENSY)

add_test(NAME DEMO_TEENSY_MASTER COMMAND $<TARGET_FILE:DEMO_TEENSY_MASTER>)
set_tests_properties(DEMO_TEENSY_MASTER PROPERTIES TIMEOUT 5)

add_executable(DEMO_RPI_SLAVE test/demo_rpi_slave.cpp)
target_link_libraries(DEMO_RPI_SLAVE PUBLIC 2024_I_AV_SW_RPI)

add_test(NAME DEMO_RPI_SLAVE COMMAND $<TARGET_FILE:DEMO_RPI_SLAVE>)
set_tests_properties(DEMO_RPI_SLAVE PROPERTIES TIMEOUT 5)
