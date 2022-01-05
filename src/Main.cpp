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

    Game game;
    game.playGame();

    //Création des cartes :
    CreatureCard("Soldier", 1, "White", 1, 1);
    CreatureCard("ArmoredPegasus", 2, "White", 1, 2);
    CreatureCard("WhiteKnight", 2, "White", 2, 2);
    CreatureCard("AngryBear", 3, "Green", 3, 2);
    CreatureCard("Guard", 4, "White", 2, 5);
    CreatureCard("Werewolf", 4, "Green", 4, 6);
    CreatureCard("Skeleton", 1, "Black", 1, 1);
    CreatureCard("Ghost", 2, "Black", 2, 1);
    CreatureCard("BlackKnight", 2, "Black", 2, 2);
    CreatureCard("OrcManiac", 3, "Red", 4, 1);
    CreatureCard("Hobgoblin", 3, "Red", 3, 3);
    CreatureCard("Vampire", 4, "Black", 6, 3);

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