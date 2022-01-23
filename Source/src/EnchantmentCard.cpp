//
// Created by bilai on 22/01/2022.
//

#include "../header/EnchantmentCard.h"
#include <vector>
#include <string>

enum enchantment {
    white,
    blue,
    black,
    red,
    green
};

EnchantmentCard::EnchantmentCard(std::string name, std::vector<int> manaCost , std::string cl) : Card(name, manaCost, cl) {
    associate = NULL
}

EnchantmentCard::~EnchantmentCard() {

}

void EnchantmentCard::effect() {
    
}


