//
// Created by Samuel on 10/02/2024.
//

#ifndef INC_2024_I_AV_SW_GYRO_SENSOR_HPP
#define INC_2024_I_AV_SW_GYRO_SENSOR_HPP

#include "base_sensor.hpp"

struct GyroData {
	bool valid;
	double gx;
	double gy;
	double gz;
};

class BaseGyroscope : public virtual BaseSensor<GyroData> {
private:
	unsigned pollingRate;
	unsigned axis;
protected:
public:
	BaseGyroscope(unsigned pollingRateIn) : pollingRate(pollingRateIn), axis(3) {}

	unsigned int getAxis() override { return axis; }
	unsigned int getPollingRate() override { return pollingRate; }
};

#endif //INC_2024_I_AV_SW_GYRO_SENSOR_HPP
