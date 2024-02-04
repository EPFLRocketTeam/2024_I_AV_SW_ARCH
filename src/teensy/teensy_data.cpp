//
// Created by Samuel on 04/02/2024.
//

#include "teensy_data.hpp"

template<class IntranetClass, typename IntranetStatus, class SensorsClass, typename SensorsStatus>
DataStatus<IntranetStatus, SensorsStatus> TeensyDataClass<IntranetClass, IntranetStatus, SensorsClass, SensorsStatus>::get() {
	return {
		.intra = intra.get(),
		.sens = sens.get(),
	};
}

template<class IntranetClass, typename IntranetStatus, class SensorsClass, typename SensorsStatus>
void
TeensyDataClass<IntranetClass, IntranetStatus, SensorsClass, SensorsStatus>::compute() {
	intra.compute();
	sens.compute();
}