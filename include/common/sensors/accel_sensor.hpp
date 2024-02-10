//
// Created by Samuel on 10/02/2024.
//

#ifndef INC_2024_I_AV_SW_ACCEL_SENSOR_HPP
#define INC_2024_I_AV_SW_ACCEL_SENSOR_HPP

#include "base_sensor.hpp"

struct AccelData {
	bool valid;
	double ax;
	double ay;
	double az;
};

class BaseAccelerometer : public virtual BaseSensor<AccelData> {
private:
	unsigned pollingRate;
	unsigned axis;
protected:
public:
	BaseAccelerometer(unsigned pollingRateIn) : pollingRate(pollingRateIn), axis(3) {}

	unsigned int getAxis() override { return axis; }
	unsigned int getPollingRate() override { return pollingRate; }
};

#endif //INC_2024_I_AV_SW_ACCEL_SENSOR_HPP
