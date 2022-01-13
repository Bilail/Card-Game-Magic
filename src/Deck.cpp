//
// Created by bilai on 05/01/2022.
//

#include "header/Card.h"
#include "header/Deck.h"
#include "header/Util.h"

const int Deck::DECK_SIZE = 30;

Deck::Deck() {
    GameCards gc;
    for (CreatureCard c : gc.getCreatures()) {
        library.push_back(new CreatureCard(c));
    }
    for(LandCard l : gc.getLands()) {
        library.push_back(new LandCard(l));
        library.push_back(new LandCard(l));
    }
}

Deck::~Deck() {
}

void Deck::printLibrary() {
    Card::print(library);
}

void Deck::printInPlayCards() {
    Card::print(inPlayCards);
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
        return true;
    }
}

void Deck::disengageCards() {
    for (int i = 0; i < inPlayCards.size(); i++) {
        inPlayCards.at(i)->disengage();
    }
}

std::vector<Card*> Deck::getPlayableCards() {
    std::vector<int> manaAvailable(6,0);
    for (Card* c : inPlayCards) {
        if (!c->getIsEngaged()) {
            if (dynamic_cast<const LandCard*>(c)) {
                manaAvailable.at(5) += 1;
                int colorIndex = getIndex(Card::ColorCode, c->getColor());
                manaAvailable.at(colorIndex) += 1;
            }
        }
    }
    std::vector<Card*> playableCards;
    for (Card* c : handCards) {
        int landCardsUsed = 0;
        for (int i = 0; i < c->getManaCost().size(); i++) {
            if (i == 5) { // La position 5 correspond à tout type de terrain
                if (c->getManaCost().at(i) <= manaAvailable.at(i) - landCardsUsed)
                    playableCards.push_back(c);
            }
            else {
                if (c->getManaCost().at(i) <= manaAvailable.at(i))
                    landCardsUsed  += c->getManaCost().at(i);
                else
                    break;
            }
        }
    }
    return playableCards;
}

void Deck::playCard(Card* c) {
    // On commence par engager les terrains nécessaires pour poser la carte
    for (int i = 0; i < c->getManaCost().size(); i++) {
        for (int j = 0; j < c->getManaCost().at(i); j++) {
            for (int k = 0; k < inPlayCards.size(); k++) {
                if (dynamic_cast<const LandCard*>(inPlayCards.at(k))) {
                    if (!inPlayCards.at(k)->getIsEngaged()) {
                        if (inPlayCards.at(k)->getColor() == Card::ColorCode[i] || i == 5) {
                            inPlayCards.at(k)->engage();
                            break;
                        }
                    }
                }
            }
        }
    }
    // Puis on transfère la carte de la main vers les cartes en jeu
    int idx = getIndex(handCards, c);
    handCards.erase(handCards.begin() + idx);
    inPlayCards.push_back(c);
}