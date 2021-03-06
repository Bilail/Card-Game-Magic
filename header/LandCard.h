//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_LANDCARD_H
#define MAGIC_LANDCARD_H

#include <string>

#include "Card.h"

class LandCard : public Card {
public :
    /**
     * Constructeur d'une carte terrain
     * @param nom
     * @param couleur
     */
    LandCard(std::string nm, std::string clr);
    ~LandCard();
    void printLine(int line);
};


#endif //MAGIC_LANDCARD_H
