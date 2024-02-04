//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_DATA_HPP
#define INC_2024_I_AV_SW_RPI_DATA_HPP

#include "rpi_intranet.hpp"
#include "rpi_telecom.hpp"

template<typename IntranetStatus, typename TelecomStatus>
struct DataStatus {
	IntranetStatus intra;
	TelecomStatus tele;
};

template<INTRANET_TEMPLATE, TELECOM_TEMPLATE>
class RpiDataClass {
protected:

public:
	explicit RpiDataClass();
	IntranetClass<IntranetStatus> intra;
	TelecomClass<TelecomStatus> tele;

	DataStatus<IntranetStatus, TelecomStatus> get();
	virtual void compute();
};

#endif //INC_2024_I_AV_SW_RPI_DATA_HPP
