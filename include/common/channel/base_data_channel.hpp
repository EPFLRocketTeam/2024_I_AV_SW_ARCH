//
// Created by Samuel on 23/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_DATA_CHANNEL_HPP
#define INC_2024_I_AV_SW_BASE_DATA_CHANNEL_HPP

#include <cstdint>

/**
 * BaseDataChannel is the interface describing all potential communication channels within the AV and with external Systems.
 *
 * @tparam Packet: the packet struct that passes through the channel
 */
template<typename Packet>
class BaseDataChannel {
protected:
	virtual Packet fromBytes(uint8_t* bytesIn, uint32_t lenIn) = 0;
	virtual uint32_t toBytes(const Packet& packetIn, uint8_t* bytesOut) = 0;

	virtual bool readByte(uint8_t& byte) = 0;
	virtual bool writeByte(const uint8_t& byte) = 0;
};


#endif //INC_2024_I_AV_SW_BASE_DATA_CHANNEL_HPP
