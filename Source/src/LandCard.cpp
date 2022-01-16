//
// Created by bilai on 05/01/2022.
//

#include <iostream>
#include <string>
#include "../header/StrColor.h"
#include "../header/LandCard.h"


LandCard::LandCard(std::string nm, std::string clr) : Card(nm,std::vector<int>(6, 0),clr) {

}


void LandCard::print() {
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

void LandCard::printLine(int line) {
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