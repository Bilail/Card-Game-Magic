//
// Created by dope on 08/01/2022.
//

#include "../header/GameCards.h"
#include <vector>
#include <fstream>
#include <string>
#include "../dependance/json.hpp"
using json = nlohmann::json;

GameCards::GameCards() {
    std::ifstream ifs("./data/cards.json");
    json deck;
    ifs >> deck;
    // Ajout des créatures
    auto& creaturesImported = deck["Deck"]["Creature"];
    for (auto& creature : creaturesImported.items()) {
        std::string name = creature.value()["name"];
        std::vector<int> mana = creature.value()["cost"];
        std::vector<std::string> capacities = creature.value()["capacities"];
        std::string color = creature.value()["color"];
        int attack = creature.value()["attack"];
        int hp = creature.value()["hp"];
        creatures.push_back(CreatureCard(name, mana, capacities, color, attack, hp));
    }
    // Ajout des terrains
    auto& landsImported = deck["Deck"]["Land"];
    for (auto& land : landsImported.items()){
        std::string name = land.value()["name"];
        std::string color = land.value()["color"];
        lands.push_back(LandCard(name, color));
    }
    // Ajout des enchantments
    auto& enchantmentsImported = deck["Deck"]["Enchantment"];
    for (auto& enchantment : enchantmentsImported.items()){
        std::string name = enchantment.value()["name"];
        std::string color = enchantment.value()["color"];
        enchantments.push_back(EnchantmentCard(name, color));
    }
}

const std::vector<CreatureCard>& GameCards::getCreatures() {
    return creatures;
}

const std::vector<LandCard>& GameCards::getLands() {
    return lands;
}

const std::vector<EnchantmentCard>& GameCards::getEnchantments() {
    return enchantments;
}