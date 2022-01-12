//
// Created by bilai on 04/01/2022.
//

#include <iostream>
#include <string>
#include "header/StrColor.h"
#include "header/CreatureCard.h"



CreatureCard::CreatureCard(std::string nam, std::vector<int> mC, std::string cl, int ap, int hp) : Card(nam, mC, cl) {
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

void CreatureCard::attack(){
    engage();
}


void CreatureCard::print() {
    std::string spaces = "                ";
    for (int i = 0; i < name.length(); i++)
        spaces.pop_back();
    std::cout
            << StrColor::print(" ___________________________________ ", color) << std::endl
            << StrColor::print("| Name : " + name + spaces + "  Cout : " + manaToString(), color) << std::endl
            << StrColor::print("|                                   |", color) << std::endl
            << StrColor::print("| Attack : " + std::to_string(attackPower) + "                 HP : " + std::to_string(hp) + " |", color) << std::endl
            << StrColor::print("|___________________________________|", color) << std::endl;
}
