# New CMake build file for Icarus
cmake_minimum_required(VERSION 3.22)

project(2024_I_AV_SW VERSION 0.1 LANGUAGES C CXX)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb")

# Library for Common Things
add_library(2024_I_AV_SW_COMMON include/common/core/system.hpp src/common/core/system.cpp include/common/core/fsm.hpp include/common/logger.hpp src/common/core/base_board.cpp include/common/core/base_board.hpp include/common/modifier/command_handler.hpp src/common/modifier/command_handler.cpp include/common/types.hpp include/common/core/data/base_data_component.hpp include/common/core/data/base_intranet.hpp include/common/config.hpp)
target_include_directories(2024_I_AV_SW_COMMON PUBLIC include/common)

# Library for the Teensy
add_library(2024_I_AV_SW_TEENSY include/teensy/base_teensy_board.hpp include/teensy/teensy_intranet.hpp)
target_link_libraries(2024_I_AV_SW_TEENSY PUBLIC 2024_I_AV_SW_COMMON)
target_include_directories(2024_I_AV_SW_TEENSY PUBLIC include/teensy)

# Library for the RPI
add_library(2024_I_AV_SW_RPI include/rpi/rpi_intranet.hpp include/rpi/rpi_telecom.hpp include/rpi/base_rpi_board.hpp include/rpi/base_rpi_board.hpp)
target_link_libraries(2024_I_AV_SW_RPI PUBLIC 2024_I_AV_SW_COMMON)
target_include_directories(2024_I_AV_SW_RPI PUBLIC include/rpi)

# Defining tests
enable_testing()

add_executable(CREATE_RPI_BOARD_TEST test/create_rpi_board_test.cpp)
target_link_libraries(CREATE_RPI_BOARD_TEST PUBLIC 2024_I_AV_SW_RPI)

add_test(NAME CREATE_RPI_BOARD_TEST COMMAND $<TARGET_FILE:CREATE_RPI_BOARD_TEST>)
set_tests_properties(CREATE_RPI_BOARD_TEST PROPERTIES TIMEOUT 5)

add_executable(CREATE_TEENSY_BOARD_TEST test/create_teensy_board_test.cpp)
target_link_libraries(CREATE_TEENSY_BOARD_TEST PUBLIC 2024_I_AV_SW_TEENSY)

add_test(NAME CREATE_TEENSY_BOARD_TEST COMMAND $<TARGET_FILE:CREATE_TEENSY_BOARD_TEST>)
set_tests_properties(CREATE_TEENSY_BOARD_TEST PROPERTIES TIMEOUT 5)