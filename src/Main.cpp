//
// Created by bilai on 04/01/2022.
//
#include <vector>

#include "header/Card.h"
#include "header/CreatureCard.h"
#include "header/LandCard.h"
#include "header/Game.h"
#include "header/Deck.h"


int main() {

    /*Game game;
    game.playGame();*/

    Deck d1;
    Deck d2;

    //Création des cartes :
    d1.add(CreatureCard ("Soldier", 1, "White", 1, 1));
    d1.add(CreatureCard("ArmoredPegasus", 2, "White", 1, 2));
    d1.add(CreatureCard("WhiteKnight", 2, "White", 2, 2));
    d1.add(CreatureCard("AngryBear", 3, "Green", 3, 2));
    d1.add(CreatureCard("Guard", 4, "White", 2, 5));
    d1.add(CreatureCard("Werewolf", 4, "Green", 4, 6));
    d1.add(CreatureCard("Skeleton", 1, "Black", 1, 1));
    d1.add(CreatureCard("Ghost", 2, "Black", 2, 1));
    d1.add(CreatureCard("BlackKnight", 2, "Black", 2, 2));
    d1.add(CreatureCard("OrcManiac", 3, "Red", 4, 1));
    d1.add(CreatureCard("Hobgoblin", 3, "Red", 3, 3));
    d1.add(CreatureCard("Vampire", 4, "Black", 6, 3));*/

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