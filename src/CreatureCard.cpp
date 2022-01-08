//
// Created by bilai on 04/01/2022.
//

#include <iostream>
#include <string>
#include "header/StrColor.h"
#include "header/CreatureCard.h"

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

void CreatureCard::print() const {
    std::string spaces = "                ";
    for (int i = 0; i < name.length(); i++)
        spaces.pop_back();
    std::cout
            << StrColor::print(" ___________________________________ ", color) << std::endl
            << StrColor::print("| Name : " + name + spaces + "  Cout : " + std::to_string(manaCost) + " |", color) << std::endl
            << StrColor::print("|                                   |", color) << std::endl
            << StrColor::print("| Attack : " + std::to_string(attackPower) + "                 HP : " + std::to_string(hp) + " |", color) << std::endl
            << StrColor::print("|___________________________________|", color) << std::endl;
}
