//
// Created by Samuel on 24/02/2024.
//

#include <cstring>
#include "channel/base_intranet_channel.hpp"

void BaseIntranetChannel::tick(){
	// sync read from buffer
	while(readAvailable())
		decode();

	while(writeAvailable())
		encode();
}

void BaseIntranetChannel::write(const IntranetPacket &packet) {
	uint8_t* bytes;
	uint32_t len = toBytes(packet, bytes);
	for(uint32_t i = 0; i < len; i++)
		writeBuffer.pushBack(bytes[i]);
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
			len = 0;
			csc = 0;
			parserState = LEN;
			break;
		case LEN:
			len = byte;
			parserPayloadIdx = 0;
			parserState = PAYLOAD;
			break;
		case PAYLOAD:
			if(parserPayloadIdx < len)
				payload[parserPayloadIdx++] = byte;

			if(parserPayloadIdx >= len)
				parserState = CSC;

			break;
		case CSC:
			csc = byte;
			if(csc == computeCSC()) {
				IntranetPacket packet{.id = id, .len = len, .csc = csc};
				memmove(packet.payload, payload, len);
				onRead(packet);
			}
			parserState = ID;
			break;
	}
}

void BaseIntranetChannel::encode() {
	uint8_t byte = writeBuffer.popFront();
	writeByte(byte);
}

uint8_t BaseIntranetChannel::computeCSC() {
	uint8_t u = 0;

	for(uint32_t i = 0; i < len; i++)
		u += payload[i];

	return u;
}

IntranetPacket BaseIntranetChannel::fromBytes(uint8_t *bytesIn, uint32_t lenIn) {
	if(lenIn < INTRANET_METADATA_BYTES)
		return {};

	IntranetPacket packet{};
	packet.id = bytesIn[0];
	packet.len = bytesIn[1];
	packet.csc = bytesIn[2];
	memcpy(packet.payload, &(bytesIn[3]), packet.len);

	return packet;
}

uint32_t BaseIntranetChannel::toBytes(const IntranetPacket &packetIn, uint8_t *bytesOut) {
	if(bytesOut)
		return 0; // Array should not be created outside the function

	bytesOut = new uint8_t[packetIn.len + INTRANET_METADATA_BYTES];

	bytesOut[0] = packetIn.id;
	bytesOut[1] = packetIn.len;
	bytesOut[2] = packetIn.csc;
	memcpy(&(bytesOut[3]), packetIn.payload, packetIn.len);

	return packetIn.len + INTRANET_METADATA_BYTES;
}
