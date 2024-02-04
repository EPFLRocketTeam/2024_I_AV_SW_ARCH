//
// Created by Samuel on 04/02/2024.
//
#include "teensy_board.hpp"
#include "logger.hpp"

FSMState TeensyBoard::getNextState() {
	FSMState nextState = INIT_STATE;

	if (data.ctrl.isUpdated()) {
		TeensyControlPathStatus com = data.get().ctrl;
		nextState = executeCommand(com.cmdId, com.value);
		data.ctrl.reset();
	}

	return nextState;
}

FSMState TeensyBoard::executeCommand(TeensyCommandIDs id, uint8_t value) {
	LOG("RpiBoard::executeCommand > OVERRIDE ME !!");
	return sys.get().state;
}
