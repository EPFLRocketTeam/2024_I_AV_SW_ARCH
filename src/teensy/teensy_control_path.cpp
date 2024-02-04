//
// Created by Samuel on 04/02/2024.
//

#include "teensy_control_path.hpp"
#include "logger.hpp"

TeensyControlPathStatus TeensyControlPathClass::get() {
	return TeensyControlPathStatus {
		.cmdId = cmdId,
		.value = value,
	};
}

void TeensyControlPathClass::update() {
	LOG("TeensyControlPathClass::update > OVERRIDE ME !!");
	lastCmdId = cmdId;
}

void TeensyControlPathClass::reset() {
	cmdId = TEENSY_CMD_NONE;
	lastCmdId = TEENSY_CMD_NONE;
	value = 0;
}

bool TeensyControlPathClass::isUpdated() {
	return cmdId != lastCmdId;
}

void TeensyControlPathClass::write_to_rpi() {
	LOG("TeensyControlPathClass::write_to_rpi > OVERRIDE ME !!");
}
