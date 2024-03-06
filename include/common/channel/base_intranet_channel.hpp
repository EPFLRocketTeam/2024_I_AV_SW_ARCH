//
// Created by Samuel on 24/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_INTRANET_CHANNEL_HPP
#define INC_2024_I_AV_SW_BASE_INTRANET_CHANNEL_HPP

#include "base_data_channel.hpp"
#include "circular_buffer.hpp"

#define INTRANET_MAX_RAW_BUFFER_SIZE 2048
#define INTRANET_MAX_PAYLOAD_SIZE 256
#define INTRANET_METADATA_BYTES 3

struct IntranetPacket {
	uint8_t id;
	uint8_t len;
	uint8_t csc;
	uint8_t payload[INTRANET_MAX_PAYLOAD_SIZE];
};

enum IntranetParserState : uint8_t {
	ID,
	LEN,
	PAYLOAD,
	CSC,
};

/**
 * BaseIntranetChannel is the abstract class that all "board-bound" Intranet implementations derive from.
 * The Intranet is a full-duplex communication channel.
 * \n\n
 * Read operations:
 * - inbound data is read asynchronously and store as-is (raw) in the read buffer.
 * - during each loop iteration, the buffer is read synchronously and the data is processed into IntranetPacket via the <strong>decode</strong> method
  * \n\n
 * Write operations are dependant on the master/slave role of the board. A buffer system similar to read operations is available.
 */
class BaseIntranetChannel : public BaseDataChannel<IntranetPacket> {
public:
	void tick();
	void write(const IntranetPacket& packet);
protected:
	bool readAvailable();
	bool writeAvailable();

	void decode();
	void encode();

	virtual void onRead(const IntranetPacket& packet) = 0;

	IntranetPacket fromBytes(uint8_t* bytesIn, uint32_t lenIn) override;
	uint32_t toBytes(const IntranetPacket& packetIn, uint8_t* bytesOut) override;

protected:
	CircularBuffer<INTRANET_MAX_RAW_BUFFER_SIZE> readBuffer;
	CircularBuffer<INTRANET_MAX_RAW_BUFFER_SIZE> writeBuffer;

	IntranetParserState parserState = ID;
	uint8_t parserPayloadIdx = 0;

	uint8_t id{};
	uint8_t len{};
	uint8_t csc{};
	uint8_t payload[INTRANET_MAX_PAYLOAD_SIZE]{};

	uint8_t computeCSC();
};

#endif //INC_2024_I_AV_SW_BASE_INTRANET_CHANNEL_HPP
