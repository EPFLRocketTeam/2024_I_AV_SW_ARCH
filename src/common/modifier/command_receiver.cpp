//
// Created by Samuel on 04/02/2024.
//

#include "modifier/command_receiver.hpp"

bool CommandReceiver::isCommandUpdated() {
	return comId != lastComId;
}

bool CommandReceiver::isCommand(CommandID id) {
	return comId = id;
}

void CommandReceiver::resetCommand() {
	comId = CMD_NONE;
	lastComId = CMD_NONE;
	comVal = 0;
}
