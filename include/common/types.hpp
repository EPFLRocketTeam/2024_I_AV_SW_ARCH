//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TYPES_HPP
#define INC_2024_I_AV_SW_TYPES_HPP

#include <cstdint>

typedef uint32_t time_millis_t;

enum CommandID: uint8_t {
	// COMMANDS TO ICARUS AV
	CMD_NONE = 0x00,
	CMD_AV_STATE = 0x01,

	// COMMANDS TO PROPULSION SYSTEM
	CMD_PR_VENT_N2O = 0x11,
	CMD_PR_VENT_FUEL = 0x12,

	// COMMANDS TO GSE
	CMD_GSE_DISCONNECT = 0x21,
	CMD_GSE_PRESSURIZE = 0x22,
	CMD_GSE_FILLING_N2O = 0x23,
	CMD_GSE_VENT = 0x24,
};

typedef double scalar;

struct Vect3 {
	scalar x;
	scalar y;
	scalar z;
};

struct Quaternion {
	scalar s;
	Vect3 v;
};


#endif //INC_2024_I_AV_SW_TYPES_HPP
