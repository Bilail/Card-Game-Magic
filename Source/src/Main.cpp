//
// Created by bilai on 04/01/2022.
//
#include <iostream>

#include "../header/Card.h"
#include "../header/CreatureCard.h"
#include "../header/LandCard.h"
#include "../header/Game.h"
#include "../header/DeckCreator.h"

#include "../dependance/json.hpp"
using json = nlohmann::json;

int main() {

    std::cout << "\n#### MENU PRINCIPAL ####\n\n";

    std::cout << "- 1 : Lancement du jeu\n";
    std::cout << "- 2 : Création d'un deck personnalisé\n";
    std::cout << "\nSaisissez le numéro de l'application que vous souhaitez démarrer : ";
    std::string input;
    bool validInput = false;
    while (!validInput) {
        std::getline(std::cin, input);
        if (input == "1") {
            validInput = true;
            Game game;
            game.playGame();
        }
        else if (input == "2") {
            DeckCreator dc;
            dc.startApp();
            validInput = true;
        }
        else {
            std::cout << "Réponse inconnue, veuillez réessayer : ";
        }
    }

    return 0;
}