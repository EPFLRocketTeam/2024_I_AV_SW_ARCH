//
// Created by Samuel on 24/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_INTRANET_CHANNEL_HPP
#define INC_2024_I_AV_SW_BASE_INTRANET_CHANNEL_HPP

#include "base_data_channel.hpp"
#include "circular_buffer.hpp"

#define INTRANET_MAX_RAW_BUFFER_SIZE 2048
#define INTRANET_DATA_SIZE 63
#define INTRANET_PAYLOAD_SIZE (INTRANET_DATA_SIZE + 1)
#define INTRANET_CSC_IDX INTRANET_DATA_SIZE

#define INTRANET_RESERVE(n) uint8_t reserved[n];
#define INTRANET_FREE(n) INTRANET_RESERVE(INTRANET_DATA_SIZE - n);

struct intranet_packet_t {
	uint8_t id;
	union packet_data_t {
		uint8_t raw[INTRANET_PAYLOAD_SIZE];

		struct void_packet_t { // ID = 0
			INTRANET_FREE(0);
			uint8_t csc;
		} void_packet;

		struct sensor_response_packet_t { // ID = 1
			uint8_t sensorId;
			float x;
			float y;
			float z;
			bool valid;
			INTRANET_FREE(1+3*2+1)
			uint8_t csc;
		} sensor_response;

	} data;
};

enum IntranetParserState : uint8_t {
	ID,
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
class BaseIntranetChannel : public BaseDataChannel<intranet_packet_t> {
public:
	void tick();
	void writeSync(const intranet_packet_t& packet);
protected:
	bool readAvailable();
	bool writeAvailable();

	void decode();

	virtual void onRead(const intranet_packet_t& packet) = 0;

	intranet_packet_t fromBytes(uint8_t* bytesIn, uint32_t lenIn) override;
	uint32_t toBytes(const intranet_packet_t& packetIn, uint8_t* bytesOut) override;

protected:
	CircularBuffer<INTRANET_MAX_RAW_BUFFER_SIZE> readBuffer;
	CircularBuffer<INTRANET_MAX_RAW_BUFFER_SIZE> writeBuffer;

	IntranetParserState parserState = ID;
	uint8_t parserPayloadIdx = 0;

	uint8_t id{};
	uint8_t payload[INTRANET_PAYLOAD_SIZE]{};

	uint8_t computeCSC();
};

#endif //INC_2024_I_AV_SW_BASE_INTRANET_CHANNEL_HPP
