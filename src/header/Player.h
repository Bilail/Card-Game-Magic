//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_PLAYER_H
#define MAGIC_PLAYER_H

#include <string>

#include "Deck.h"


class Player {
protected :
    std::string name;
    std::string printColor;
    bool isAlive;
    int currentHp;
    static int baseHp;
    Deck cards;
public :
    Player(std::string, Deck);
    ~Player(){};
    void setPrintColor(std::string color);
    std::string getName();

};


#endif //MAGIC_PLAYER_H
