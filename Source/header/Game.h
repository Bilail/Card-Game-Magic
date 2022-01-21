//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_GAME_H
#define MAGIC_GAME_H

#include "Player.h"


class Game {
private:
    /**
     * Affiche le titre du jeux
     */
    void showBanner();*
    /**
     * Initialise la game
     * les joueurs et les decks
     */
    void initGame();
    /**
     * Tirage au sort du joueurs qui commencent
     */
    void randomDraw();
    /**
     * Phase de jeux principale
     * picoher, poser les cartes,..
     */
    void mainPhase();
    /**
     * Phase de combat
     * Attaque et défense
     */
    void fightPhase();
    /**
     * Retourne le joueur ennemie
     * @return joueur ennemeie
     */
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
    /**
     * Lance la partie
     */
    void playGame();
    /**
     * Nombre de carte maximum dans la main
     */
    static int MAX_CARDS_IN_HAND;
};


#endif //MAGIC_GAME_H
