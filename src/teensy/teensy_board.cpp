//
// Created by Samuel on 04/02/2024.
//
#include "teensy_board.hpp"
#include "config.hpp"

template<class DataClass>
FSMState TeensyBoard<DataClass>::getNextState() {

	// The teensy does not have its own FMS. It tracks that of the Teensy (master).
	// The Tracking is done via commands sent by the Teensy to the Teensy

	if (data.intra.isCommandUpdated() && data.intra.isCommand(CMD_STATE)) {
		auto nextState = (FSMState) data.get().intra.comId;
		data.intra.resetCommand();
		return nextState;
	}

	return sys.get().state;
}