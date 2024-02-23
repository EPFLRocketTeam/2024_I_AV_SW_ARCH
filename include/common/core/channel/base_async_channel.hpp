//
// Created by Samuel on 23/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_ASYNC_CHANNEL_HPP
#define INC_2024_I_AV_SW_BASE_ASYNC_CHANNEL_HPP

#include "base_data_channel.hpp"


template<typename Packet, uint32_t MAX_PACKET_SIZE>
class BaseAsyncChannel : public virtual BaseDataChannel<Packet> {
public:
	void decode() override {}
	void events() override {
		if(event) {
			_callbackPtr(fromBytes(packet, packetLen));
			event = false;
		}
	}

protected:

	uint8_t packet[MAX_PACKET_SIZE];
	uint8_t packetLen = 0;
	bool event;

};

#endif //INC_2024_I_AV_SW_BASE_ASYNC_CHANNEL_HPP
