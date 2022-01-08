//
// Created by dope on 08/01/2022.
//

#include "header/GameCards.h"

GameCards::GameCards() {
    creatures.push_back(CreatureCard ("Soldier", 1, "yellow", 1, 1));
    creatures.push_back(CreatureCard("ArmoredPegasus", 2, "yellow", 1, 2));
    creatures.push_back(CreatureCard("Phase Dolphin", 2, "blue", 1, 4));
    creatures.push_back(CreatureCard("AngryBear", 3, "green", 3, 2));
    creatures.push_back(CreatureCard("Guard", 4, "yellow", 2, 5));
    creatures.push_back(CreatureCard("Werewolf", 4, "green", 4, 6));
    creatures.push_back(CreatureCard("Skeleton", 1, "black", 1, 1));
    creatures.push_back(CreatureCard("Ghost", 2, "black", 2, 1));
    creatures.push_back(CreatureCard("BlackKnight", 2, "black", 2, 2));
    creatures.push_back(CreatureCard("Naga Eternal", 2, "blue", 3, 2));
    creatures.push_back(CreatureCard("Vampire", 4, "black", 6, 3));
    creatures.push_back(CreatureCard("Hobgoblin", 3, "red", 3, 3));
}

const std::vector<CreatureCard>& GameCards::getCreatures() {
    return creatures;
}

const std::vector<LandCard>& GameCards::getLands() {
    return lands;
}
