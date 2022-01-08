# cmake_minimum_required(VERSION <specify CMake version here>)
project(Magic)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        Magic
        src/StrColor.cpp
        src/header/StrColor.h
        src/Card.cpp
        src/header/Card.h
        src/CreatureCard.cpp
        src/header/CreatureCard.h
        src/LandCard.cpp
        src/header/LandCard.h
        src/GameCards.cpp
        src/header/GameCards.h
        src/Deck.cpp
        src/header/Deck.h
        src/Game.cpp
        src/header/Game.h
        src/Player.cpp
        src/header/Player.h
        src/Main.cpp)