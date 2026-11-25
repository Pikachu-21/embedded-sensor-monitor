#include "Sensor.hpp"

#include <random>

namespace {
    std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> temperatureDistribution(15.0, 40.0);
    std::uniform_real_distribution<double> humidityDistribution(30.0, 90.0);
}

SensorReading Sensor::read() {
    SensorReading reading;

    reading.temperature = temperatureDistribution(generator);
    reading.humidity = humidityDistribution(generator);
    reading.timestamp = ++readingCount;

    return reading;
}