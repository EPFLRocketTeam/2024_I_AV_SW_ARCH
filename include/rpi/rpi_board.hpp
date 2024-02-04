//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_BOARD_HPP
#define INC_2024_I_AV_SW_RPI_BOARD_HPP

#include "base_board.hpp"
#include "rpi_data.hpp"

class RpiBoard : public BaseBoard {
protected:
	RpiDataClass data;

public:
	FSMState getNextState() override;

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
};

#endif //INC_2024_I_AV_SW_RPI_BOARD_HPP
