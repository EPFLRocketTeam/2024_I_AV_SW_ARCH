//
// Created by Samuel on 04/02/2024.
//

#include "system.hpp"

SystemStatus SystemClass::get() {
	return SystemStatus{
		.time = time,
		.lastFSMTransition = lastFSMTransition,
		.state = state,
		.initCheckComplete = initCheckComplete,
		.updated = updated,
	};
}

void SystemClass::setTime(time_millis_t timeIn) {
	time = timeIn;
}

void SystemClass::setLastFsmTransition(time_millis_t lastFsmTransitionIn) {
	lastFSMTransition = lastFsmTransitionIn;
}

void SystemClass::setState(FSMState stateIn) {
	state = stateIn;
}

void SystemClass::setInitCheckComplete(bool initCheckCompleteIn) {
	initCheckComplete = initCheckCompleteIn;
}

void SystemClass::setUpdated(bool updatedIn) {
	updated = updatedIn;
}
