//
// Created by Samuel on 04/02/2024.
//

#include "modifier/command_receiver.hpp"

template<typename CommandIDs>
bool CommandReceiver<CommandIDs>::isCommandUpdated() {
	return comId != lastComId;
}

template<typename CommandIDs>
bool CommandReceiver<CommandIDs>::isCommand(CommandIDs id) {
	return comId = id;
}

template<typename CommandIDs>
void CommandReceiver<CommandIDs>::resetCommand() {
	comId = 0;
	lastComId = 0;
	comVal = 0;
}
