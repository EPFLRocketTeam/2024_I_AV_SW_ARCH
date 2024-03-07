//
// Created by Samuel on 29/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_TEENSY_TELECOM_HPP
#define INC_2024_I_AV_SW_BASE_TEENSY_TELECOM_HPP

#include <cstdint>
#include "channel/base_data_channel.hpp"
#include "channel/modifier/command_handler.hpp"

void teensy_handleTelemetryIn(int packetSize);
void teensy_handleTelemetryOut(int packetSize);

template<typename TeensyTelecomPacket>
class BaseTeensyTelecom : public virtual BaseDataChannel<TeensyTelecomPacket>, public virtual CommandHandler {
public:

	// init function
	virtual void init() = 0;

	// Synchronous update
	virtual void tick() = 0;

	// write packet to telemetry
	virtual void sendTelemetry(const TeensyTelecomPacket& packet) = 0;

};

#endif //INC_2024_I_AV_SW_BASE_TEENSY_TELECOM_HPP
