#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Sensor.hpp"

enum class SystemState {
    NORMAL,
    WARNING,
    CRITICAL
};

class Controller {
public:
    SystemState evaluate(const SensorReading& reading);

    bool isFanOn() const;
    SystemState getState() const;

private:
    SystemState currentState = SystemState::NORMAL;
    bool fanOn = false;
};

#endif