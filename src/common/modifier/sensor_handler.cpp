//
// Created by Samuel on 05/02/2024.
//

#include "modifier/sensor_handler.hpp"
#include "logger.hpp"

template<typename SensorSetStatus>
SensorSetStatus SensorSetHandler<SensorSetStatus>::get() {
	LOG("SensorSetHandler::get > OVERRIDE ME !");
	return {};
}

template<typename SensorSetStatus>
void SensorSetHandler<SensorSetStatus>::calibrate() {
	LOG("SensorSetHandler::calibrate > OVERRIDE ME !");
}

template<typename SensorSetStatus>
void SensorSetHandler<SensorSetStatus>::fetchRaw() {
	LOG("SensorSetHandler::fetchRaw > OVERRIDE ME !");
}

template<uint8_t n>
AccelSetStatus<n> AccelHandler<n>::get() {
	return {
		.data = accelData,
		.bias = accelBias,
		.noise = accelNoise,
		.drift = accelDrift,
		.rate = accelRate,
		.updated = accelUpdated,
	};
}

template<uint8_t n>
GyroSetStatus<n> GyroHandler<n>::get() {
	return {
		.data = gyroData,
		.bias = gyroBias,
		.noise = gyroNoise,
		.drift = gyroDrift,
		.rate = gyroRate,
		.updated = gyroUpdated,
	};
}

template<uint8_t n>
BaroSetStatus<n> BaroHandler<n>::get() {
	return {
		.data = baroData,
		.bias = baroBias,
		.noise = baroNoise,
		.drift = baroDrift,
		.rate = baroRate,
		.updated = baroUpdated,
	};
}
