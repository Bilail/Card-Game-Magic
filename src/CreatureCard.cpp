//
// Created by bilai on 04/01/2022.
//

#include "CreatureCard.h"
#include <string>

CreatureCard::CreatureCard(std::string nam, int mC, std::string cl, int ap, int hp, bool fstStk, bool trmb) : Card(nam, mC, cl, "Creature") {
    if (hp >= 0)
    hP = hp;
    else
    hP = 0;

    if (ap >= 0)
    attackPower = ap;
    else
    attackPower = 0;

    hasFirstStr = fstStk;
    hasTrmb = trmb;
    isTapped = true;
}


int CreatureCard::getHp() const {
    return hP;
}

int CreatureCard::getAttackPower() const {
    return attackPower;
}

bool CreatureCard::getIsTapped() const {
    return isTapped;
}

bool CreatureCard::isHasFirstStr() const {
    return hasFirstStr;
}

bool CreatureCard::isHasTrmb() const {
    return hasTrmb;
}

void CreatureCard::setHp(int hP) {
    CreatureCard::hP = hP;
}

void CreatureCard::setAttackPower(int attackPower) {
    CreatureCard::attackPower = attackPower;
}

void CreatureCard::setIsTapped(bool isTapped) {
    CreatureCard::isTapped = isTapped;
}

void CreatureCard::setHasFirstStr(bool hasFirstStr) {
    CreatureCard::hasFirstStr = hasFirstStr;
}

void CreatureCard::setHasTrmb(bool hasTrmb) {
    CreatureCard::hasTrmb = hasTrmb;
}

