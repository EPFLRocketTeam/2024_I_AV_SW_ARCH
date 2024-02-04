//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_CONTROL_PATH_HPP
#define INC_2024_I_AV_SW_RPI_CONTROL_PATH_HPP

#include <cstdint>
#include "commands.hpp"

struct RpiControlPathStatus {
	RpiCommandIDs cmdId;
	uint8_t value;
};

class RpiControlPathClass {
protected:
	RpiCommandIDs cmdId = RPI_CMD_NONE;
	RpiCommandIDs lastCmdId = RPI_CMD_NONE;
	uint8_t value = 0;
public:
	RpiControlPathStatus get();
	void update();
	void reset();
	bool isUpdated();
	void write_to_teensy();
};


#endif //INC_2024_I_AV_SW_RPI_CONTROL_PATH_HPP
