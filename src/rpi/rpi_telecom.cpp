//
// Created by Samuel on 04/02/2024.
//

#include "rpi_telecom.hpp"
#include "logger.hpp"

RpiTelecomStatus RpiTelecomClass::get() {
	LOG("RpiTelecomClass::get > OVERRIDE ME !");
	return {};
}

void RpiTelecomClass::compute() {
	LOG("RpiTelecomClass::compute > OVERRIDE ME !");

}
