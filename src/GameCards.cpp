//
// Created by dope on 08/01/2022.
//

#include "header/GameCards.h"

GameCards::GameCards() {
    //  Création des créatures
    creatures.push_back(CreatureCard("Soldier", {0,0,0,1,0,2}, "yellow", 1, 1));
    creatures.push_back(CreatureCard("ArmoredPegasus", {0,0,0,1,0,1}, "yellow", 1, 2));
    creatures.push_back(CreatureCard("Phase Dolphin", {0,2,0,0,0,2}, "blue", 1, 4));
    creatures.push_back(CreatureCard("AngryBear", {1,0,0,0,0,1}, "green", 3, 2));
    creatures.push_back(CreatureCard("Guard", {0,0,0,2,0,4}, "yellow", 2, 5));
    creatures.push_back(CreatureCard("Werewolf", {0,0,0,1,0,4}, "green", 4, 6));
    creatures.push_back(CreatureCard("Skeleton", {0,0,0,0,1,1}, "black", 1, 1));
    creatures.push_back(CreatureCard("Ghost", {0,0,0,0,1,2}, "black", 2, 1));
    creatures.push_back(CreatureCard("BlackKnight", {0,0,0,0,1,2}, "black", 2, 2));
    creatures.push_back(CreatureCard("Naga Eternal", {0,2,0,0,0,1}, "blue", 3, 2));
    creatures.push_back(CreatureCard("Vampire", {0,0,0,0,1,4}, "black", 6, 3));
    creatures.push_back(CreatureCard("Hobgoblin", {0,3,1,1,0,3}, "red", 3, 3));

    // Création des terrains
    lands.push_back(LandCard("Forest", "Green"));
    lands.push_back(LandCard("Island",  "Blue"));
    lands.push_back(LandCard("Mountain", "Red"));
    lands.push_back(LandCard("Plain", "Yellow"));
    lands.push_back(LandCard("Swamp", "Black"));
}


const std::vector<CreatureCard>& GameCards::getCreatures() {
    return creatures;
}

const std::vector<LandCard>& GameCards::getLands() {
    return lands;
}
