//
// Created by bilai on 22/01/2022.
//

#ifndef MAGIC_ENCHANTMENTCARD_H
#define MAGIC_ENCHANTMENTCARD_H
#include <vector>
#include <string>
#include "Card.h"

class EnchantmentCard : public Card {
public :
    EnchantmentCard(std::string name, std::vector<int> manaCost , std::string cl)

    ~EnchantmentCard();

private :
    void effect();


};


#endif //MAGIC_ENCHANTMENTCARD_H
