//
// Created by Samuel on 24/02/2024.
//

#include <cstring>
#include "channel/base_intranet_channel.hpp"

void BaseIntranetChannel::tick(){
	// sync read from buffer
	while(readAvailable())
		decode();

}

void BaseIntranetChannel::writeSync(const intranet_packet_t &packet) {
	writeBuffer.pushBack(packet.id);

	for(unsigned char p : packet.data.payload)
		writeBuffer.pushBack(p);
}

bool BaseIntranetChannel::readAvailable() {
	return readBuffer.isDataAvailable();
}

bool BaseIntranetChannel::writeAvailable() {
	return writeBuffer.isDataAvailable();
}

void BaseIntranetChannel::decode() {
	uint8_t byte = readBuffer.popFront();

	switch(parserState) {
		case ID:
			id = byte;
			parserState = PAYLOAD;
			memset(payload, 0, INTRANET_PAYLOAD_SIZE);
			break;
		case PAYLOAD:
			payload[parserPayloadIdx++] = byte;

			if(parserPayloadIdx >= INTRANET_DATA_SIZE)
				parserState = CSC;

			break;
		case CSC:
			payload[INTRANET_CSC_IDX] = byte;
			if(payload[INTRANET_CSC_IDX] == computeCSC()) {
				intranet_packet_t packet{};
				packet.id = id;
				memmove(packet.data.payload, payload, INTRANET_PAYLOAD_SIZE);
				onRead(packet);
			}
			parserState = ID;
			break;
	}
}

uint8_t BaseIntranetChannel::computeCSC() {
	uint8_t u = 0;

	for(uint32_t i = 0; i < INTRANET_DATA_SIZE; i++)
		u += payload[i];

	return u;
}

intranet_packet_t BaseIntranetChannel::fromBytes(uint8_t *bytesIn, uint32_t lenIn) {
	if(lenIn != sizeof(intranet_packet_t))
		return intranet_packet_t{};

	intranet_packet_t packet{};
	packet.id = bytesIn[0];
	memcpy(packet.data.payload, &(bytesIn[1]), INTRANET_PAYLOAD_SIZE);

	return packet;
}

uint32_t BaseIntranetChannel::toBytes(const intranet_packet_t &packetIn, uint8_t *bytesOut) {
	if(bytesOut)
		return 0; // Array should not be created outside the function

	bytesOut = new uint8_t[sizeof(intranet_packet_t)];

	bytesOut[0] = packetIn.id;
	memcpy(&(bytesOut[1]), packetIn.data.payload, INTRANET_PAYLOAD_SIZE);

	return 1 + INTRANET_PAYLOAD_SIZE;
}
