//
// Created by Samuel on 05/02/2024.
//

#ifndef INC_2024_I_AV_SW_SENSOR_HANDLER_HPP
#define INC_2024_I_AV_SW_SENSOR_HANDLER_HPP

#include <cstdint>
#include "config.hpp"

template<typename SensorSetStatus>
class SensorSetHandler {
public:
	virtual SensorSetStatus get();
	virtual void calibrate();
	virtual void fetchRaw();
};

template<uint8_t n>
struct AccelSetStatus {
	Vect3 data[n];
	Vect3 bias[n];
	Vect3 noise[n];
	scalar drift[n];
	uint16_t rate;
	bool updated;
};

template<uint8_t n>
class AccelHandler: SensorSetHandler<AccelSetStatus<n>> {

protected:
	Vect3 accelData[n]{};
	Vect3 accelBias[n]{};
	Vect3 accelNoise[n]{};
	scalar accelDrift[n]{};
	bool accelUpdated = false;
	uint8_t accelRate;
public:
	explicit AccelHandler(uint16_t rateIn) : accelRate(rateIn) {}
	AccelSetStatus<n> get() override;
};

template<uint8_t n>
struct GyroSetStatus {
	Vect3 data[n];
	Vect3 bias[n];
	Vect3 noise[n];
	scalar drift[n];
	uint16_t rate;
	bool updated;
};

template<uint8_t n>
class GyroHandler: SensorSetHandler<GyroSetStatus<n>> {

protected:
	Vect3 gyroData[n]{};
	Vect3 gyroBias[n]{};
	Vect3 gyroNoise[n]{};
	scalar gyroDrift[n]{};
	bool gyroUpdated = false;
	uint8_t gyroRate;
public:
	explicit GyroHandler(uint16_t rateIn) : gyroRate(rateIn) {}
	GyroSetStatus<n> get() override;
};

template<uint8_t n>
struct BaroSetStatus {
	scalar data[n];
	scalar bias[n];
	scalar noise[n];
	scalar drift[n];
	uint16_t rate;
	bool updated;
};

template<uint8_t n>
class BaroHandler: SensorSetHandler<BaroSetStatus<n>> {

protected:
	scalar baroData[n]{};
	scalar baroBias[n]{};
	scalar baroNoise[n]{};
	scalar baroDrift[n]{};
	bool baroUpdated = false;
	uint8_t baroRate;
public:
	explicit BaroHandler(uint16_t rateIn) : baroRate(rateIn) {}
	BaroSetStatus<n> get() override;
};

// TODO MAGNETO
// TODO GNSS

#endif //INC_2024_I_AV_SW_SENSOR_HANDLER_HPP
