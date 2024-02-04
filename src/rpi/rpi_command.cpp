//
// Created by Samuel on 04/02/2024.
//
#include "rpi_command.hpp"
#include "logger.hpp"

RpiCommandStatus RpiCommandClass::get() {
	return RpiCommandStatus {
		.cmdId = cmdId,
		.value = value,
	};
}

void RpiCommandClass::update() {
	LOG("RpiCommandClass::update > OVERRIDE ME !!");
	lastCmdId = cmdId;
}

void RpiCommandClass::reset() {
	cmdId = RPI_CMD_NONE;
	lastCmdId = RPI_CMD_NONE;
	value = 0;
}

bool RpiCommandClass::isUpdated() {
	return cmdId != lastCmdId;
}
