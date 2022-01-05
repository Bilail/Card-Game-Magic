//
// Created by bilai on 05/01/2022.
//
#include <string>

#include "header/Player.h"
#include "header/StrColor.h"


int Player::baseHp = 20;

Player::Player(std::string name , Deck deck) {
    this->name = name;
    cards = deck;
    printColor = "white";
}

std::string Player::getName() {
    return StrColor::print(name, printColor);
}

void Player::setPrintColor(std::string color) {
    printColor = color;
}