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
protected:
	TeensyCommandClass com;
	TeensyOutputClass out;
public:
	TeensyDataStatus get();
};

#endif //INC_2024_I_AV_SW_TEENSY_DATA_HPP
