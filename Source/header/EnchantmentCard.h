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
    EnchantmentCard(std::string name, std::string color);

    ~EnchantmentCard();

    void effect();
    void print();
    void printLine(int line);
    void associate(Card* CardToAssociate);
    Card* getAsso();

protected :
    Card* asso;

};


#endif //MAGIC_ENCHANTMENTCARD_H
