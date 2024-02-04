//
// Created by Samuel on 04/02/2024.
//

#include "teensy_command.hpp"
#include "logger.hpp"

TeensyCommandStatus TeensyCommandClass::get() {
	return TeensyCommandStatus {
		.cmdId = cmdId,
		.value = value,
	};
}

void TeensyCommandClass::update() {
	LOG("TeensyCommandClass::update > OVERRIDE ME !!");
	lastCmdId = cmdId;
}

void TeensyCommandClass::reset() {
	cmdId = TEENSY_CMD_NONE;
	lastCmdId = TEENSY_CMD_NONE;
	value = 0;
}

bool TeensyCommandClass::isUpdated() {
	return cmdId != lastCmdId;
}
