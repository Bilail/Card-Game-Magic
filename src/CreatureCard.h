//
// Created by bilai on 04/01/2022.
//

#ifndef MAGIC_CREATURECARD_H
#define MAGIC_CREATURECARD_H

#include "Card.h"

class CreatureCard : public Card  {
public:
    CreatureCard(std::string nam, int mC, std::string cl, int ap, int hp, bool fstStk, bool trmb);

    int getHp() const;

    int getAttackPower() const;

    bool getIsTapped() const;

    bool isHasFirstStr() const;

    bool isHasTrmb() const;

    void setHp(int hP);

    void setAttackPower(int attackPower);

    void setIsTapped(bool isTapped);

    void setHasFirstStr(bool hasFirstStr);

    void setHasTrmb(bool hasTrmb);

protected:
    int hP;
    int attackPower;
    bool isTapped;
    bool hasFirstStr;
    bool hasTrmb;
};


#endif //MAGIC_CREATURECARD_H
