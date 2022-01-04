# cmake_minimum_required(VERSION <specify CMake version here>)
project(Magic)

set(CMAKE_CXX_STANDARD 20)

add_executable(Magic main.cpp src/Card.cpp src/Card.h src/Main.cpp src/CreatureCard.cpp src/CreatureCard.h)