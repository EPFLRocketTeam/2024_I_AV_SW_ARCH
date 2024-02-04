# New CMake build file for Icarus
cmake_minimum_required(VERSION 3.22)

project(2024_I_AV_SW VERSION 0.1 LANGUAGES C CXX)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb")

# Library for Common Things
add_library(2024_I_AV_SW_COMMON include/common/system.hpp src/common/system.cpp include/common/fsm.hpp include/common/logger.hpp src/common/base_board.cpp include/common/base_board.hpp)
target_include_directories(2024_I_AV_SW_COMMON PUBLIC include/common)
# Library for the Teensy

add_library(2024_I_AV_SW_TEENSY src/teensy/teensy_board.cpp include/teensy/teensy_board.hpp include/teensy/teensy_data.hpp include/teensy/teensy_command.hpp include/teensy/teensy_output.hpp src/teensy/teensy_command.cpp src/teensy/teensy_command.cpp src/teensy/teensy_output.cpp src/teensy/teensy_data.cpp)
target_link_libraries(2024_I_AV_SW_TEENSY PUBLIC 2024_I_AV_SW_COMMON)
target_include_directories(2024_I_AV_SW_TEENSY PUBLIC include/teensy)

# Library for the RPI
add_library(2024_I_AV_SW_RPI src/rpi/rpi_board.cpp include/rpi/rpi_board.hpp src/rpi/rpi_data.cpp include/rpi/rpi_data.hpp include/rpi/rpi_command.hpp src/rpi/rpi_command.cpp include/rpi/rpi_output.hpp src/rpi/rpi_output.cpp)
target_link_libraries(2024_I_AV_SW_RPI PUBLIC 2024_I_AV_SW_COMMON)
target_include_directories(2024_I_AV_SW_RPI PUBLIC include/rpi)

# Defining tests
# enable_testing()
# add_test( NAME DUMMY  COMMAND $<TARGET_FILE:dummy>)
# set_tests_properties(DUMMY PROPERTIES TIMEOUT 5)