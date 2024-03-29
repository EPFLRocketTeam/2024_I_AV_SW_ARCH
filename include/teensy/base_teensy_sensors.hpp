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
                return bnoData.get();
            case BMP:
                return bmpData.get();
            case GNSS:
                return gnssData.get();
        }
    }
    void calibrate(SENSOR_TYPE sensorType);
    void setPollingRate(SENSOR_TYPE sensorType, int pollingRateIn) {
        switch (sensorType) {
            case BNO:
                bnoData.setPollingRate(pollingRateIn);
                return ;
            case BMP:
                bmpData.setPollingRate(pollingRateIn);
                return;
            case GNSS:
                gnssData.setPollingRate(pollingRateIn);
                return;
        }
    }


protected:
    void setMean(SENSOR_TYPE sensorType, float meanIn) {
        switch (sensorType) {
            case BNO:
                return bnoData.setMean(meanIn);
            case BMP:
                return bmpData.setMean(meanIn);
            case GNSS:
                return gnssData.setMean(meanIn);
        }
    }
    void setVariance(SENSOR_TYPE sensorType, float varianceIn) {
        switch (sensorType) {
            case BNO:
                return bnoData.setVariance(varianceIn);
            case BMP:
                return bmpData.setVariance(varianceIn);
            case GNSS:
                return gnssData.setVariance(varianceIn);
        }
    }

    virtual int8_t readRawSensorData(SENSOR_TYPE sensorType);
    
    virtual int8_t readCalibratedSensorData(SENSOR_TYPE sensorType);
    
    virtual int8_t applyCalibration(SensorData calibrationData, int8_t dataIn);

protected:
    I2CInterface* i2CInterface;
    BNOSensor* bno;
    BMPSensor* bmp;
    GNSSSensor* gnss;

    SensorDataClass bnoData = SensorDataClass();
    SensorDataClass bmpData = SensorDataClass();
    SensorDataClass gnssData = SensorDataClass();

};