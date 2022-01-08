//
// Created by bilai on 04/01/2022.
//
#include <vector>
#include <iostream>

#include "header/Card.h"
#include "header/CreatureCard.h"
#include "header/LandCard.h"
#include "header/Game.h"
#include "header/Deck.h"
#include "header/GameCards.h"

int main() {

    Game game;
    //game.playGame();

    //Création des cartes :
    Deck d1;
    GameCards gc;

    for (int i = 0; i < gc.getCreatures().size(); i++)
        d1.addCreature(gc.getCreatures().at(i));

    d1.printLibrary();

    class Forest : public LandCard {
    public:
        Forest() : LandCard("Forest", 0, "Green") {}
    };

    class Island : public LandCard {
    public:
        Island() : LandCard("Island", 0, "Blue") {}
        ~Island(){}
    };

    class Mountain : public LandCard {
    public:
        Mountain() : LandCard("Mountain", 0, "Red") {}

    };

    class Plain : public LandCard {
    public:
        Plain() : LandCard("Plain", 0, "Yellow") {}
    };

    class Swamp : public LandCard {
    public:
        Swamp() : LandCard("Swamp", 0, "Black") {}
    };

    return 0;
}