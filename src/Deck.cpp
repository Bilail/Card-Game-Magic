//
// Created by bilai on 05/01/2022.
//

#include <vector>

#include "header/Card.h"
#include "header/Deck.h"

Deck::Deck() {
}

void Deck::add(Card d){
    library.push_back(d);
}

void Deck::printLibrary(){
    for (Card e : library){
        e.print();
    }
}

