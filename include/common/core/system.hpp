//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_SYSTEM_HPP
#define INC_2024_I_AV_SW_SYSTEM_HPP

#include "core/fsm.hpp"
#include "types.hpp"

struct SystemStatus {
	time_millis_t time;																	// TIME REF (beginning of each cycle)
	time_millis_t lastFSMTransition;													// TIME OF LAST STATE TRANSITION
	FSMState state;																		// CURRENT STATE
	bool initCheckComplete;																// CHECKS IN INIT STATE OK ?
	bool updated;																		// STATE TRANSITION THIS CYCLE ?
};

class SystemClass {
private:
	time_millis_t time;
	time_millis_t lastFSMTransition;
	FSMState state;
	bool initCheckComplete;
	bool updated;
public:
	SystemStatus get();
	void setTime(time_millis_t);
	void setLastFsmTransition(time_millis_t);
	void setState(FSMState);
	void setInitCheckComplete(bool);
	void setUpdated(bool);
};

#endif //INC_2024_I_AV_SW_SYSTEM_HPP
