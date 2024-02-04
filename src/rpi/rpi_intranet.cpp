//
// Created by Samuel on 04/02/2024.
//

#include "rpi_intranet.hpp"
#include "logger.hpp"


RpiIntranetStatus RpiIntranetClass::get() {
	LOG("RpiIntranetClass::get > OVERRIDE ME !");
	return {};
}

void RpiIntranetClass::compute() {
	LOG("RpiIntranetClass::compute > OVERRIDE ME !");
}
