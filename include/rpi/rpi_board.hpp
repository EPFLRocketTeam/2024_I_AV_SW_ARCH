//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_BOARD_HPP
#define INC_2024_I_AV_SW_RPI_BOARD_HPP

#include "config.hpp"
#include "base_board.hpp"

template<class DataClass>
class RpiBoard : public BaseBoard{
protected:
	DataClass data;

	FSMState onCommand(CommandID, uint8_t);

	FSMState stateInit();
	FSMState stateCalibration();
	FSMState stateArmed();
	FSMState statePressurized();
	FSMState stateFlightStateReady();
	FSMState stateIgnite();
	FSMState stateIgnition();
	FSMState stateAscent();
	FSMState stateHovering();
	FSMState stateDescent();
	FSMState stateTouchdown();
	FSMState stateAbort();
public:
	FSMState getNextState() override;
};

#endif //INC_2024_I_AV_SW_RPI_BOARD_HPP
