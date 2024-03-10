//
// Created by Samuel on 05/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_TEENSY_BOARD_HPP
#define INC_2024_I_AV_SW_BASE_TEENSY_BOARD_HPP

#include "core/base_board.hpp"
#include "logger.hpp"

template< class IntranetClass, class TelecomClass, class SensorsClass>
class BaseTeensyBoardClass : public virtual BaseBoardClass {
protected:
	IntranetClass intra;
	TelecomClass tele;
	SensorsClass sens;

    FSMState stateInit() {
        LOG("BaseRpiBoardClass::stateInit > OVERRIDE ME !");
        if (sys.get().state != INIT_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(INIT_STATE)
        }
        return INIT_STATE;
    }
    FSMState stateCalibration() {
        LOG("BaseRpiBoardClass::stateCalibration > OVERRIDE ME !");
        if (sys.get().state != CALIBRATION_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(CALIBRATION_STATE)
        }
        return CALIBRATION_STATE;
    }
    FSMState stateArmed() {
        LOG("BaseRpiBoardClass::stateArmed > OVERRIDE ME !");
        if (sys.get().state != ARMED_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(ARMED_STATE)
        }
        return ARMED_STATE;
    }
    FSMState statePressurized() {
        LOG("BaseRpiBoardClass::statePressurized > OVERRIDE ME !");
        if (sys.get().state != TOUCHDOWN_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(TOUCHDOWN_STATE)
        }
        return TOUCHDOWN_STATE;
    }
    FSMState stateFlightStateReady() {
        LOG("BaseRpiBoardClass::stateFlightStateReady > OVERRIDE ME !");
        if (sys.get().state != FLIGHTREADY_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(FLIGHTREADY_STATE)
        }
        return FLIGHTREADY_STATE;
    }
    FSMState stateIgnite() {
        LOG("BaseRpiBoardClass::stateIgnite > OVERRIDE ME !");
        if (sys.get().state != IGNITE_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(IGNITE_STATE)
        }
        return IGNITE_STATE;
    }
    FSMState stateIgnition() {
        LOG("BaseRpiBoardClass::stateIgnition > OVERRIDE ME !");
        if (sys.get().state != IGNITION_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(IGNITION_STATE)
        }
        return IGNITION_STATE;
    }
    FSMState stateAscent() {
        LOG("BaseRpiBoardClass::stateAscent > OVERRIDE ME !");
        if (sys.get().state != ASCENT_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(ASCENT_STATE)
        }
        return ASCENT_STATE;
    }
    FSMState stateHovering() {
        LOG("BaseRpiBoardClass::stateHovering > OVERRIDE ME !");
        if (sys.get().state != HOVERING_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(HOVERING_STATE)
        }
        return HOVERING_STATE;
    }
    FSMState stateDescent() {
        LOG("BaseRpiBoardClass::stateDescent > OVERRIDE ME !");
        if (sys.get().state != DESCENT_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(DESCENT_STATE)
        }
        return DESCENT_STATE;
    }
    FSMState stateTouchdown() {
        LOG("BaseRpiBoardClass::stateTouchdown > OVERRIDE ME !");
        if (sys.get().state != TOUCHDOWN_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(TOUCHDOWN_STATE)
        }
        return TOUCHDOWN_STATE;
    }
    FSMState stateAbort()  {
        LOG("BaseRpiBoardClass::stateAbort > OVERRIDE ME !");
        if (sys.get().state != ABORT_STATE) {
            // Usefull to check this ? I don't know in C++ ...
            sys.setState(ABORT_STATE)
        }
        return ABORT_STATE;
    }
public:
	FSMState getNextState() override {
		if(tele.isCommandUpdated() && tele.isCommand(CMD_AV_STATE)){
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