//
// Created by Samuel on 04/02/2024.
//
#include "teensy_board.hpp"
#include "logger.hpp"

FSMState TeensyBoard::getNextState() {
	FSMState nextState = INIT_STATE;

	if (data.com.isUpdated()) {
		TeensyCommandStatus com = data.get().com;
		nextState = executeCommand(com.cmdId, com.value);
		data.com.reset();
	}

	return nextState;
}

FSMState TeensyBoard::executeCommand(TeensyCommandIDs id, uint8_t value) {
	LOG("RpiBoard::executeCommand > OVERRIDE ME !!");
	return sys.get().state;
}
