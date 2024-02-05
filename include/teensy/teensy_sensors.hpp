//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_SENSORS_HPP
#define INC_2024_I_AV_SW_TEENSY_SENSORS_HPP

#include "modifier/data_component.hpp"

#define SENSORS_TEMPLATE template<typename> class SensorsClass, typename SensorsStatus
#define SENSORS_WILDCARD SensorsClass, SensorsStatus

template <typename SensorsStatus>
class TeensySensorsClass : public DataComponent<SensorsStatus> {
public:
	void compute(SystemStatus) override;
	void fetchData();
	void calibrate();
};


#endif //INC_2024_I_AV_SW_TEENSY_SENSORS_HPP
