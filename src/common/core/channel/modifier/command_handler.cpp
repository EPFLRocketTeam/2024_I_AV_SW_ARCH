//
// Created by Samuel on 04/02/2024.
//

#include "core/channel/modifier/command_handler.hpp"

bool CommandHandler::isCommandUpdated() {
	return comId != lastComId;
}

bool CommandHandler::isCommand(CommandID id) {
	return comId = id;
}

void CommandHandler::resetCommand() {
	comId = CMD_NONE;
	lastComId = CMD_NONE;
	comVal = 0;
}
