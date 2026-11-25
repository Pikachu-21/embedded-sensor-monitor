#include "Sensor.hpp"
#include "Controller.hpp"
#include "Logger.hpp"

#include <iostream>
#include <iomanip>

const char* stateToString(SystemState state) {
    switch (state) {
        case SystemState::NORMAL:
            return "NORMAL";
        case SystemState::WARNING:
            return "WARNING";
        case SystemState::CRITICAL:
            return "CRITICAL";
    }

    return "UNKNOWN";
}

int main() {
    Sensor sensor;
    Controller controller;
    Logger logger;

    std::cout << "====================================\n";
    std::cout << "  EMBEDDED SENSOR MONITORING SYSTEM\n";
    std::cout << "====================================\n\n";

    // Simulate 15 sensor readings.
    for (int i = 0; i < 15; ++i) {
        SensorReading reading = sensor.read();

        SystemState state = controller.evaluate(reading);

        logger.add(reading);

        std::cout << std::fixed << std::setprecision(2);

        std::cout << "Reading #" << reading.timestamp << "\n";
        std::cout << "Temperature: "
                  << reading.temperature << " C\n";

        std::cout << "Humidity: "
                  << reading.humidity << " %\n";

        std::cout << "System State: "
                  << stateToString(state) << "\n";

        std::cout << "Fan: "
                  << (controller.isFanOn() ? "ON" : "OFF")
                  << "\n";

        std::cout << "------------------------------------\n";
    }

    std::cout << "\nRECENT READING HISTORY\n";
    std::cout << "=====================\n";

    SensorReading reading{};

    for (std::size_t i = 0; i < logger.size(); ++i) {
        if (logger.getOldest(i, reading)) {
            std::cout << "Timestamp: " << reading.timestamp
                      << " | Temperature: " << reading.temperature
                      << " C | Humidity: " << reading.humidity
                      << " %\n";
        }
    }

    std::cout << "\nSimulation complete.\n";

    return 0;
}