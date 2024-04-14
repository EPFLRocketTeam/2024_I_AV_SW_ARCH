//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_BOARD_HPP
#define INC_2024_I_AV_SW_BASE_BOARD_HPP


#include "common/core/system.hpp"

/**
 * BaseBoardClass is the interface from which all board derive. To run the board, one must first call <strong>init</strong> then put <strong>loopOnce</strong> in an infinite loop
 */
class BaseBoardClass {
protected:
	SystemClass sys = SystemClass();
public:
	void loopOnce();

	virtual time_millis_t getCurrentTimeMillis();
	virtual FSMState getNextState();
	virtual void update();
	virtual void output();
	virtual void init();
};


#endif //INC_2024_I_AV_SW_BASE_BOARD_HPP
