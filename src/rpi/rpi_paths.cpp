//
// Created by Samuel on 04/02/2024.
//

#include "rpi_paths.hpp"

RpiPathsStruct RpiPathsClass::get() {
	return RpiPathsStruct {
		.ctrl = ctrl.get(),
		.out = out.get(),
	};
}

void RpiPathsClass::update() {
	ctrl.update();
	out.update();

}
