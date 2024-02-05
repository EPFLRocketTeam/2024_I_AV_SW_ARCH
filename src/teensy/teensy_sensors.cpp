//
// Created by Samuel on 05/02/2024.
//

#include "teensy_sensors.hpp"
#include "logger.hpp"

template<typename SensorsStatus>
void TeensySensorsClass<SensorsStatus>::compute(SystemStatus sys) {
	if(sys.state == CALIBRATION_STATE) {
		calibrate();
		return;
	}

	fetchData();
}

template<typename SensorsStatus>
void TeensySensorsClass<SensorsStatus>::calibrate() {
	LOG("TeensySensorsClass::calibrate > OVERRIDE ME !");
}

template<typename SensorsStatus>
void TeensySensorsClass<SensorsStatus>::fetchData() {
	LOG("TeensySensorsClass::fetchData > OVERRIDE ME !");
}