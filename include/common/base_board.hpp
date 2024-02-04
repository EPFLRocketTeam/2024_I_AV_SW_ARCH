//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_BOARD_HPP
#define INC_2024_I_AV_SW_BASE_BOARD_HPP


#include "system.hpp"

class BaseBoard {
protected:
	SystemClass sys;
public:
	void update();

	virtual FSMState getNextState();
	time_millis_t getCurrentTimeMillis();
};


#endif //INC_2024_I_AV_SW_BASE_BOARD_HPP
