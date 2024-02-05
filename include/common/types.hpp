//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TYPES_HPP
#define INC_2024_I_AV_SW_TYPES_HPP

#include <cstdint>

typedef uint32_t time_millis_t;

enum CommandID: uint8_t {
	CMD_NONE = 0x00,
	CMD_STATE = 0x01,
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
