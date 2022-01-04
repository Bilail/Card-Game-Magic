//
// Created by bilai on 04/01/2022.
//

#include "Card.h"

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

void Card::setTypeOfCard(const std::string &typeOfCard) {
    Card::typeOfCard = typeOfCard;
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

const std::string &Card::getTypeOfCard() const {
    return typeOfCard;
}

Card::Card(std::string nm, int mnCt, std::string clr, std::string typeOfCard) : name(nm), manaCost(mnCt),
    color(clr), typeOfCard(typeOfCard) {
    isDiscarded = false;
}

Card::~Card() {

}

