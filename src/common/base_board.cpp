//
// Created by Samuel on 04/02/2024.
//

#include "base_board.hpp"
#include "logger.hpp"

void BaseBoard::update() {
	sys.setTime(getCurrentTimeMillis());	// UPDATE TIME REF
	sys.setState(getNextState());			// UPDATE FSM
	/* TODO
	 * Compute relevant things based on current state
	 * Output bunch of shit
	 */
}

FSMState BaseBoard::getNextState() {
	LOG("BaseBoard::getNextState > OVERRIDE ME !");
	return ABORT_STATE;
}

time_t BaseBoard::getCurrentTimeMillis() {
	LOG("BaseBoard::getCurrentTimeMillis > OVERRIDE ME !");
	return 0;
}
