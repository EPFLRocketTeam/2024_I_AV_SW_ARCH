//
// Created by Samuel on 04/02/2024.
//
#include "rpi_control_path.hpp"
#include "logger.hpp"

RpiControlPathStatus RpiControlPathClass::get() {
	return RpiControlPathStatus {
		.cmdId = cmdId,
		.value = value,
	};
}

void RpiControlPathClass::update() {
	LOG("RpiControlPathClass::update > OVERRIDE ME !!");
	lastCmdId = cmdId;
}

void RpiControlPathClass::reset() {
	cmdId = RPI_CMD_NONE;
	lastCmdId = RPI_CMD_NONE;
	value = 0;
}

bool RpiControlPathClass::isUpdated() {
	return cmdId != lastCmdId;
}

void RpiControlPathClass::write_to_teensy() {
	LOG("RpiControlPathClass::write_to_teensy > OVERRIDE ME !!");
}
