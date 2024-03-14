//
// Created by Samuel on 05/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_TEENSY_BOARD_HPP
#define INC_2024_I_AV_SW_BASE_TEENSY_BOARD_HPP

#include "core/base_board.hpp"
#include "logger.hpp"

#define IGNITION_SEQUENCE_THRESHOLD_1 3000
#define IGNITION_SEQUENCE_THRESHOLD_2 6000
#define IGNITION_SEQUENCE_THRESHOLD_3 9000
#define IGNITION_SEQUENCE_LIMIT 4

template<class IntranetClass, class TelecomClass, class SensorsClass>
class BaseTeensyBoardClass : public virtual BaseBoardClass {
protected:
	IntranetClass intra;
	TelecomClass tele;
	SensorsClass sens;

    // battery power is monitored and assessed
    virtual bool checkPower() = 0;

    // Guidance initial trajectory is computed following procedure
    virtual bool checkInitialTrajectory() = 0;

    // Navigation is calibrated and assessed following procedure
    virtual bool checkNavigation() = 0;

    // Control is calibrated and assessed following procedure
    virtual bool checkControl() = 0;

    // Checks that the Hopper is ready for filling and pressurization
    virtual bool checkArmed() = 0;

    // Check if pressurization is finished and we are flight ready
    virtual bool checkFlightReady() = 0;

    // Check if the hopper is fully ready and flight may begin.
    virtual bool readyForIgnition() = 0;

    // Abort everything and make all necessary checks before going back to INIT STATE
    virtual void abortAll() = 0;

    // Check if the above method was successful
    virtual bool abortSuccessful() = 0;

    // The Hopper ascents to its targeted altitude
    virtual bool targetAltitudeReached() = 0;

    // The hover is stable and can begin descent
    virtual bool hoverStable() = 0;

    // Ready for touchdown
    virtual bool touchdownReady() = 0;

    FSMState stateInit() {
        // Setting system flags
        sys.setInFlight(false);
        sys.setIgnitionSequence(0);
        sys.setInitCheckComplete(checkPower() && intra.get().connectionEstablished && sens.checkAllSensorsValid());

        // Next potential transition
        if(tele.isCommandUpdated() && tele.isCommand(CMD_AV_STATE)){
            FSMState nextState = tele.get().comId;
            tele.resetCommand();
            switch (nextState) {
                case CALIBRATION_STATE:
                    sys.setCalibrationSuccessful(false);
                    return CALIBRATION_STATE;
                case ARMED_STATE:
                    return sys.get().initCheckComplete ? ARMED_STATE : INIT_STATE;
                default:
                    break;
            }
        }

        return INIT_STATE;
    }
    FSMState stateCalibration() {
        bool calibrationReady = sens.checkCalibration() && checkControl() && checkInitialTrajectory() && checkNavigation();

        // Only go to next state if the calibration is finished
        if(calibrationReady && tele.isCommandUpdated() && tele.isCommand(CMD_AV_STATE)){
            FSMState nextState = tele.get().comId;
            tele.resetCommand();
            sys.setCalibrationSuccessful(true);
            return INIT_STATE;
        }

        return CALIBRATION_STATE;
    }
    FSMState stateArmed() {
        if(tele.isCommandUpdated() && tele.isCommand(CMD_AV_STATE)){
            FSMState nextState = tele.get().comId;
            tele.resetCommand();
            switch (nextState) {
                case INIT_STATE:
                    return INIT_STATE;
                case ABORT_STATE:
                    return ABORT_STATE;
                case PRESSURIZE_STATE:
                    return checkArmed() ? PRESSURIZE_STATE : ARMED_STATE;
                default:
                    break;
            }
        }

        return ARMED_STATE;
    }
    FSMState statePressurized() {
        if (shouldAbort()) {
            return ABORT_STATE;
        }

        return checkFlightReady() ? FLIGHTREADY_STATE : PRESSURIZE_STATE;
    }
    FSMState stateFlightStateReady() {
        if (shouldAbort()) {
            return ABORT_STATE;
        }

        if(tele.isCommandUpdated() && tele.isCommand(CMD_AV_STATE)){
            FSMState nextState = tele.get().comId;
            tele.resetCommand();
            switch (nextState) {
                case ABORT_STATE:
                    return ABORT_STATE;
                case IGNITE_STATE:
                    return readyForIgnition() ? IGNITE_STATE : FLIGHTREADY_STATE;
                default:
                    break;
            }
        }

        return FLIGHTREADY_STATE;
    }
    FSMState stateIgnite() {
        if (shouldAbort()) {
            return ABORT_STATE;
        }

        sys.setIgnitionSequence(1);

        return IGNITION_STATE;
    }
    FSMState stateIgnition() {
        if (shouldAbort()) {
            return ABORT_STATE;
        }

        int ignitionSequence = sys.get().ignitionSequence;

        if (ignitionSequence == IGNITION_SEQUENCE_LIMIT) {
            return ASCENT_STATE;
        }

        int timeSinceIgnite = timeDiff(sys.get().time,sys.get().lastFSMTransition);

        if (timeSinceIgnite >= IGNITION_SEQUENCE_THRESHOLD_3) {
            sys.setIgnitionSequence(4);
        } else if (timeSinceIgnite >= IGNITION_SEQUENCE_THRESHOLD_2) {
            sys.setIgnitionSequence(3);
        } else if (timeSinceIgnite >= IGNITION_SEQUENCE_THRESHOLD_1) {
            sys.setIgnitionSequence(2);
        }

        return IGNITION_STATE;
    }
    FSMState stateAscent() {
        if (shouldAbort()) {
            return ABORT_STATE;
        }

        return targetAltitudeReached() ? HOVERING_STATE : ASCENT_STATE;
    }
    FSMState stateHovering() {
        if (shouldAbort()) {
            return ABORT_STATE;
        }

        return hoverStable() ? DESCENT_STATE : HOVERING_STATE;
    }
    FSMState stateDescent() {
        if (shouldAbort()) {
            return ABORT_STATE;
        }

        return touchdownReady() ? TOUCHDOWN_STATE : DESCENT_STATE;
    }
    FSMState stateTouchdown() {
        if (shouldAbort()) {
            return ABORT_STATE;
        }

        return TOUCHDOWN_STATE;
    }
    FSMState stateAbort()  {
        abortAll();

        return abortSuccessful() ? INIT_STATE : ABORT_STATE;
    }

    /*
     * Check if there is an abort signal sent from the ground station
     * WARNING: the telecom is not reset
     */
    bool shouldAbort() {
        if(tele.isCommandUpdated() && tele.isCommand(CMD_AV_STATE)){
            FSMState nextState = tele.get().comId;
            bool isAbort = nextState == ABORT_STATE;
            if (isAbort) {
                tele.reset();
            }
            return isAbort;
        }
        return false;
    }
public:
	FSMState getNextState() override {
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