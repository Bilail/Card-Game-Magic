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
        Source/src/GameCards.cpp
        Source/header/GameCards.h
        Source/src/Deck.cpp
        Source/header/Deck.h
        Source/src/Game.cpp
        Source/header/Game.h
        Source/src/Player.cpp
        Source/header/Player.h
        Source/src/Main.cpp)


set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Magic ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

#file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()