//
// Created by Philip on 27/03/2024.
//

#include <cstdint>
#include <cstdlib>
#include "channel/base_data_channel.hpp"

template<class I2CInterface, typename SensorSetData, typename SensorSetCalibration>
class BaseTeensySensors {
public:
    BaseTeensySensors(I2CInterface* i2cIn) : i2c(i2cIn) {}
    virtual void init() = 0;

    virtual void tick() = 0;
    virtual void calibrate() = 0;

	virtual void get_raw_data(SensorSetData* memory) = 0;
	virtual void get_calibration_data(SensorSetCalibration* memory) = 0;

protected:
    I2CInterface* i2c;
};