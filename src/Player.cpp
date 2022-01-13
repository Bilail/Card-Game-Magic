//
// Created by bilai on 05/01/2022.
//

#include "header/Player.h"
#include "header/StrColor.h"


int Player::baseHp = 20;

Player::Player(std::string name , Deck deck) {
    this->name = name;
    currentHp = baseHp;
    cards = deck;
    printColor = "white";
}

std::string Player::getName() {
    return StrColor::print(name, printColor);
}

void Player::setPrintColor(std::string color) {
    printColor = color;
}

int Player::getHp() {
    return currentHp;
}

void Player::setHp(int hp) {
    currentHp = hp;
}

bool Player::drawCard(){
    return cards.drawCard();
}

void Player::disengageCards() {
    cards.disengageCards();
}

std::vector<Card*> Player::getPlayableCards() {
   return cards.getPlayableCards();
}

void Player::playCard(Card *c) {
    cards.playCard(c);
}