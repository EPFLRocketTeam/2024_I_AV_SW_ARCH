//
// Created by Samuel on 24/02/2024.
//

#ifndef INC_2024_I_AV_SW_CIRCULAR_BUFFER_HPP
#define INC_2024_I_AV_SW_CIRCULAR_BUFFER_HPP

#include <cstdint>

template<size_t MAX_SIZE>
class CircularBuffer {
private:
	uint8_t buffer[MAX_SIZE];
	uint32_t head = 0;
	uint32_t tail = 0;
	uint32_t size = 0;

public:
	void pushBack(const uint8_t& byte);
	uint8_t popFront();
	bool isDataAvailable();
};

template<size_t MAX_SIZE>
void CircularBuffer<MAX_SIZE>::pushBack(const uint8_t &byte) {
	buffer[tail] = byte;
	tail = (tail + 1) & (MAX_SIZE - 1);
	size++;
}

template<size_t MAX_SIZE>
uint8_t CircularBuffer<MAX_SIZE>::popFront() {
	uint8_t byte = buffer[head];
	head = (head + 1) & (MAX_SIZE - 1);
	size--;
	return byte;
}

template<size_t MAX_SIZE>
bool CircularBuffer<MAX_SIZE>::isDataAvailable() {
	return size > 0;
}

#endif //INC_2024_I_AV_SW_CIRCULAR_BUFFER_HPP
