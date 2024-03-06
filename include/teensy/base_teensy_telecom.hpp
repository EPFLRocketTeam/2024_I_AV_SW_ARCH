//
// Created by Samuel on 29/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_TEENSY_TELECOM_HPP
#define INC_2024_I_AV_SW_BASE_TEENSY_TELECOM_HPP

#include <cstdint>
#include "channel/base_data_channel.hpp"
#include "channel/modifier/command_handler.hpp"

template<typename TeensyTelecomMemory, typename TeensyTelecomPacket>
class BaseTeensyTelecom : public virtual BaseDataChannel<TeensyTelecomPacket>, public virtual CommandHandler {
public:
	// Get the current state of the telecom memory
	// The telecom memory SHOULD NOT contain raw buffered data
	virtual TeensyTelecomMemory get() = 0;

	// Synchronous update
	virtual void tick() = 0;

};

#endif //INC_2024_I_AV_SW_BASE_TEENSY_TELECOM_HPP
