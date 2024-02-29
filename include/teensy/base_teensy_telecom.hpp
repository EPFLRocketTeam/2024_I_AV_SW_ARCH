//
// Created by Samuel on 29/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_TEENSY_TELECOM_HPP
#define INC_2024_I_AV_SW_BASE_TEENSY_TELECOM_HPP

#include <cstdint>
#include "core/channel/base_data_channel.hpp"

template<typename TeensyTelecomMemory, typename TeensyTelecomPacket>
class BaseTeensyTelecom : public virtual BaseDataChannel<TeensyTelecomPacket> {
public:
	// Get the current state of the telecom memory
	// The telecom memory SHOULD NOT contain raw buffered data
	virtual TeensyTelecomMemory get() = 0;

	// Checks whether a new command was received
	virtual bool isCommandUpdated() = 0;

	// Checks which command is currently held in memory
	virtual bool isCommand(const uint8_t& command) = 0;

	// Synchronous update
	virtual void tick() = 0;

};

#endif //INC_2024_I_AV_SW_BASE_TEENSY_TELECOM_HPP
