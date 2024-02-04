//
// Created by Samuel on 04/02/2024.
//

#include "teensy_intranet.hpp"
#include "logger.hpp"

TeensyIntranetStatus TeensyIntranetClass::get() {
	LOG("TeensyIntranetClass::get > OVERRIDE ME !");
	return {};
}

void TeensyIntranetClass::compute() {
	LOG("TeensyIntranetClass::compute > OVERRIDE ME !");
}

