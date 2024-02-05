//
// Created by Samuel on 04/02/2024.
//

#include "rpi_data.hpp"
#include <type_traits>

template<INTRANET_TEMPLATE, TELECOM_TEMPLATE>
RpiDataClass<INTRANET_WILDCARD, TELECOM_WILDCARD>::RpiDataClass() {
	static_assert(std::is_base_of<RpiIntranetClass<IntranetStatus>, IntranetClass<IntranetStatus>>::value, "IntranetClass must be a subclass fo RpiIntranetClass");
	static_assert(std::is_base_of<RpiTelecomClass<TelecomStatus>, TelecomClass<TelecomStatus>>::value, "TelecomClass must be a subclass fo RpiTelecomClass");
}

template<INTRANET_TEMPLATE, TELECOM_TEMPLATE>
DataStatus<IntranetStatus, TelecomStatus> RpiDataClass<INTRANET_WILDCARD, TELECOM_WILDCARD>::get() {
	return {
		.intra = intra.get(),
		.tele = tele.get(),
	};
}

template<INTRANET_TEMPLATE, TELECOM_TEMPLATE>
void RpiDataClass<INTRANET_WILDCARD, TELECOM_WILDCARD>::compute() {
	intra.compute();
	tele.compute();
}

