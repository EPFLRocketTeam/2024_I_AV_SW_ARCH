# New CMake build file for Icarus
cmake_minimum_required(VERSION 3.22)

project(2024_I_AV_SW VERSION 0.1 LANGUAGES C CXX)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb")

# Library for Common Things
add_library(2024_I_AV_SW_COMMON include/common/system.hpp src/common/system.cpp include/common/fsm.hpp include/common/logger.hpp src/common/base_board.cpp include/common/base_board.hpp include/common/commands.hpp)
target_include_directories(2024_I_AV_SW_COMMON PUBLIC include/common)

# Library for the Teensy
add_library(2024_I_AV_SW_TEENSY src/teensy/teensy_board.cpp include/teensy/teensy_board.hpp include/teensy/teensy_paths.hpp include/teensy/teensy_control_path.hpp include/teensy/teensy_data_path.hpp src/teensy/teensy_control_path.cpp src/teensy/teensy_control_path.cpp src/teensy/teensy_data_path.cpp src/teensy/teensy_paths.cpp)
target_link_libraries(2024_I_AV_SW_TEENSY PUBLIC 2024_I_AV_SW_COMMON)
target_include_directories(2024_I_AV_SW_TEENSY PUBLIC include/teensy)

# Library for the RPI
add_library(2024_I_AV_SW_RPI src/rpi/rpi_board.cpp include/rpi/rpi_board.hpp src/rpi/rpi_paths.cpp include/rpi/rpi_paths.hpp include/rpi/rpi_control_path.hpp src/rpi/rpi_control_path.cpp include/rpi/rpi_data_path.hpp src/rpi/rpi_data_paths.cpp)
target_link_libraries(2024_I_AV_SW_RPI PUBLIC 2024_I_AV_SW_COMMON)
target_include_directories(2024_I_AV_SW_RPI PUBLIC include/rpi)

# Defining tests
# enable_testing()
# add_test( NAME DUMMY  COMMAND $<TARGET_FILE:dummy>)
# set_tests_properties(DUMMY PROPERTIES TIMEOUT 5)