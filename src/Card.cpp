//
// Created by bilai on 04/01/2022.
//
#include <iostream>
#include "../header/StrColor.h"
#include "../header/Card.h"

std::vector<std::string> Card::ColorCode = {"green","blue","red","yellow","black","white"};

void Card::engage() {
    isEngaged = true;
}

void Card::disengage() {
    isEngaged = false;
}

void Card::setName(const std::string &name) {
    Card::name = name;
}

void Card::setColor(const std::string &color) {
    Card::color = color;
}

const std::string &Card::getName() const {
    return name;
}

const std::string Card::getColoredName() const {
    return StrColor::print(name, color);
}

std::vector<int> Card::getManaCost() const {
    return manaCost;
}

const std::string &Card::getColor() const {
    return color;
}

bool Card::getIsEngaged() const {
    return isEngaged;
}

Card::Card(std::string nm, std::vector<int> mnCt, std::string clr) {
    name = nm;
    manaCost = mnCt;
    color = clr;
}

Card::~Card() {
}

void Card::setManaCost(std::vector<int> manaCost) {
    this-> manaCost = manaCost;
}

std::string Card::manaToString() {
    std::string s = "";
    int nbManaCost = 0;
    for (int i: manaCost)
        if (i > 0)
            nbManaCost++;
    int nbManaCostAdded = 0;
    for (int i = 0; i < manaCost.size(); i++) {
        if (manaCost.at(i) > 0) {
            s += StrColor::print(std::to_string(manaCost.at(i)), Card::ColorCode.at(i));
            nbManaCostAdded++;
            if (nbManaCostAdded < nbManaCost)
                s += "-";
        }
    }
    return s;
}

void Card::print() {
    for (int i = 1; i <= 6; i++) {
        printLine(i);
        std::cout << std::endl;
    }
}

void Card::printLine(int line) {
    std::string nameSpaces = "                ";
    for (int i = 0; i < name.length(); i++)
        if (nameSpaces.length() > 0)
            nameSpaces.pop_back();
    if (line == 1)
        std::cout << StrColor::print(" ________________________ ", color);
    else if (line == 2)
        std::cout << StrColor::print("| Name : " + name + nameSpaces + "|", color);
    else if (line == 3)
        std::cout << StrColor::print("| Mana Cost : undefined  |", color);
    else if (line == 4)
        std::cout << StrColor::print("|                        |", color);
    else if (line == 5)
        std::cout << StrColor::print("|________________________|", color);
}

void Card::print(std::vector<Card*> v) {
    int firstCardLineIdx = 0;
    int nbCardsPerLine = 5;
    int linePerCardToPrint = 6;
    int lineOfCards = (v.size() + nbCardsPerLine - 1) / nbCardsPerLine;
    for (int k = 0; k < lineOfCards; k++) {
        for (int i = 1; i <= linePerCardToPrint; i++) {
            for (int j = firstCardLineIdx; j < firstCardLineIdx + nbCardsPerLine && j < v.size(); j++) {
                v.at(j)->printLine(i);
                std::cout << " ";
            }
            std::cout << std::endl;
        }
        firstCardLineIdx += nbCardsPerLine;
    }
}
