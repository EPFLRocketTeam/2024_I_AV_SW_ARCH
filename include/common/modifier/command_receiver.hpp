//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_COMMAND_RECEIVER_HPP
#define INC_2024_I_AV_SW_COMMAND_RECEIVER_HPP

#include "config.hpp"

class CommandReceiver {
protected:
	CommandID comId = CMD_NONE;
	CommandID lastComId = CMD_NONE;
	uint8_t comVal = 0;
public:
	bool isCommandUpdated();
	bool isCommand(CommandID id);
	void resetCommand();
};


#endif //INC_2024_I_AV_SW_COMMAND_RECEIVER_HPP
