//
// Created by Samuel on 04/02/2024.
//

#include "core/base_board.hpp"
#include "logger.hpp"

void BaseBoardClass::loopOnce() {
	sys.setTime(getCurrentTimeMillis());												// UPDATE TIME REF
	sys.setUpdated(false);

	FSMState prev = sys.get().state;
	FSMState current = getNextState();
	sys.setState(current);																// UPDATE FSM

	if (prev != current) {                    											// IF CHANGED STATE
		sys.setLastFsmTransition(getCurrentTimeMillis());    							// UPDATE TRANSITION TIME
		sys.setUpdated(true);    														// RAISE FLAG
	}

	update();
	output();
}

FSMState BaseBoardClass::getNextState() {
	LOG("BaseBoardClass::getNextState > OVERRIDE ME !");
	return sys.get().state;
}


time_millis_t BaseBoardClass::getCurrentTimeMillis() {
	LOG("BaseBoardClass::getCurrentTimeMillis > OVERRIDE ME !");
	return 0;
}

void BaseBoardClass::update() {
	LOG("BaseBoardClass::update > OVERRIDE ME !");
}

void BaseBoardClass::output() {
	LOG("BaseBoardClass::output > OVERRIDE ME !");
}

void BaseBoardClass::init() {
	LOG("BaseBoardClass::init > OVERRIDE ME !");
}
