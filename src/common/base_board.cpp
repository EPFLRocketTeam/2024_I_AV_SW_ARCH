//
// Created by Samuel on 04/02/2024.
//

#include "base_board.hpp"
#include "logger.hpp"

void BaseBoard::update() {
	sys.setTime(getCurrentTimeMillis());												// UPDATE TIME REF
	sys.setUpdated(false);

	FSMState prev = sys.get().state;
	FSMState current = getNextState();
	sys.setState(current);																// UPDATE FSM

	if (prev != current) {                    											// IF CHANGED STATE
		sys.setLastFsmTransition(getCurrentTimeMillis());    							// UPDATE TRANSITION TIME
		sys.setUpdated(true);    														// RAISE FLAG
	}

	compute();
	output();
}

FSMState BaseBoard::getNextState() {
	LOG("BaseBoard::getNextState > OVERRIDE ME !");
	return INIT_STATE;
}


time_millis_t BaseBoard::getCurrentTimeMillis() {
	LOG("BaseBoard::getCurrentTimeMillis > OVERRIDE ME !");
	return 0;
}

void BaseBoard::compute() {
	LOG("BaseBoard::compute > OVERRIDE ME !");
}

void BaseBoard::output() {
	LOG("BaseBoard::output > OVERRIDE ME !");
}