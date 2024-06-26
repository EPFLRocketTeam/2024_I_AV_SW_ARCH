//
// Created by Samuel on 04/02/2024.
//

#include "common/core/system.hpp"

SystemStatus SystemClass::get() {
	return SystemStatus {
		.time = time,
		.lastFSMTransition = lastFSMTransition,
		.state = state,
		.initCheckComplete = initCheckComplete,
		.stateUpdated = stateUpdated,
		.inFlight = inFlight,
		.calibrationSuccessful = calibrationSuccessful,
		.ignitionSequence = ignitionSequence,
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

void SystemClass::setStateUpdated(bool stateUpdatedIn) {
	stateUpdated = stateUpdatedIn;
}

void SystemClass::setInFlight(bool inFlightIn) {
	inFlight = inFlightIn;
}

void SystemClass::setIgnitionSequence(int ignitionSequenceIn) {
    ignitionSequence = ignitionSequenceIn;
}

void SystemClass::setCalibrationSuccessful(bool calibrationSuccessfulIn) {
    calibrationSuccessful = calibrationSuccessfulIn;
}
