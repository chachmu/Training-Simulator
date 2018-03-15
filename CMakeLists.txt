cmake_minimum_required(VERSION 3.9)
project(Training_Simulator)

set(CMAKE_CXX_STANDARD 11)

add_executable(Training_Simulator main.cpp PhysicsObject.hpp PhysicsObject.cpp Sensor.cpp Line.hpp)