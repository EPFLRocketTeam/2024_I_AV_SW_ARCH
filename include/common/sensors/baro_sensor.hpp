//
// Created by Samuel on 10/02/2024.
//

#ifndef INC_2024_I_AV_SW_BARO_SENSOR_HPP
#define INC_2024_I_AV_SW_BARO_SENSOR_HPP

#include "base_sensor.hpp"

struct BaroData {
	bool valid;
	double h;
};

class BaseBarometer: public virtual BaseSensor<BaroData> {
private:
	unsigned pollingRate;
	unsigned axis;
protected:
public:
	BaseBarometer(unsigned pollingRateIn) : pollingRate(pollingRateIn), axis(1) {}

	unsigned int getAxis() override { return axis; }
	unsigned int getPollingRate() override { return pollingRate; }
};

#endif //INC_2024_I_AV_SW_BARO_SENSOR_HPP
