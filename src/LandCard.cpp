//
// Created by bilai on 05/01/2022.
//

#include <iostream>
#include <string>
#include "header/StrColor.h"
#include "header/LandCard.h"


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
