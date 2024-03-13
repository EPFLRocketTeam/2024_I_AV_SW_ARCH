//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_SYSTEM_HPP
#define INC_2024_I_AV_SW_SYSTEM_HPP

#include "core/fsm.hpp"
#include "types.hpp"

/**
 * @var time: time at the beginning of each cycle
 * @var lastFSMTransition: time of the last FSM transition
 * @var state: current state
 * @var initCheckComplete: flag ; if the board init was successful
 * @var stateUpdated: flag ; if the state was updated this cycle
 * @var inFlight: flag ; if the rocket is in an inFlight state ; used for abort
 * @var ignitionSequence: number ; current ignition sequence ;  used for tracking the state of ignition
 */
struct SystemStatus {
	time_millis_t time;
	time_millis_t lastFSMTransition;
	FSMState state;
	bool initCheckComplete;
	bool stateUpdated;
	bool inFlight;
    int ignitionSequence;
};

/**
 * SystemClass contains essential data and flags for Avionics Operations. It may be seen as the "memory" of BaseBoardClass.
 */
class SystemClass {
private:
	time_millis_t time;
	time_millis_t lastFSMTransition;
	FSMState state;
	bool initCheckComplete;
	bool stateUpdated;
	bool inFlight;
    int ignitionSequence;
public:
	SystemStatus get();
	void setTime(time_millis_t);
	void setLastFsmTransition(time_millis_t);
	void setState(FSMState);
	void setInitCheckComplete(bool);
	void setStateUpdated(bool);
	void setInFlight(bool);
    void setIgnitionSequence(int);
};

#endif //INC_2024_I_AV_SW_SYSTEM_HPP
