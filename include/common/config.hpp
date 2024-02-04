//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_CONFIG_HPP
#define INC_2024_I_AV_SW_CONFIG_HPP

#include <cstdint>

enum TeensyCommandID: uint8_t {
	TEENSY_CMD_NONE = 0x00,
	TEENSY_CMD_STATE = 0x01,
};

enum RpiCommandID: uint8_t {
	RPI_CMD_NONE = 0x00,
	RPI_CMD_STATE = 0x01,
};


#endif //INC_2024_I_AV_SW_CONFIG_HPP
