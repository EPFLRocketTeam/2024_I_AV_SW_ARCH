//
// Created by Samuel on 23/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_DATA_CHANNEL_HPP
#define INC_2024_I_AV_SW_BASE_DATA_CHANNEL_HPP

#include <cstdint>

template<typename Packet>
class BaseDataChannel {
public:
	typedef void (*CALLBACK_PTR)(const Packet &packet);

	virtual void decode() = 0;
	virtual void events() = 0;

	virtual Packet fromBytes(uint8_t* bytesIn, uint32_t lenIn) = 0;
	virtual uint32_t toBytes(const Packet& packetIn, uint8_t* bytesOut) = 0;

	CALLBACK_PTR _callbackPtr = nullptr;

	void onReceive(CALLBACK_PTR callbackPtr) { _callbackPtr = callbackPtr; }

	virtual bool readByte(uint8_t& byte) = 0;
	virtual bool write(const uint8_t& byte) = 0;
	virtual bool write(const uint16_t& byte) = 0;
	virtual bool write(const uint32_t& byte) = 0;
	virtual bool write(const uint64_t& byte) = 0;
	virtual bool write(const float& byte) = 0;
	virtual bool write(const double& byte) = 0;
	virtual bool write(const long double& byte) = 0;

	uint8_t csc(const uint8_t* buffer, uint32_t len) {
		uint8_t csc = 0x00;
		for (int i = 0; i < len; i++)
			csc += buffer[i];
		return csc;
	}
};


#endif //INC_2024_I_AV_SW_BASE_DATA_CHANNEL_HPP
