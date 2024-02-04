//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_SYSTEM_HPP
#define INC_2024_I_AV_SW_SYSTEM_HPP

#include "fsm.hpp"
#include <cstdint>

typedef uint32_t time_millis_t;

struct SystemStatus {
	time_millis_t time;
	time_millis_t lastFSMTransition;
	FSMState state;
	bool initialized;
};

class SystemClass {
private:
	time_millis_t time;
	time_millis_t lastFSMTransition;
	FSMState state;
	bool initialized;
public:
	SystemStatus get();
	void setTime(time_millis_t);
	void setLastFsmTransition(time_millis_t);
	void setState(FSMState);
	void setInitialized(bool);
};

#endif //INC_2024_I_AV_SW_SYSTEM_HPP
