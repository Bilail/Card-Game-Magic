//
// Created by bilai on 05/01/2022.
//

#include <string>
#include <iostream>
#include "header/Player.h"
#include "header/Deck.h"
#include "header/Game.h"

Game::Game() : p1("", Deck()), p2("", Deck()) {
    std::string nameP1("P1");
    std::string nameP2("P2");
    std::cout << "Quel est le nom du premier joueur ?\n";
    std::cin >> nameP1;
    std::cout << "Quel est le nom du deuxieme joueur ?\n";
    std::cin >> nameP2;
    Player p1(nameP1, Deck());
    Player p2(nameP2, Deck());
}

void Game::playGame() {
    std::cout << "Debut de la game" << std::endl;
    //std::cout << "Bienvenue aux joueurs " << p1.getName() << " et " << p2.getName() << std::endl;

}
