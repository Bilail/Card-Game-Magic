//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_LANDCARD_H
#define MAGIC_LANDCARD_H

#include <string>

#include "Card.h"

class LandCard : public Card {
public :
    LandCard(std::string nm, std::string clr);
    ~LandCard(){};

    };


#endif //MAGIC_LANDCARD_H
