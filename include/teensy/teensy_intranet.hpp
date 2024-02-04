//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_INTRANET_HPP
#define INC_2024_I_AV_SW_TEENSY_INTRANET_HPP

#include "data/base_intranet.hpp"
#include "config.hpp"
#include "modifier/command_receiver.hpp"

struct TeensyIntranetStatus {
	CommandID comId;
	uint8_t comVal;
};

class TeensyIntranetClass : public CommandReceiver {
public:
	virtual TeensyIntranetStatus get();
	virtual void compute();
};

#endif //INC_2024_I_AV_SW_TEENSY_INTRANET_HPP
