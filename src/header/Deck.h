//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_DECK_H
#define MAGIC_DECK_H

#include <vector>
#include "Card.h"
#include "CreatureCard.h"
#include "LandCard.h"

class Deck {
protected:
    std::vector<CreatureCard> creatures;
    std::vector<LandCard> lands;
    std::vector<Card*> inPlayCards;
    std::vector<Card*> handPile;
    std::vector<Card*> library;
    std::vector<Card*> disCards;
public:
    static const int DECK_SIZE;
    Deck();
    ~Deck();
    void addCreature(CreatureCard card);
    //void addLand(LandCard card);
    void printLibrary();
    void printInPlayCards();
};


#endif //MAGIC_DECK_H
