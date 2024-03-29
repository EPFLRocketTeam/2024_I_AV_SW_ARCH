//
// Created by Philip on 27/03/2024.
//

#include <cstdint>
#include "channel/base_data_channel.hpp"

struct SensorData {
    float pollingRate;
    uint8_t id;
    union sensor_calibration_data {
        struct bno_calibration_t { // ID = 0 is for BNO
            float mean;
            float variance;
        } bnoCalibration;

        struct bmp_calibration_t { // ID = 1 is for BMP
            float mean[3];
            float variance[3];
        } bmpCalibration ;

        struct gnss_calibration_t { // ID = 2 is for BMP

        } gnssCalibration;

    } data;
};

enum SENSOR_TYPE {
    BNO,
    BMP,
    GNSS
};

template<class I2CInterface, class BNOSensor, class BMPSensor, class GNSSSensor>
class BaseTeensySensors {
public:
    BaseTeensySensors(BNOSensor* bnoSensorIn, BMPSensor* bmpSensorIn, GNSSSensor* gnssSensorIn, I2CInterface* i2CInterfaceIn) {
        gnss = gnssSensorIn;
        bmp = bmpSensorIn;
        bno = bnoSensorIn;
        i2CInterface = i2CInterfaceIn;
    }

    virtual void initializeDrivers() = 0;
    virtual void tick() = 0;
    SensorData getSensorData(SENSOR_TYPE sensorType) {
        switch (sensorType) {
            case BNO:
                return bnoData;
            case BMP:
                return bmpData;
            case GNSS:
                return gnssData;
        }
    }
    virtual void calibrate(SENSOR_TYPE sensorType) = 0;


protected:
    void setMeanBNO(float meanIn) {
        bnoData.data.bnoCalibration.mean = meanIn;
    }
    void setMeanBMP(float meanXIn, float meanYIn, float meanZIn) {
        bnoData.data.bmpCalibration.mean[0] = meanXIn;
        bnoData.data.bmpCalibration.mean[1] = meanYIn;
        bnoData.data.bmpCalibration.mean[2] = meanZIn;
    }
    void setMeanGNSS() {
    }

    void setVarianceBNO(float varianceIn) {
        bnoData.data.bnoCalibration.variance = varianceIn;
    }
    void setVarianceBMP(float varianceXIn, float varianceYIn, float varianceZIn) {
        bnoData.data.bmpCalibration.variance[0] = varianceXIn;
        bnoData.data.bmpCalibration.variance[1] = varianceYIn;
        bnoData.data.bmpCalibration.variance[2] = varianceZIn;
    }
    void setVarianceGNSS() {
    }

    virtual int8_t readRawSensorData(SENSOR_TYPE sensorType);
    
    virtual int8_t readCalibratedSensorData(SENSOR_TYPE sensorType);
    
    virtual int8_t applyCalibration(SensorData calibrationData, int8_t dataIn);

protected:
    I2CInterface* i2CInterface;
    BNOSensor* bno;
    BMPSensor* bmp;
    GNSSSensor* gnss;

    SensorData bnoData = {
            .pollingRate = 0,
            .id = 0,
    };
    SensorData bmpData = {
            .pollingRate = 0,
            .id = 1
    };
    SensorData gnssData = {
            .pollingRate = 0,
            .id = 2
    };
};