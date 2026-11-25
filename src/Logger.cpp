#include "Logger.hpp"

void Logger::add(const SensorReading& reading) {
    buffer[nextIndex] = reading;

    nextIndex = (nextIndex + 1) % CAPACITY;

    if (count < CAPACITY) {
        ++count;
    }
}

std::size_t Logger::size() const {
    return count;
}

bool Logger::getOldest(std::size_t index, SensorReading& output) const {
    if (index >= count) {
        return false;
    }

    const std::size_t oldestIndex =
        (nextIndex + CAPACITY - count) % CAPACITY;

    const std::size_t physicalIndex =
        (oldestIndex + index) % CAPACITY;

    output = buffer[physicalIndex];

    return true;
}