# CMake generated Testfile for 
# Source directory: /workspaces/embedded-sensor-monitor
# Build directory: /workspaces/embedded-sensor-monitor/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(SensorTest "/workspaces/embedded-sensor-monitor/build/sensor_test")
set_tests_properties(SensorTest PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/embedded-sensor-monitor/CMakeLists.txt;49;add_test;/workspaces/embedded-sensor-monitor/CMakeLists.txt;0;")
add_test(ControllerTest "/workspaces/embedded-sensor-monitor/build/controller_test")
set_tests_properties(ControllerTest PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/embedded-sensor-monitor/CMakeLists.txt;50;add_test;/workspaces/embedded-sensor-monitor/CMakeLists.txt;0;")
add_test(LoggerTest "/workspaces/embedded-sensor-monitor/build/logger_test")
set_tests_properties(LoggerTest PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/embedded-sensor-monitor/CMakeLists.txt;51;add_test;/workspaces/embedded-sensor-monitor/CMakeLists.txt;0;")
