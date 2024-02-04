//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_BOARD_HPP
#define INC_2024_I_AV_SW_TEENSY_BOARD_HPP

#include "base_board.hpp"

template<class DataClass>
class TeensyBoard : public BaseBoard {
protected:
	DataClass data;
public:
	FSMState getNextState() override;
};


#endif //INC_2024_I_AV_SW_TEENSY_BOARD_HPP
