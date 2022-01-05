//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_DECK_H
#define MAGIC_DECK_H

#include <vector>
#include "Card.h"

class Deck {
protected:
    std::vector<Card> inplayCards;
    std::vector<Card> handPile;
    std::vector<Card> library;
    std::vector<Card> disCards;
public:
    Deck();
    ~Deck();
    void add(Card card);
    void printLibrary();
};


#endif //MAGIC_DECK_H
