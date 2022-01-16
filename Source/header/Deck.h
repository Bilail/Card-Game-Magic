//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_DECK_H
#define MAGIC_DECK_H

#include <vector>
#include <bits/stdc++.h>
#include "Card.h"
#include "GameCards.h"

class Deck {
protected:
    std::vector<Card*> inPlayCards;
    std::vector<Card*> handCards;
    std::vector<Card*> library;
    std::vector<Card*> disCards;
public:
    static const int DECK_SIZE;
    Deck();
    ~Deck();
    void printLibrary();
    void printInPlayCards();
    void generateRandomDeck();
    bool drawCard();
    void disengageCards();
    std::vector<Card*> getPlayableCards();
    std::vector<Card*> getAttackCards();
    std::vector<Card*> getDefenseCards();
    void playCard(Card* c);
};


#endif //MAGIC_DECK_H
