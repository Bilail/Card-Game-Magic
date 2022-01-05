//
// Created by bilai on 04/01/2022.
//

#include "header/CreatureCard.h"
#include <string>

CreatureCard::CreatureCard(std::string nam, int mC, std::string cl, int ap, int hp) : Card(nam, mC, cl) {
    this->hp = hp;
    defaultHp = hp;
    attackPower = ap;
}


int CreatureCard::getHp() const {
    return hp;
}

int CreatureCard::getAttackPower() const {
    return attackPower;
}

void CreatureCard::setHp(int hP) {
    CreatureCard::hp = hP;
}

void CreatureCard::setAttackPower(int attackPower) {
    CreatureCard::attackPower = attackPower;
}

void CreatureCard::invocate() {
    firstTurn = true;
}

bool CreatureCard::isFirstTurn() {
    return firstTurn;
}