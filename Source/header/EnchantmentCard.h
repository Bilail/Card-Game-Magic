//
// Created by bilai on 22/01/2022.
//

#ifndef MAGIC_ENCHANTMENTCARD_H
#define MAGIC_ENCHANTMENTCARD_H
#include <vector>
#include <string>
#include "Card.h"
#include "StrColor.h"

class EnchantmentCard : public Card {
public :
    EnchantmentCard(std::string name);

    ~EnchantmentCard();

    void effect();
    void print();
    void printLine(int line);

protected :
    Card* associate;

};


#endif //MAGIC_ENCHANTMENTCARD_H
