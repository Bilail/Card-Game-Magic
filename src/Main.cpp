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


//Création des cartes :

    class Soldier : public CreatureCard {
    public:
        Soldier() : CreatureCard("Soldier", 1, "White", 1, 1) {}
    };

    class ArmoredPegasus : public CreatureCard {
    public:
        ArmoredPegasus() : CreatureCard("ArmoredPegasus", 2, "White", 1, 2) {}
    };

    class WhiteKnight : public CreatureCard {
    public:
        WhiteKnight() : CreatureCard("WhiteKnight", 2, "White", 2, 2) {}
    };

    class AngryBear : public CreatureCard {
    public:
        AngryBear() : CreatureCard("AngryBear", 3, "Green", 3, 2) {}
    };

    class Guard : public CreatureCard {
    public:
        Guard() : CreatureCard("Guard", 4, "White", 2, 5) {}
    };

    class Werewolf : public CreatureCard {  //TRAMPLE
    public:
        Werewolf() : CreatureCard("Werewolf", 4, "Green", 4, 6) {}
    };

    class Skeleton : public CreatureCard {
    public:
        Skeleton() : CreatureCard("Skeleton", 1, "Black", 1, 1) {}
    };

    class Ghost : public CreatureCard {
    public:
        Ghost() : CreatureCard("Ghost", 2, "Black", 2, 1) {}
    };

    class BlackKnight : public CreatureCard {
    public:
        BlackKnight() : CreatureCard("BlackKnight", 2, "Black", 2, 2) {}
    };

    class OrcManiac : public CreatureCard {
    public:
        OrcManiac() : CreatureCard("OrcManiac", 3, "Red", 4, 1) {}
    };

    class Hobgoblin : public CreatureCard {
    public:
        Hobgoblin() : CreatureCard("Hobgoblin", 3, "Red", 3, 3) {}
    };

    class Vampire : public CreatureCard {
    public:
        Vampire() : CreatureCard("Vampire", 4, "Black", 6, 3) {}
    };


    //std::vector<CreatureCard> CreatureCard{Soldier(), ArmoredPegasus(), WhiteKnight(), AngryBear(), Guard(), Werewolf(),Skeleton(),Ghost(), BlackKnight(),OrcManiac(), Hobgoblin(), Vampire()};


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

    LandCard sw("Swamp", 0, "Black");
    CreatureCard s("Soldier", 1, "White", 1, 1);
    //std::vector<Card> player1Deck =  {sw};//{Plain(), Plain(), Plain(), Plain(), Plain(),Forest(), Forest(), Forest(),Island(),Soldier(), Soldier(), Soldier(),ArmoredPegasus(), ArmoredPegasus(),WhiteKnight(), WhiteKnight(),AngryBear(),Guard(),Werewolf()};
    //,Disenchant(),LightningBolt(),Flood(), Flood(),Rage(),HolyWar(),HolyLight()
/*
    std::vector<Card> player2Deck{Swamp(), Swamp(), Swamp(), Swamp(), Swamp(),Mountain(), Mountain(), Mountain(),Island(),Skeleton(), Skeleton(), Skeleton(),Ghost(), Ghost(),BlackKnight(), BlackKnight(),OrcManiac(),Hobgoblin(),Vampire()};
    // ,Reanimate(),Plague(),Terror(),Terror(),UnholyWar(),Restrain(),Slow()
*/
    return 0;
}