//
// Created by bilai on 05/01/2022.
//

#include <string>
#include <iostream>
#include <random>
#include "header/Player.h"
#include "header/Deck.h"
#include "header/Game.h"

Game::Game() : p1("", Deck()), p2("", Deck()) {
    nbRound = 0;
}

void Game::playGame() {
    showBanner();
    initGame();
    std::cout << "\nBienvenue aux joueurs " << p1.getName() << " et " << p2.getName() << " !\n\n";
    std::cout << "### Tirage au sort du joueur qui commence ###\n\n";
    bool randBool = 0 + (rand() % (1 - 0 + 1)) == 1;
    if (randBool)
        playerTurn = &p1;
    else
        playerTurn = &p2;
    std::cout << "C'est à " << playerTurn->getName() << " de commencer.\n\n";
}


void Game::showBanner() {
    std::cout
            << "  _   _  ____ _______   __  __          _____ _____ _____ \n"
            << " | \\ | |/ __ \\__   __| |  \\/  |   /\\   / ____|_   _/ ____|\n"
            << " |  \\| | |  | | | |    | \\  / |  /  \\ | |  __  | || |     \n"
            << " | . ` | |  | | | |    | |\\/| | / /\\ \\| | |_ | | || |     \n"
            << " | |\\  | |__| | | |    | |  | |/ ____ \\ |__| |_| || |____ \n"
            << " |_| \\_|\\____/  |_|    |_|  |_/_/    \\_\\_____|_____\\_____|\n\n";
}

void Game::initGame() {
    std::string nameP1("P1");
    std::string nameP2("P2");
    std::cout << "Quel est le nom du premier joueur ?\n";
    std::cin >> nameP1;
    std::cout << "\nQuel est le nom du deuxieme joueur ?\n";
    std::cin >> nameP2;
    p1 = Player(nameP1, Deck());
    p2 = Player(nameP2, Deck());
}
