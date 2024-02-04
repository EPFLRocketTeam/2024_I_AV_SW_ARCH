//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_COMMAND_HPP
#define INC_2024_I_AV_SW_RPI_COMMAND_HPP

#include <cstdint>

enum RpiCommandIDs {
	RPI_CMD_NONE,
	RPI_CMD_STATE
};

struct RpiCommandStatus {
	RpiCommandIDs cmdId;
	uint8_t value;
};

class RpiCommandClass {
protected:
	RpiCommandIDs cmdId = RPI_CMD_NONE;
	RpiCommandIDs lastCmdId = RPI_CMD_NONE;
	uint8_t value = 0;
public:
	RpiCommandStatus get();
	void update();
	void reset();
	bool isUpdated();
};


#endif //INC_2024_I_AV_SW_RPI_COMMAND_HPP
