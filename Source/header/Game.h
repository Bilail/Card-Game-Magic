//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_GAME_H
#define MAGIC_GAME_H

#include "Player.h"


class Game {
private:
    void showBanner();
    void initGame();
    void randomDraw();
    void mainPhase();
    void fightPhase();
    void endOfTurnPhase();
    Player* getOpponent();
protected:
    Player p1;
    Player p2;
    Player* playerTurn;
    bool playerHasPlayedLandCard;
    int round;

public :
    Game();
    //Game(Game const &); //reprendre une game
    void playGame();
    static int MAX_CARDS_IN_HAND;
};


#endif //MAGIC_GAME_H
