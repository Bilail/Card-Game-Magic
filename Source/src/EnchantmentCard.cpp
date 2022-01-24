//
// Created by bilai on 22/01/2022.
//

#include "../header/EnchantmentCard.h"
#include <vector>
#include <string>

enum enchantment {
    white,
    blue,
    black,
    red,
    green
};

EnchantmentCard::EnchantmentCard(std::string name) : Card(name, std::vector<int>(6, 0), name) {
    associate = NULL;
};

EnchantmentCard::~EnchantmentCard() {

};

void EnchantmentCard::effect() {

};


void EnchantmentCard::print() {
    std::string nameSpaces = "                ";
    for (int i = 0; i < name.length(); i++)
        if (nameSpaces.length() > 0)
            nameSpaces.pop_back();
    std::cout
            << StrColor::print(" ________________________ ", color) << std::endl
            << StrColor::print("| Name : " + name + nameSpaces + "|", color) << std::endl
            << StrColor::print("| Mana Cost : 0          |", color) << std::endl
            << StrColor::print("|                        |", color) << std::endl
            << StrColor::print("|________________________|", color) << std::endl;
}

void EnchantmentCard::printLine(int line) {
    std::string nameSpaces = "                ";
    for (int i = 0; i < name.length(); i++)
        if (nameSpaces.length() > 0)
            nameSpaces.pop_back();
    if (line == 1)
        std::cout << StrColor::print(" ________________________ ", color);
    else if (line == 2)
        std::cout << StrColor::print("| Name : " + name + nameSpaces + "|", color);
    else if (line == 3)
        std::cout << StrColor::print("| Mana Cost : 0          |", color);
    else if (line == 4)
        std::cout << StrColor::print("|                        |", color);
    else if (line == 5)
        std::cout << StrColor::print("|________________________|", color);
}


void EnchantmentCard::associate(Card* c){
    this->asso = c;
}