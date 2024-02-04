//
// Created by Samuel on 04/02/2024.
//
#include "teensy_board.hpp"
#include "logger.hpp"

FSMState TeensyBoard::getNextState() {
	LOG("TeensyBoard::getNextState > OVERRIDE ME");
	return ABORT_STATE;
}
