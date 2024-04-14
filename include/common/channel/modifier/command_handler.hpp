//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_COMMAND_HANDLER_HPP
#define INC_2024_I_AV_SW_COMMAND_HANDLER_HPP

#include "common/types.hpp"

class CommandHandler {
protected:
	CommandID comId = CMD_NONE;
	CommandID lastComId = CMD_NONE;
	uint8_t comVal = 0;
public:
	bool isCommandUpdated();
	bool isCommand(CommandID id);
	void resetCommand();
};


#endif //INC_2024_I_AV_SW_COMMAND_HANDLER_HPP
