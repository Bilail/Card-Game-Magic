//
// Created by bilai on 05/01/2022.
//
#include <string>

#include "header/Player.h"


int Player::baseHp = 20;

Player::Player(std::string name , Deck deck) {
    this->name = name;
    cards = deck;
}

std::string Player::getName() {
    return name;
}
