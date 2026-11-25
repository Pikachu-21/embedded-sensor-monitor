#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <cstdint>

struct SensorReading {
    double temperature;
    double humidity;
    std::uint64_t timestamp;
};

class Sensor {
public:
    SensorReading read();

private:
    std::uint64_t readingCount = 0;
};

#endif