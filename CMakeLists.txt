# cmake_minimum_required(VERSION <specify CMake version here>)
project(Magic)

set(CMAKE_CXX_STANDARD 20)

add_executable(Magic src/Card.cpp src/header/Card.h src/CreatureCard.cpp src/header/CreatureCard.h src/Game.cpp src/header/Game.h src/Main.cpp)