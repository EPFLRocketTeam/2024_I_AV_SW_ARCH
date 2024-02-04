//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_TELECOM_HPP
#define INC_2024_I_AV_SW_RPI_TELECOM_HPP

#include "config.hpp"
#include "modifier/command_receiver.hpp"

struct RpiTelecomStatus {
	CommandID comId;
	uint8_t comVal;
};

class RpiTelecomClass : public CommandReceiver {
protected:
public:
	virtual RpiTelecomStatus get();
	virtual void compute();
};

#endif //INC_2024_I_AV_SW_RPI_TELECOM_HPP
