//
// Created by Samuel on 04/02/2024.
//

#include "data/base_intranet.hpp"
#include "logger.hpp"

template<typename IntranetStatus>
IntranetStatus BaseIntranetClass<IntranetStatus>::get() {
	LOG("BaseIntranetClass::get > OVERRIDE ME !");
	return IntranetStatus {

	};
}

template<typename IntranetStatus>
void BaseIntranetClass<IntranetStatus>::update() {
	LOG("BaseIntranetClass::compute > OVERRIDE ME !");
}