//
// Created by Samuel on 04/02/2024.
//
#include "rpi_board.hpp"
#include "logger.hpp"

template<class DataClass>
FSMState RpiBoard<DataClass>::getNextState() {

	if(data.tele.isCommandUpdated() && data.tele.isCommand(TEENSY_CMD_STATE)){
		auto nextState = (FSMState) data.get().tele.comId;
		data.tele.resetCommand();
		return nextState;
	}

	switch (sys.get().state) {
		case CALIBRATION_STATE:
			return stateCalibration();
		case ARMED_STATE:
			return stateArmed();
		case PRESSURIZE_STATE:
			return statePressurized();
		case FLIGHTREADY_STATE:
			return stateFlightStateReady();
		case IGNITE_STATE:
			return stateIgnite();
		case IGNITION_STATE:
			return stateIgnition();
		case ASCENT_STATE:
			return stateAscent();
		case HOVERING_STATE:
			return stateHovering();
		case DESCENT_STATE:
			return stateDescent();
		case TOUCHDOWN_STATE:
			return stateTouchdown();
		case ABORT_STATE:
			return stateAbort();
		default: // INIT_STATE
			return stateInit();
	}
}

template<class DataClass>
FSMState RpiBoard<DataClass>::executeCommand(RpiCommandID, uint8_t) {
	LOG("RpiBoard::executeCommand > OVERRIDE ME !");
	return INIT_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateInit() {
	LOG("RpiBoard::stateInit > OVERRIDE ME !");
	return INIT_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateCalibration() {
	LOG("RpiBoard::stateCalibration > OVERRIDE ME !");
	return CALIBRATION_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateArmed() {
	LOG("RpiBoard::stateArmed > OVERRIDE ME !");
	return ARMED_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::statePressurized() {
	LOG("RpiBoard::statePressurized > OVERRIDE ME !");
	return TOUCHDOWN_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateFlightStateReady() {
	LOG("RpiBoard::stateFlightStateReady > OVERRIDE ME !");
	return FLIGHTREADY_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateIgnite() {
	LOG("RpiBoard::stateIgnite > OVERRIDE ME !");
	return IGNITE_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateIgnition() {
	LOG("RpiBoard::stateIgnition > OVERRIDE ME !");
	return IGNITION_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateAscent() {
	LOG("RpiBoard::stateAscent > OVERRIDE ME !");
	return ASCENT_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateHovering() {
	LOG("RpiBoard::stateHovering > OVERRIDE ME !");
	return HOVERING_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateDescent() {
	LOG("RpiBoard::stateDescent > OVERRIDE ME !");
	return DESCENT_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateTouchdown() {
	LOG("RpiBoard::stateTouchdown > OVERRIDE ME !");
	return TOUCHDOWN_STATE;
}

template<class DataClass>
FSMState RpiBoard<DataClass>::stateAbort() {
	LOG("RpiBoard::stateAbort > OVERRIDE ME !");
	return ABORT_STATE;
}




