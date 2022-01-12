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
    std::string nameSpaces = "                ";
    for (int i = 0; i < name.length(); i++)
        if (nameSpaces.length() > 0)
            nameSpaces.pop_back();
    std::string manaSpaces = "           ";
    int nbManaCost = 0;
    for (int i : manaCost)
        if (i > 0)
            nbManaCost++;
    for (int i = 0; i < nbManaCost + nbManaCost - 1; i++) {
        if (manaSpaces.length() > 0)
            manaSpaces.pop_back();
    }
    std::cout
            << StrColor::print(" ________________________ ", color) << std::endl
            << StrColor::print("| Name : " + name + nameSpaces + "|", color) << std::endl
            << StrColor::print("| Mana Cost : ", color) + manaToString() + StrColor::print(manaSpaces + "|", color) << std::endl
            << StrColor::print("| Attack : " + std::to_string(attackPower) + "      HP : " + std::to_string(hp) + " |", color) << std::endl
            << StrColor::print("|________________________|", color) << std::endl;
}
