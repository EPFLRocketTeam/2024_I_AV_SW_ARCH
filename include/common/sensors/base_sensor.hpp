//
// Created by Samuel on 10/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_SENSOR_HPP
#define INC_2024_I_AV_SW_BASE_SENSOR_HPP

template<typename SensorData>
class BaseSensor {
	virtual unsigned getAxis() = 0;
	virtual unsigned getPollingRate() = 0;
	virtual bool isDataValid() = 0;
	virtual bool poll(SensorData& out) = 0;
};

#endif //INC_2024_I_AV_SW_BASE_SENSOR_HPP
