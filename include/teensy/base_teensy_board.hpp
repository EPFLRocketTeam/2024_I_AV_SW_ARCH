//
// Created by Samuel on 05/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_TEENSY_BOARD_HPP
#define INC_2024_I_AV_SW_BASE_TEENSY_BOARD_HPP

#include "core/base_board.hpp"
#include "logger.hpp"

template< class IntranetClass, class TelecomClass, class SensorsClass>
class BaseTeensyBoardClass : public BaseBoardClass {
protected:
	IntranetClass intra;
	TelecomClass tele;
	SensorsClass sens;

	FSMState stateInit() {
		LOG("BaseRpiBoardClass::stateInit > OVERRIDE ME !");
		return INIT_STATE;
	}
	FSMState stateCalibration() {
		LOG("BaseRpiBoardClass::stateCalibration > OVERRIDE ME !");
		return CALIBRATION_STATE;
	}
	FSMState stateArmed() {
		LOG("BaseRpiBoardClass::stateArmed > OVERRIDE ME !");
		return ARMED_STATE;
	}
	FSMState statePressurized() {
		LOG("BaseRpiBoardClass::statePressurized > OVERRIDE ME !");
		return TOUCHDOWN_STATE;
	}
	FSMState stateFlightStateReady() {
		LOG("BaseRpiBoardClass::stateFlightStateReady > OVERRIDE ME !");
		return FLIGHTREADY_STATE;
	}
	FSMState stateIgnite() {
		LOG("BaseRpiBoardClass::stateIgnite > OVERRIDE ME !");
		return IGNITE_STATE;
	}
	FSMState stateIgnition() {
		LOG("BaseRpiBoardClass::stateIgnition > OVERRIDE ME !");
		return IGNITION_STATE;
	}
	FSMState stateAscent() {
		LOG("BaseRpiBoardClass::stateAscent > OVERRIDE ME !");
		return ASCENT_STATE;
	}
	FSMState stateHovering() {
		LOG("BaseRpiBoardClass::stateHovering > OVERRIDE ME !");
		return HOVERING_STATE;
	}
	FSMState stateDescent() {
		LOG("BaseRpiBoardClass::stateDescent > OVERRIDE ME !");
		return DESCENT_STATE;
	}
	FSMState stateTouchdown() {
		LOG("BaseRpiBoardClass::stateTouchdown > OVERRIDE ME !");
		return TOUCHDOWN_STATE;
	}
	FSMState stateAbort()  {
		LOG("BaseRpiBoardClass::stateAbort > OVERRIDE ME !");
		return ABORT_STATE;
	}
public:
	FSMState getNextState() override {
		if(tele.isCommandUpdated() && tele.isCommand(CMD_STATE)){
			auto nextState = (FSMState) tele.get().comId;
			tele.resetCommand();
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
};

#endif //INC_2024_I_AV_SW_BASE_TEENSY_BOARD_HPP
