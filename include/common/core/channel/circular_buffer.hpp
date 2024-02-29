//
// Created by Samuel on 24/02/2024.
//

#ifndef INC_2024_I_AV_SW_CIRCULAR_BUFFER_HPP
#define INC_2024_I_AV_SW_CIRCULAR_BUFFER_HPP

class CircularBuffer {
public:
	void pushBack(const uint8_t& byte);
	uint8_t popFront();
	bool isDataAvailable();
};

#endif //INC_2024_I_AV_SW_CIRCULAR_BUFFER_HPP
