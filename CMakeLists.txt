# New CMake build file for Icarus
cmake_minimum_required(VERSION 3.22)

project(2024_I_AV_SW VERSION 0.1 LANGUAGES C CXX)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb")

# Library for Common Things
add_library(2024_I_AV_SW_COMMON include/common/system.hpp src/common/system.cpp include/common/fsm.hpp include/common/logger.hpp src/common/base_board.cpp include/common/base_board.hpp include/common/data/base_intranet.hpp src/common/data/base_intranet.cpp include/common/modifier/command_receiver.hpp src/common/modifier/command_receiver.cpp include/common/config.hpp)
target_include_directories(2024_I_AV_SW_COMMON PUBLIC include/common)

# Library for the Teensy
add_library(2024_I_AV_SW_TEENSY src/teensy/teensy_board.cpp include/teensy/teensy_board.hpp include/teensy/teensy_intranet.hpp src/teensy/teensy_intranet.cpp src/teensy/teensy_data.cpp include/teensy/teensy_data.hpp include/rpi/rpi_data.hpp src/teensy/teensy_sensors.cpp include/teensy/teensy_sensors.hpp)
target_link_libraries(2024_I_AV_SW_TEENSY PUBLIC 2024_I_AV_SW_COMMON)
target_include_directories(2024_I_AV_SW_TEENSY PUBLIC include/teensy)

# Library for the RPI
add_library(2024_I_AV_SW_RPI src/rpi/rpi_board.cpp include/rpi/rpi_board.hpp src/rpi/rpi_intranet.cpp include/rpi/rpi_intranet.hpp include/rpi/rpi_telecom.hpp src/rpi/rpi_telecom.cpp src/rpi/rpi_data.cpp)
target_link_libraries(2024_I_AV_SW_RPI PUBLIC 2024_I_AV_SW_COMMON)
target_include_directories(2024_I_AV_SW_RPI PUBLIC include/rpi)

# Defining tests
# enable_testing()
# add_test( NAME DUMMY  COMMAND $<TARGET_FILE:dummy>)
# set_tests_properties(DUMMY PROPERTIES TIMEOUT 5)