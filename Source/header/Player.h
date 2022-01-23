//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_PLAYER_H
#define MAGIC_PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
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
    /**
     * Constructeur d'un joueur
     */
    Player(std::string, Deck);
    ~Player(){};
    /**
     * set la couleur du joueur
     * @param color
     */
    void setPrintColor(std::string color);
    /**
     * Set le nom du joueurs
     * @return
     */
    std::string getName();
    std::string getColoredName();
    /**
     * récupère les hp du joueurs
     * @return
     */
    int getHp();
    /**
     * set les hp du joueurs
     * @param hp
     */
    void setHp(int hp);
    /**
     * piocher une carte
     * @return
     */
    bool drawCard();
    /**
     * désengager ses cartes
     */
    void disengageCards();
    /**
     * ses cartes jouables
     * @return
     */
    std::vector<Card*> getPlayableCards();
    void playCard(Card* c);
    /**
     * ses cartes qui peuvent attaquer
     * @return
     */
    std::vector<Card*> getAttackCards();
    /**
     * ses cartes qui peuvent défendre
     * @return
     */
    std::vector<Card*> getDefenseCards();
    /**
     * envoyer une carte au cimetière
     * @param c
     */
    std::vector<Card*> getHandCards();
    void discardCard(Card* c);
};


#endif //MAGIC_PLAYER_H
