//
// Created by bilai on 05/01/2022.
//

#include "header/Card.h"
#include "header/Deck.h"

const int Deck::DECK_SIZE = 30;

Deck::Deck() {
    creatures.reserve(DECK_SIZE);
}

Deck::~Deck() {
}

void Deck::addCreature(CreatureCard card) {
    if (creatures.size() < DECK_SIZE) {
        creatures.push_back(CreatureCard(card));
        library.push_back(&creatures.back());
    }
}

void Deck::printLibrary() {
    for (Card* c : library)
        c->print();
}

void Deck::printInPlayCards() {
    for (Card* c : inPlayCards)
        c->print();
}

