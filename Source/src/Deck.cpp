//
// Created by bilai on 05/01/2022.
//

#include <vector>
#include <string>
#include <fstream>
#include "../header/Util.h"
#include "../header/Card.h"
#include "../header/Deck.h"

#include "../dependance/json.hpp"
using json = nlohmann::json;

const int Deck::DECK_SIZE = 30;

Deck::Deck() {
    GameCards gc;
    for (CreatureCard c : gc.getCreatures()) {
        library.push_back(new CreatureCard(c));
    }
    for(LandCard l : gc.getLands()) {
        library.push_back(new LandCard(l));
        library.push_back(new LandCard(l));
    }
}

Deck::Deck(std::string nomDeck){
    importFromJson(nomDeck);
}

Deck::~Deck() {
}

void Deck::printLibrary() {
    Card::print(library);
}

void Deck::printInPlayCards() {
    Card::print(inPlayCards);
}

void Deck::generateRandomDeck() {
    for (int i=0; i<library.size() ;i++)
    {
        // Random for remaining positions.
        int r = i + (rand() % (library.size() -i));
        std::swap(library[i], library[r]);
    }
}

bool Deck::drawCard(){
    if(library.size() == 0 ){
        return false;
    }
    else {
        handCards.push_back(library.back());
        library.pop_back();
        return true;
    }
}

void Deck::disengageCards() {
    for (int i = 0; i < inPlayCards.size(); i++) {
        inPlayCards.at(i)->disengage();
    }
}

std::vector<Card*> Deck::getPlayableCards() {
    std::vector<int> manaAvailable(6,0);
    for (Card* c : inPlayCards) {
        if (!c->getIsEngaged()) {
            if (dynamic_cast<const LandCard*>(c)) {
                manaAvailable.at(5) += 1;
                int colorIndex = getIndex(Card::ColorCode, c->getColor());
                manaAvailable.at(colorIndex) += 1;
            }
        }
    }
    std::vector<Card*> playableCards;
    for (Card* c : handCards) {
        int landCardsUsed = 0;
        for (int i = 0; i < c->getManaCost().size(); i++) {
            if (i == 5) { // La position 5 correspond à tout type de terrain
                if (c->getManaCost().at(i) <= manaAvailable.at(i) - landCardsUsed)
                    playableCards.push_back(c);
            }
            else {
                if (c->getManaCost().at(i) <= manaAvailable.at(i))
                    landCardsUsed  += c->getManaCost().at(i);
                else
                    break;
            }
        }
    }
    return playableCards;
}

void Deck::playCard(Card* c) {
    // On commence par engager les terrains nécessaires pour poser la carte
    for (int i = 0; i < c->getManaCost().size(); i++) {
        for (int j = 0; j < c->getManaCost().at(i); j++) {
            for (int k = 0; k < inPlayCards.size(); k++) {
                if (dynamic_cast<const LandCard*>(inPlayCards.at(k))) {
                    if (!inPlayCards.at(k)->getIsEngaged()) {
                        if (inPlayCards.at(k)->getColor() == Card::ColorCode[i] || i == 5) {
                            inPlayCards.at(k)->engage();
                            break;
                        }
                    }
                }
            }
        }
    }
    // Puis on transfère la carte de la main vers les cartes en jeu
    int idx = getIndex(handCards, c);
    handCards.erase(handCards.begin() + idx);
    inPlayCards.push_back(c);
}

std::vector<Card*> Deck::getAttackCards() {
    std::vector<Card*> attackCards;
    for( Card* c : inPlayCards )
        if (!c->getIsEngaged())
            if (dynamic_cast<const CreatureCard*>(c))
                attackCards.push_back(c);
    return attackCards;
}

std::vector<Card*> Deck::getDefenseCards() {
    std::vector<Card*> defenseCards;
    for( Card* c : inPlayCards )
        if (!c->getIsEngaged())
            if (dynamic_cast<const CreatureCard*>(c))
                defenseCards.push_back(c);
    return defenseCards;
}

void Deck::discardCard(Card *c) {
    for (int i = 0; i < inPlayCards.size(); i++) {
        if (inPlayCards.at(i) == c) {
            inPlayCards.erase(inPlayCards.begin()+i);
            return;
        }
    }
    for (int i = 0; i < handCards.size(); i++) {
        if (handCards.at(i) == c) {
            handCards.erase(handCards.begin()+i);
            return;
        }
    }
}

std::vector<Card*> Deck::getHandCards() {
    return handCards;
}

void Deck::importFromJson(std::string nomDeck) {
    std::ifstream ifs(nomDeck+".json");
    json deck;
    ifs >> deck;

    // Ajout des créatures
    auto& creatures = deck["Deck"]["Creature"];
    for (auto& creature : creatures.items()){
        std::string name = creature.value()["name"];
        std::vector<int> mana = creature.value()["cost"];
        std::string color = creature.value()["color"];
        int attack = creature.value()["attack"];
        int hp = creature.value()["hp"];

        library.push_back(new CreatureCard(name, mana, color, attack, hp));
    }

    // Ajout des terrains
    auto& lands = deck["Deck"]["Land"];
    for (auto& land : lands.items()){
        std::string name = land.value()["name"];
        std::string color = land.value()["color"];
        library.push_back(new LandCard(name, color));
    }

    // Ajout des enchantements
    auto& enchantments = deck["Deck"]["Enchantment"];
    for (auto& enchantment : enchantments.items()){
        std::string name = enchantment.value()["name"];
        library.push_back(new EnchantmentCard(name));
    }
}

void Deck::exportToJson(std::string filename) {
    json jsonfile;
    jsonfile["Deck"]["Creature"] = json::array({});
    jsonfile["Deck"]["Land"] = json::array({});
    for (Card* c : library) {
        if (CreatureCard* cc = dynamic_cast<CreatureCard*>(c)) {
            json j = {
                    {"name", cc->getName()},
                    {"cost", {
                        cc->getManaCost()[0],
                        cc->getManaCost()[1],
                        cc->getManaCost()[2],
                        cc->getManaCost()[3],
                        cc->getManaCost()[4],
                        cc->getManaCost()[5]
                    }},
                    {"color", cc->getColor()},
                    {"attack", cc->getAttackPower()},
                    {"hp", cc->getHp()}
            };
            jsonfile["Deck"]["Creature"].push_back(j);
        }
        else if (LandCard* lc = dynamic_cast<LandCard*>(c)) {
            json j = {
                    {"name", lc->getName()},
                    {"color", lc->getColor()}
            };
            jsonfile["Deck"]["Land"].push_back(j);
        }
    }
    std::ofstream file(filename + ".json");
    file << jsonfile;
}

std::vector<EnchantmentCard*> Deck::getEnchantmentInGame(){
    return enchantmentInGame;
}

bool Deck::GetEnchant(std::string e){
    for(EnchantmentCard* c : enchantmentInGame){
        if ( c->getName() == e){
            return true;
        }
    }
    return false;
}


