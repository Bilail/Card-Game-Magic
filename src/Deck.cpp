//
// Created by bilai on 05/01/2022.
//

#include "header/Card.h"
#include "header/Deck.h"

const int Deck::DECK_SIZE = 30;

Deck::Deck() {
    GameCards gc;
    for (CreatureCard c : gc.getCreatures()) {
        library.push_back(new CreatureCard(c));
    }
    for(LandCard l : gc.getLands()) {
        library.push_back(new LandCard(l));
    }
}

Deck::~Deck() {
}

void Deck::printLibrary() {
    for (Card* c : library)
        c->print();
}

void Deck::printInPlayCards() {
    for (Card* c : inPlayCards)
        c->print();
}

void Deck::generateRandomDeck(){

    // Initialize seed randomly
    srand(time(0));

    for (int i=0; i<library.size() ;i++)
    {
        // Random for remaining positions.
        int r = i + (rand() % (library.size() -i));
        std::swap(library[i], library[r]);
    }
}

bool Deck::drawCard(){
    if(library.size() == 0 ){
        return false;
    }
    else {
        handCards.push_back(library.back());
        library.pop_back();
    }
}

void Deck::disengageCards() {
    for (int i = 0; i < inPlayCards.size(); i++) {
        inPlayCards.at(i)->disengage();
    }
}

std::vector<Card*> Deck::getPlayableCards() {
    std::vector<Card*> playableCards;
    for (int i = 0; i < handCards.size(); i++) {

    }
    return playableCards;
}