//
// Created by bilai on 04/01/2022.
//
#include <vector>
#include <iostream>

#include "../header/Card.h"
#include "../header/CreatureCard.h"
#include "../header/LandCard.h"
#include "../header/Game.h"
#include "../header/Deck.h"
#include "../header/GameCards.h"

#include <filesystem>
#include "../dependance/json.hpp"
using json = nlohmann::json;

int main() {

    Game game;
    game.playGame();

    /*
    std::cout << "\nContenu de ./data/ :\n";
    std::string path = "./data/";
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::cout << entry.path().filename() << std::endl;
    }

    Deck d;
    std::cout << "\ngénération du json...\n";
    d.exportToJson("test");
    std::cout << "export terminé\n";
    */

    //Création des cartes :
    /*    Deck d1;
    GameCards gc;

    // Test Json :
    Deck *d2 = new Deck("./data/cards");
    d2->printLibrary();
*/
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