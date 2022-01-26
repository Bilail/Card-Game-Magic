cmake_minimum_required(VERSION 3.16)
project(Magic)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        Magic
        Source/src/StrColor.cpp
        Source/header/StrColor.h
        Source/src/Card.cpp
        Source/header/Card.h
        Source/src/CreatureCard.cpp
        Source/header/CreatureCard.h
        Source/src/LandCard.cpp
        Source/header/LandCard.h
        Source/src/EnchantmentCard.cpp
        Source/header/EnchantmentCard.h
        Source/src/GameCards.cpp
        Source/header/GameCards.h
        Source/src/Deck.cpp
        Source/header/Deck.h
        Source/src/Game.cpp
        Source/header/Game.h
        Source/src/Player.cpp
        Source/header/Player.h
        Source/src/DeckCreator.cpp
        Source/header/DeckCreator.h
        Source/src/Main.cpp)
