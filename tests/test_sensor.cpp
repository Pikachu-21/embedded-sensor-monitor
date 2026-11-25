#include "Sensor.hpp"

#include <cassert>
#include <iostream>

int main() {
    Sensor sensor;

    for (int i = 1; i <= 1000; ++i) {
        SensorReading reading = sensor.read();

        assert(reading.temperature >= 15.0);
        assert(reading.temperature <= 40.0);

        assert(reading.humidity >= 30.0);
        assert(reading.humidity <= 90.0);

        assert(reading.timestamp == static_cast<std::uint64_t>(i));
    }

    std::cout << "All sensor tests passed!\n";

    return 0;
}