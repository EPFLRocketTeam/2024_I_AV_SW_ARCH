//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_DATA_HPP
#define INC_2024_I_AV_SW_TEENSY_DATA_HPP

#include "teensy_intranet.hpp"
#include "teensy_sensors.hpp"

template<typename IntranetStatus, typename SensorsStatus>
struct DataStatus {
	IntranetStatus intra;
	SensorsStatus sens;
};

template<INTRANET_TEMPLATE, SENSORS_TEMPLATE>
class TeensyDataClass {
public:
	explicit TeensyDataClass();
	IntranetClass<IntranetStatus> intra;
	SensorsClass<SensorsStatus> sens;

	DataStatus<IntranetStatus, SensorsStatus> get();
	virtual void compute();
};

#endif //INC_2024_I_AV_SW_TEENSY_DATA_HPP
