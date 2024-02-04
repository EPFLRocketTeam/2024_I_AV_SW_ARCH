//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_BOARD_HPP
#define INC_2024_I_AV_SW_RPI_BOARD_HPP

#include "base_board.hpp"
#include "rpi_paths.hpp"

class RpiBoard : public BaseBoard {
protected:
	RpiPathsClass data;
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

	FSMState executeCommand(RpiCommandIDs, uint8_t);
public:
	FSMState getNextState() override;
};

#endif //INC_2024_I_AV_SW_RPI_BOARD_HPP
