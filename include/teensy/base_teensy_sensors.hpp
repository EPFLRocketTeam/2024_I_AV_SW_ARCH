//
// Created by Philip on 27/03/2024.
//

#include <cstdint>
#include "channel/base_data_channel.hpp"
#include "channel/sensor_data.hpp"



template<class I2CInterface, class BNOSensor, class BMPSensor, class GNSSSensor, typename Packet>
class BaseTeensySensors : public virtual BaseDataChannel<Packet> {
public:
    void initializeDrivers() {
        i2CInterface.begin();
        bno.init();
        bmp.init();
        gnss.init();
    }
    void tick();
    SensorData getSensorData(SENSOR_TYPE sensorType) {
        switch (sensorType) {
            case BNO:
                return bnoCalibrationData.get();
            case BMP:
                return bmpCalibrationData.get();
            case GNSS:
                return gnssCalibrationData.get();
        }
    }
    void calibrate(SENSOR_TYPE sensorType);


protected:
    void setMean(SENSOR_TYPE sensorType, float meanIn) {
        switch (sensorType) {
            case BNO:
                return bnoCalibrationData.setMean(meanIn);
            case BMP:
                return bmpCalibrationData.setMean(meanIn);
            case GNSS:
                return gnssCalibrationData.setMean(meanIn);
        }
    }
    void setVariance(SENSOR_TYPE sensorType, float varianceIn) {
        switch (sensorType) {
            case BNO:
                return bnoCalibrationData.setVariance(varianceIn);
            case BMP:
                return bmpCalibrationData.setVariance(varianceIn);
            case GNSS:
                return gnssCalibrationData.setVariance(varianceIn);
        }
    }
    void setPollingRate(SENSOR_TYPE sensorType, int pollingRateIn) {
        switch (sensorType) {
            case BNO:
                return bnoCalibrationData.setPollingRate(pollingRateIn);
            case BMP:
                return bmpCalibrationData.setPollingRate(pollingRateIn);
            case GNSS:
                return gnssCalibrationData.setPollingRate(pollingRateIn);
        }
    }

protected:
    I2CInterface* i2CInterface;
    BNOSensor* bno;
    BMPSensor* bmp;
    GNSSSensor* gnss;

    SensorDataClass bnoData = SensorDataClass();
    SensorDataClass bmpData = SensorDataClass();
    SensorDataClass gnssData = SensorDataClass();

};