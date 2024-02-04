//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_DATA_HPP
#define INC_2024_I_AV_SW_TEENSY_DATA_HPP

#include "teensy_command.hpp"
#include "teensy_output.hpp"

struct TeensyDataStatus {
	TeensyCommandStatus com;
	TeensyOutputStatus out;
};

class TeensyDataClass {
public:
	TeensyDataStatus get();

	TeensyCommandClass com;
	TeensyOutputClass out;
};

#endif //INC_2024_I_AV_SW_TEENSY_DATA_HPP
