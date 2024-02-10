//
// Created by Samuel on 10/02/2024.
//

#ifndef INC_2024_I_AV_SW_MAG_SENSOR_HPP
#define INC_2024_I_AV_SW_MAG_SENSOR_HPP

#include "base_sensor.hpp"

struct MagData {
	bool valid;
	double mx;
	double my;
	double mz;
};

class BaseMagnetometer: public virtual BaseSensor<MagData> {
private:
	unsigned pollingRate;
	unsigned axis;
protected:
public:
	BaseMagnetometer(unsigned pollingRateIn) : pollingRate(pollingRateIn), axis(3) {}

	unsigned int getAxis() override { return axis; }
	unsigned int getPollingRate() override { return pollingRate; }
};

#endif //INC_2024_I_AV_SW_MAG_SENSOR_HPP
