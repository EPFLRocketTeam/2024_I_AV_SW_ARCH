//
// Created by Samuel on 04/02/2024.
//

#include "teensy_paths.hpp"

TeensyPathsStatus TeensyPathsClass::get() {
	return TeensyPathsStatus{
		.ctrl = ctrl.get(),
		.out = out.get(),
	};
}

void TeensyPathsClass::update() {
	ctrl.update();
	out.update();

}
