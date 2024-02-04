//
// Created by Samuel on 04/02/2024.
//

#include "teensy_data.hpp"

TeensyDataStatus TeensyDataClass::get() {
	return TeensyDataStatus{
		.com = com.get(),
		.out = out.get(),
	};
}
