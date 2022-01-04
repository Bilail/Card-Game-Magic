//
// Created by bilai on 04/01/2022.
//
#include <vector>

#include "Card.h"
#include "CreatureCard.h"


int main(){


//Création des cartes :

    class Soldier : public CreatureCard {
    public:
        Soldier() : CreatureCard("Soldier", 1, "White", 1, 1, false, false) {}
    };

    class ArmoredPegasus : public CreatureCard {
    public:
        ArmoredPegasus() : CreatureCard("ArmoredPegasus", 2, "White", 1, 2, false, false) {}
    };

    class WhiteKnight : public CreatureCard {
    public:
        WhiteKnight() : CreatureCard("WhiteKnight", 2, "White", 2, 2, true, false) {}
    };

    class AngryBear : public CreatureCard {
    public:
        AngryBear() : CreatureCard("AngryBear", 3, "Green", 3, 2, false, true) {}
    };

    class Guard : public CreatureCard {
    public:
        Guard() : CreatureCard("Guard", 4, "White", 2, 5, false, false) {}
    };

    class Werewolf : public CreatureCard {  //TRAMPLE
    public:
        Werewolf() : CreatureCard("Werewolf", 4, "Green", 4, 6, false, true) {}
    };

    class Skeleton : public CreatureCard {
    public:
        Skeleton() : CreatureCard("Skeleton", 1, "Black", 1, 1, false, false) {}
    };

    class Ghost : public CreatureCard {
    public:
        Ghost() : CreatureCard("Ghost", 2, "Black", 2, 1, false, false) {}
    };

    class BlackKnight : public CreatureCard {
    public:
        BlackKnight() : CreatureCard("BlackKnight", 2, "Black", 2, 2, true, false) {}
    };

    class OrcManiac : public CreatureCard {
    public:
        OrcManiac() : CreatureCard("OrcManiac", 3, "Red", 4, 1, false, false) {}
    };

    class Hobgoblin : public CreatureCard {
    public:
        Hobgoblin() : CreatureCard("Hobgoblin", 3, "Red", 3, 3, false, false) {}
    };

    class Vampire : public CreatureCard {
    public:
        Vampire() : CreatureCard("Vampire", 4, "Black", 6, 3, false, false) {}
    };


    std::vector<CreatureCard> CreatureCard{Soldier(), ArmoredPegasus(), WhiteKnight(), AngryBear(), Guard(), Werewolf(),Skeleton(),Ghost(), BlackKnight(),OrcManiac(), Hobgoblin(), Vampire()};

}