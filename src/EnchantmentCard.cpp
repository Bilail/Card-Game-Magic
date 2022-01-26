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

EnchantmentCard::EnchantmentCard(std::string name, std::string color) : Card(name, std::vector<int>(6, 0), color) {
    asso = NULL;
};

EnchantmentCard::~EnchantmentCard() {};

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
    else std::cout << "                          ";
}

void EnchantmentCard::associate(Card* c){
    this->asso = c;
}

Card* EnchantmentCard::getAsso(){
    return asso;
}