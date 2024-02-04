//
// Created by Samuel on 04/02/2024.
//
#include "rpi_board.hpp"
#include "logger.hpp"

FSMState RpiBoard::getNextState() {
	FSMState currentState = sys.get().state;
	FSMState nextState = INIT_STATE;

	if (data.com.isUpdated()) {
		RpiCommandStatus com = data.get().com;
		nextState = executeCommand(com.cmdId, com.value);
		data.com.reset();
	} else {
		switch (currentState) {
			case INIT_STATE:
				nextState = stateInit();
				break;
			case CALIBRATION_STATE:
				nextState = stateCalibration();
				break;
			case ARMED_STATE:
				nextState = stateArmed();
				break;
			case PRESSURIZE_STATE:
				nextState = statePressurized();
				break;
			case FLIGHTREADY_STATE:
				nextState = stateFlightStateReady();
				break;
			case IGNITE_STATE:
				nextState = stateIgnite();
				break;
			case IGNITION_STATE:
				nextState = stateIgnition();
				break;
			case ASCENT_STATE:
				nextState = stateAscent();
				break;
			case HOVERING_STATE:
				nextState = stateHovering();
				break;
			case DESCENT_STATE:
				nextState = stateDescent();
				break;
			case TOUCHDOWN_STATE:
				nextState = stateTouchdown();
				break;
			case ABORT_STATE:
				nextState = stateAbort();
				break;
		}
	}
	if(nextState != currentState)
		sys.setLastFsmTransition(getCurrentTimeMillis());

	return nextState;
}

FSMState RpiBoard::stateInit() {
	LOG("RpiBoard::stateInit > OVERRIDE ME !!");
	return INIT_STATE;
}

FSMState RpiBoard::stateCalibration() {
	LOG("RpiBoard::stateCalibration > OVERRIDE ME !!");
	return CALIBRATION_STATE;
}

FSMState RpiBoard::stateArmed() {
	LOG("RpiBoard::stateArmed > OVERRIDE ME !!");
	return ARMED_STATE;
}

FSMState RpiBoard::statePressurized() {
	LOG("RpiBoard::statePressurized > OVERRIDE ME !!");
	return TOUCHDOWN_STATE;
}

FSMState RpiBoard::stateFlightStateReady() {
	LOG("RpiBoard::stateFlightStateReady > OVERRIDE ME !!");
	return FLIGHTREADY_STATE;
}

FSMState RpiBoard::stateIgnite() {
	LOG("RpiBoard::stateIgnite > OVERRIDE ME !!");
	return IGNITE_STATE;
}

FSMState RpiBoard::stateIgnition() {
	LOG("RpiBoard::stateIgnition > OVERRIDE ME !!");
	return IGNITION_STATE;
}

FSMState RpiBoard::stateAscent() {
	LOG("RpiBoard::stateAscent > OVERRIDE ME !!");
	return ASCENT_STATE;
}

FSMState RpiBoard::stateHovering() {
	LOG("RpiBoard::stateHovering > OVERRIDE ME !!");
	return HOVERING_STATE;
}

FSMState RpiBoard::stateDescent() {
	LOG("RpiBoard::stateDescent > OVERRIDE ME !!");
	return DESCENT_STATE;
}

FSMState RpiBoard::stateTouchdown() {
	LOG("RpiBoard::stateTouchdown > OVERRIDE ME !!");
	return TOUCHDOWN_STATE;
}

FSMState RpiBoard::stateAbort() {
	LOG("RpiBoard::stateAbort > OVERRIDE ME !!");
	return ABORT_STATE;
}

FSMState RpiBoard::executeCommand(RpiCommandIDs id, uint8_t value) {
	LOG("RpiBoard::executeCommand > OVERRIDE ME !!");
	return sys.get().state;
}


