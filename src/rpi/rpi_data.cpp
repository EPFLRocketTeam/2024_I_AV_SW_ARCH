//
// Created by Samuel on 04/02/2024.
//

#include "rpi_data.hpp"

template<class IntranetClass, typename IntranetStatus, class TelecomClass, typename TelecomStatus>
DataStatus<IntranetStatus, TelecomStatus> RpiDataClass<IntranetClass, IntranetStatus, TelecomClass, TelecomStatus>::get() {
	return {
		.intra = intra.get(),
		.tele = tele.get(),
	};
}

template<class IntranetClass, typename IntranetStatus, class TelecomClass, typename TelecomStatus>
void
RpiDataClass<IntranetClass, IntranetStatus, TelecomClass, TelecomStatus>::compute() {
	intra.compute();
	tele.compute();
}

