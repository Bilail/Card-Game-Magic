//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_GAME_H
#define MAGIC_GAME_H

#include "Player.h"


class Game {
protected:
    Player p1;
    Player p2;
    int tour;

public :
    Game();
    //Game(Game const &); //reprendre une game
    void playGame();

};


#endif //MAGIC_GAME_H
