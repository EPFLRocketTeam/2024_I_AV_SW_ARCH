//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_COMMAND_RECEIVER_HPP
#define INC_2024_I_AV_SW_COMMAND_RECEIVER_HPP

#include <cstdint>

template<typename CommandIDs>
class CommandReceiver {
protected:
	CommandIDs comId = 0;
	CommandIDs lastComId = 0;
	uint8_t comVal = 0;
public:
	bool isCommandUpdated();
	bool isCommand(CommandIDs id);
	void resetCommand();
};


#endif //INC_2024_I_AV_SW_COMMAND_RECEIVER_HPP
