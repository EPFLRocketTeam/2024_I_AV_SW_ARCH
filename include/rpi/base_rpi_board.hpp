//
// Created by Samuel on 05/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_RPI_BOARD_HPP
#define INC_2024_I_AV_SW_BASE_RPI_BOARD_HPP

#include "core/base_board.hpp"
#include "logger.hpp"

template< class IntranetClass>
class BaseRpiBoardClass : public virtual BaseBoardClass {
protected:
	IntranetClass intra;

public:
	FSMState getNextState() override {
		if (intra.isCommandUpdated() && intra.isCommand(CMD_AV_STATE)) {
			auto nextState = (FSMState) intra.get().comId;
			intra.resetCommand();
			return nextState;
		}

		return sys.get().state;
	}
};

#endif //INC_2024_I_AV_SW_BASE_RPI_BOARD_HPP
