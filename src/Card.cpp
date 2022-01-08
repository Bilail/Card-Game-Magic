//
// Created by bilai on 04/01/2022.
//
#include <iostream>
#include "header/StrColor.h"
#include "header/Card.h"

void Card::Engage() {
    isEngaged = true;
}

void Card::Disengage() {
    isEngaged = false;
}

bool Card::getEngage() {
    return isEngaged;
}

void Card::setName(const std::string &name) {
    Card::name = name;
}

void Card::setManaCost(int manaCost) {
    Card::manaCost = manaCost;
}

void Card::setColor(const std::string &color) {
    Card::color = color;
}

void Card::setIsDiscarded(bool isDiscarded) {
    Card::isDiscarded = isDiscarded;
}

const std::string &Card::getName() const {
    return name;
}

int Card::getManaCost() const {
    return manaCost;
}

const std::string &Card::getColor() const {
    return color;
}

bool Card::getIsDiscarded() const {
    return isDiscarded;
}

Card::Card(std::string nm, int mnCt, std::string clr) {
    name = nm;
    manaCost = mnCt;
    color = clr;
    isDiscarded = false;
}

Card::~Card() {
}

void Card::isStillOperational() {
    if (!isDiscarded) {
        std::cout << name << ": is still operational" << std::endl;
    } else {
        std::cout << name << ": is destroyed" << std::endl;
    }
}


void Card::print() const {
    std::string spaces = "                ";
    for (int i = 0; i < name.length(); i++)
        spaces.pop_back();
    std::cout
    << StrColor::print("____________________________________", color) << std::endl
    << StrColor::print("| Name : " + name + spaces + "  Cout : " + std::to_string(manaCost) + " |", color) << std::endl
    << StrColor::print("|                                   |", color) << std::endl
    << StrColor::print("|                                   |", color) << std::endl
    << StrColor::print("|___________________________________|", color) << std::endl;
}






