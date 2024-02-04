//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_BOARD_HPP
#define INC_2024_I_AV_SW_TEENSY_BOARD_HPP

#include "base_board.hpp"
#include "teensy_data.hpp"

class TeensyBoard : public BaseBoard {
protected:
	TeensyDataClass data;
public:
	FSMState getNextState() override;
};


#endif //INC_2024_I_AV_SW_TEENSY_BOARD_HPP
