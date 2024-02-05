//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_BOARD_HPP
#define INC_2024_I_AV_SW_BASE_BOARD_HPP


#include "core/system.hpp"

class BaseBoardClass{
protected:
	SystemClass sys{};
public:
	void loopOnce();
	virtual time_millis_t getCurrentTimeMillis();
	virtual FSMState getNextState();
	virtual void update();
	virtual void output();
};


#endif //INC_2024_I_AV_SW_BASE_BOARD_HPP
