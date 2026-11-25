#include "Logger.hpp"

#include <cassert>
#include <iostream>

int main() {
    Logger logger;

    assert(logger.size() == 0);

    // Fill the buffer to capacity.
    for (std::uint64_t i = 1; i <= Logger::CAPACITY; ++i) {
        SensorReading reading{20.0 + i, 40.0 + i, i};
        logger.add(reading);
    }

    assert(logger.size() == Logger::CAPACITY);

    // Verify chronological order before wrapping.
    SensorReading output{};

    assert(logger.getOldest(0, output));
    assert(output.timestamp == 1);

    assert(logger.getOldest(9, output));
    assert(output.timestamp == 10);

    // Add two more readings to force wraparound.
    logger.add(SensorReading{31.0, 51.0, 11});
    logger.add(SensorReading{32.0, 52.0, 12});

    assert(logger.size() == Logger::CAPACITY);

    // The oldest two readings should now be 3 and 4.
    assert(logger.getOldest(0, output));
    assert(output.timestamp == 3);

    assert(logger.getOldest(1, output));
    assert(output.timestamp == 4);

    // The newest reading should be 12.
    assert(logger.getOldest(9, output));
    assert(output.timestamp == 12);

    // Invalid index should be rejected.
    assert(!logger.getOldest(10, output));

    std::cout << "All logger tests passed!\n";

    return 0;
}