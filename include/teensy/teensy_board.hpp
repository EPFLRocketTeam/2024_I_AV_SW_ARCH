//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_BOARD_HPP
#define INC_2024_I_AV_SW_TEENSY_BOARD_HPP

#include "base_board.hpp"
#include "teensy_paths.hpp"

class TeensyBoard : public BaseBoard {
protected:
	TeensyPathsClass data;
public:
	FSMState getNextState() override;

	FSMState executeCommand(TeensyCommandIDs id, uint8_t value);
};


#endif //INC_2024_I_AV_SW_TEENSY_BOARD_HPP
