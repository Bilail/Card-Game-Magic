cmake_minimum_required(VERSION 3.16)
project(Magic)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Magic
        src/StrColor.cpp
        header/StrColor.h
        src/Card.cpp
        header/Card.h
        src/CreatureCard.cpp
        header/CreatureCard.h
        src/LandCard.cpp
        header/LandCard.h
        src/EnchantmentCard.cpp
        header/EnchantmentCard.h
        src/GameCards.cpp
        header/GameCards.h
        src/Deck.cpp
        header/Deck.h
        src/Game.cpp
        header/Game.h
        src/Player.cpp
        header/Player.h
        src/DeckCreator.cpp
        header/DeckCreator.h
        src/Main.cpp)
