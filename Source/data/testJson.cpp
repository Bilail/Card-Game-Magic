//
// Created by bilai on 16/01/2022.
//

#include "../header/Card.h"
#include "../header/CreatureCard.h.h"
#include "../header/LandCard.h.h"
#include "../header/Deck.h"
#include <vector>
#include "../dependance/json.hpp"
using json = nlohmann::json;

vector<Card e* > Deck::CardtoJson(string nomDeck){
    vector<Card*> r = {};
    std::ifstream ifs(nomDeck+".json");
    json deck;
    ifs >> deck;

    // Ajout des créature dans le deck

}
