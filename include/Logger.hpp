#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "Sensor.hpp"

#include <array>
#include <cstddef>

class Logger {
public:
    static constexpr std::size_t CAPACITY = 10;

    void add(const SensorReading& reading);

    std::size_t size() const;
    bool getOldest(std::size_t index, SensorReading& output) const;

private:
    std::array<SensorReading, CAPACITY> buffer{};

    std::size_t nextIndex = 0;
    std::size_t count = 0;
};

#endif