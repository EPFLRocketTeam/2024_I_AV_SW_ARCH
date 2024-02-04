//
// Created by Samuel on 04/02/2024.
//

#include "system.hpp"

SystemStatus SystemClass::get() {
	return SystemStatus{
		.time = time,
		.lastFSMTransition = lastFSMTransition,
		.state = state,
		.initialized = initialized,
	};
}

void SystemClass::setTime(time_t timeIn) {
	time = timeIn;
}

void SystemClass::setLastFsmTransition(time_t lastFsmTransitionIn) {
	lastFSMTransition = lastFsmTransitionIn;
}

void SystemClass::setState(FSMState stateIn) {
	state = stateIn;
}

void SystemClass::setInitialized(bool initializedIn) {
	initialized = initializedIn;
}
