//
// Created by Samuel on 04/02/2024.
//

#include "rpi_data.hpp"

RpiDataStruct RpiDataClass::get() {
	return RpiDataStruct {
		.com = com.get(),
		.out = out.get(),
	};
}
