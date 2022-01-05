//
// Created by bilai on 04/01/2022.
//

#ifndef MAGIC_CREATURECARD_H
#define MAGIC_CREATURECARD_H

#include "Card.h"

class CreatureCard : public Card  {
public:
    CreatureCard(std::string nam, int mC, std::string cl, int ap, int hp);

    int getHp() const;

    int getAttackPower() const;

    void setHp(int hp);

    void setAttackPower(int attackPower);

    void invocate();

    bool isFirstTurn();

protected:
    int hp;
    int defaultHp;
    int attackPower;
    bool firstTurn;
};


#endif //MAGIC_CREATURECARD_H
