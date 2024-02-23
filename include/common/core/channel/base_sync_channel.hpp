//
// Created by Samuel on 23/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_SYNC_CHANNEL_HPP
#define INC_2024_I_AV_SW_BASE_SYNC_CHANNEL_HPP

#include "base_data_channel.hpp"

template<typename Packet, typename PacketMetadata, uint32_t MAX_PAYLOAD_SIZE>
class BaseSyncChannel : public virtual BaseDataChannel<Packet> {
public:
	void events() override {}
protected:
	uint8_t parserStatus = 0;
	PacketMetadata metadata;
	uint8_t packetPayload[MAX_PAYLOAD_SIZE]{};
	uint32_t parserPayloadIdx = 0;
};

#endif //INC_2024_I_AV_SW_BASE_SYNC_CHANNEL_HPP
