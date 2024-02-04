//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_COMMAND_HPP
#define INC_2024_I_AV_SW_TEENSY_COMMAND_HPP

#include <cstdint>

enum TeensyCommandIDs {
	TEENSY_CMD_NONE,
	TEENSY_CMD_STATE
};

struct TeensyCommandStatus {
	TeensyCommandIDs cmdId;
	uint8_t value;
};

class TeensyCommandClass {
protected:
	TeensyCommandIDs cmdId = TEENSY_CMD_NONE;
	TeensyCommandIDs lastCmdId = TEENSY_CMD_NONE;
	uint8_t value = 0;
public:
	TeensyCommandStatus get();
	void update();
	void reset();
	bool isUpdated();
};

#endif //INC_2024_I_AV_SW_TEENSY_COMMAND_HPP
