//
// Created by Philip on 27/03/2024.
//

struct SensorData {
    float mean;
    float variance;
    int pollingRate;
};

enum SENSOR_TYPE {
    BNO
    BMP
    GNSS
};

/**
 * SensorDataClass contains calibration data for a sensor.
 */
class SensorDataClass {
private:
    float mean;
    float variance;
    int pollingRate;
public:
    SensorData get();
    void setMean(time_millis_t);
    void setVariance(time_millis_t);
    void setPollingRate(FSMState);
};
