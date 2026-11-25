cmake_minimum_required(VERSION 3.16)

project(EmbeddedSensorMonitor LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(sensor
    src/Sensor.cpp
    src/Controller.cpp
    src/Logger.cpp
)

target_include_directories(sensor PUBLIC include)

# Sensor test
add_executable(sensor_test
    tests/test_sensor.cpp
)

# Main application
add_executable(embedded_monitor
    src/main.cpp
)

target_link_libraries(embedded_monitor PRIVATE sensor)

target_link_libraries(sensor_test PRIVATE sensor)

# Controller test
add_executable(controller_test
    tests/test_controller.cpp
)

target_link_libraries(controller_test PRIVATE sensor)

# Logger test
add_executable(logger_test
    tests/test_logger.cpp
)

target_link_libraries(logger_test PRIVATE sensor)

enable_testing()

add_test(NAME SensorTest COMMAND sensor_test)
add_test(NAME ControllerTest COMMAND controller_test)
add_test(NAME LoggerTest COMMAND logger_test)