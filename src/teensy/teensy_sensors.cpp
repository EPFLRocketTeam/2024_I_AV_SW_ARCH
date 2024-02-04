//
// Created by Samuel on 04/02/2024.
//

#include "teensy_sensors.hpp"
#include "logger.hpp"

TeensySensorsStatus TeensySensorsClass::get() {
	LOG("TeensySensorsClass::get > OVERRIDE ME !");
	return {};
}

void TeensySensorsClass::compute() {
	LOG("TeensySensorsClass::compute > OVERRIDE ME !");
}
