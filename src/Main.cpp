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
    game.playGame();

    //Création des cartes :
    Deck d1;
    GameCards gc;

    /*for (int i = 0; i < gc.getCreatures().size(); i++)
        d1.addCreature(gc.getCreatures().at(i));*/

    /*
    std::cout << " ------- Deck de base ------- " << std::endl;
    d1.printLibrary();std::cout << "on mélange " << std::endl;
    d1.generateRandomDeck();
    std::cout << "------- Deck mélanger ------- " << std::endl;
    d1.printLibrary();
*/
    return 0;
}