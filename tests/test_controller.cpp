#include "Controller.hpp"

#include <cassert>
#include <iostream>

int main() {
    Controller controller;

    SensorReading reading{25.0, 50.0, 1};
    assert(controller.evaluate(reading) == SystemState::NORMAL);
    assert(!controller.isFanOn());

    reading.temperature = 30.0;
    assert(controller.evaluate(reading) == SystemState::WARNING);
    assert(controller.isFanOn());

    reading.temperature = 34.9;
    assert(controller.evaluate(reading) == SystemState::WARNING);
    assert(controller.isFanOn());

    reading.temperature = 35.0;
    assert(controller.evaluate(reading) == SystemState::CRITICAL);
    assert(controller.isFanOn());

    reading.temperature = 20.0;
    assert(controller.evaluate(reading) == SystemState::NORMAL);
    assert(!controller.isFanOn());

    std::cout << "All controller tests passed!\n";

    return 0;
}