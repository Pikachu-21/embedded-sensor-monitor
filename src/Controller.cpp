#include "Controller.hpp"

SystemState Controller::evaluate(const SensorReading& reading) {
    if (reading.temperature >= 35.0) {
        currentState = SystemState::CRITICAL;
        fanOn = true;
    }
    else if (reading.temperature >= 30.0) {
        currentState = SystemState::WARNING;
        fanOn = true;
    }
    else {
        currentState = SystemState::NORMAL;
        fanOn = false;
    }

    return currentState;
}

bool Controller::isFanOn() const {
    return fanOn;
}

SystemState Controller::getState() const {
    return currentState;
}