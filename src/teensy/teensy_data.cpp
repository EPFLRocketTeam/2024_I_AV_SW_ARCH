//
// Created by Samuel on 04/02/2024.
//

#include <type_traits>
#include "teensy_data.hpp"

template<INTRANET_TEMPLATE, SENSORS_TEMPLATE>
TeensyDataClass<INTRANET_WILDCARD, SENSORS_WILDCARD>::TeensyDataClass() {
	static_assert(std::is_base_of<TeensyIntranetClass<IntranetStatus>, IntranetClass<IntranetStatus>>::value, "IntranetClass must be a subclass fo TeensyIntranetClass");
	static_assert(std::is_base_of<TeensySensorsClass<SensorsStatus>, SensorsClass<SensorsStatus>>::value, "SensorsClass must be a subclass fo TeensySensorsClass");
}

template<INTRANET_TEMPLATE, SENSORS_TEMPLATE>
DataStatus<IntranetStatus, SensorsStatus> TeensyDataClass<INTRANET_WILDCARD, SENSORS_WILDCARD>::get() {
	return {
		.intra = intra.get(),
		.sens = sens.get(),
	};
}

template<INTRANET_TEMPLATE, SENSORS_TEMPLATE>
void TeensyDataClass<INTRANET_WILDCARD, SENSORS_WILDCARD>::compute() {
	intra.compute();
	sens.compute();
}