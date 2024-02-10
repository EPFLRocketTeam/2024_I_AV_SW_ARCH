//
// Created by Samuel on 10/02/2024.
//

#ifndef INC_2024_I_AV_SW_GNSS_SENSOR_HPP
#define INC_2024_I_AV_SW_GNSS_SENSOR_HPP

#include "base_sensor.hpp"

struct GNSSData {
	bool valid;
	double px;
	double py;
	double pz;
	double vx;
	double vy;
	double vz;
};

class BaseAccelerometer : public virtual BaseSensor<GNSSData> {
private:
	unsigned pollingRate;
	unsigned axis;
protected:
public:
	BaseAccelerometer(unsigned pollingRateIn) : pollingRate(pollingRateIn), axis(6) {}

	unsigned int getAxis() override { return axis; }
	unsigned int getPollingRate() override { return pollingRate; }
};

#endif //INC_2024_I_AV_SW_GNSS_SENSOR_HPP
