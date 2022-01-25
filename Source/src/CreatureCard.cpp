//
// Created by bilai on 04/01/2022.
//

#include <iostream>
#include <string>
#include "../header/StrColor.h"
#include "../header/CreatureCard.h"



CreatureCard::CreatureCard(std::string nam, std::vector<int> mC, std::string cl, int ap, int hp) : Card(nam, mC, cl) {
    this->hp = hp;
    defaultHp = hp;
    attackPower = ap;
    firstTurn = true;
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

void CreatureCard::setFirstTurn(int b) {
    firstTurn = b;
}

bool CreatureCard::isFirstTurn() {
    return firstTurn;
}

std::string CreatureCard::capacitiesToString() {
    std::string s = "";
    for (int i = 0; i < capacities.size(); i++) {
         s += StrColor::white("" + capacities[i][0] + capacities[i][1]);
            if (i+1 < capacities.size())
                s += " - ";
    }
    return s;
}

void CreatureCard::printLine(int line) {
    std::string nameSpaces = "                ";
    for (int i = 0; i < name.length(); i++)
        if (nameSpaces.length() > 0)
            nameSpaces.pop_back();
    std::string manaSpaces = "           ";
    int nbManaCost = 0;
    for (int i : manaCost)
        if (i > 0)
            nbManaCost++;
    for (int i = 0; i < 2 * nbManaCost - 1; i++) {
        if (manaSpaces.length() > 0)
            manaSpaces.pop_back();
    }
    std::string capacitySpaces = "           ";
    if (capacities.size() > 0) {
        for (int i = 0; i < 3 * capacities.size() - 1; i++) {
            if (capacitySpaces.length() > 0)
                capacitySpaces.pop_back();
        }
    }
    else {
        capacitySpaces = "None        ";
    }
    if (line == 1)
        std::cout << StrColor::print(" ________________________ ", color);
    else if (line == 2)
        std::cout << StrColor::print("| Name : " + name + nameSpaces + "|", color);
    else if (line == 3)
        std::cout << StrColor::print("| Mana Cost : ", color) + manaToString() + StrColor::print(manaSpaces + "|", color);
    else if (line == 4)
        std::cout << StrColor::print("| Capacity : ", color) + capacitiesToString() + StrColor::print(capacitySpaces + "|", color);
    else if (line == 5)
        std::cout << StrColor::print("| Attack : " + std::to_string(attackPower) + "      HP : " + std::to_string(hp) + " |", color);
    else if (line == 6)
        std::cout << StrColor::print("|________________________|", color);
    else
        std::cout << "                          ";
}

void CreatureCard::disengage() {
    resetHp();
    isEngaged = false;
    firstTurn = false;
}

void CreatureCard::resetHp() {
    hp = defaultHp;
}

bool CreatureCard::hasCapacity(std::string capacity) {
    for (std::string s : capacities)
        if (s == capacity)
            return true;
    return false;
}