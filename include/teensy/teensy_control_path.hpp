//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_CONTROL_PATH_HPP
#define INC_2024_I_AV_SW_TEENSY_CONTROL_PATH_HPP

#include <cstdint>
#include "commands.hpp"

struct TeensyControlPathStatus {
	TeensyCommandIDs cmdId;
	uint8_t value;
};

class TeensyControlPathClass {
protected:
	TeensyCommandIDs cmdId = TEENSY_CMD_NONE;
	TeensyCommandIDs lastCmdId = TEENSY_CMD_NONE;
	uint8_t value = 0;
public:
	TeensyControlPathStatus get();
	void update();
	void reset();
	bool isUpdated();
	void write_to_rpi();
};

#endif //INC_2024_I_AV_SW_TEENSY_CONTROL_PATH_HPP
