//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_SENSORS_HPP
#define INC_2024_I_AV_SW_TEENSY_SENSORS_HPP

struct TeensySensorsStatus {

};

class TeensySensorsClass {
public:
	virtual TeensySensorsStatus get();
	virtual void compute();

};


#endif //INC_2024_I_AV_SW_TEENSY_SENSORS_HPP
