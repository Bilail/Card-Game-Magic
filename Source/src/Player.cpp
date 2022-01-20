//
// Created by bilai on 05/01/2022.
//

#include "../header/Player.h"
#include "../header/StrColor.h"


int Player::baseHp = 4;

Player::Player(std::string name , Deck deck) {
    this->name = name;
    currentHp = baseHp;
    cards = deck;
    printColor = "white";
}

std::string Player::getName() {
    return name;
}

std::string Player::getColoredName() {
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

std::vector<Card*> Player::getAttackCards() {
   return cards.getAttackCards();
}

std::vector<Card*> Player::getDefenseCards() {
   return cards.getDefenseCards();
}

std::vector<Card*> Player::getHandCards() {
   return cards.getHandCards();
}

void Player::playCard(Card *c) {
    cards.playCard(c);
}

void Player::discardCard(Card* c) {
    cards.discardCard(c);
}