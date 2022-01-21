//
// Created by bilai on 04/01/2022.
//

#ifndef MAGIC_CREATURECARD_H
#define MAGIC_CREATURECARD_H

#include "Card.h"

class CreatureCard : public Card  {
public:
    /**
     * Constructeurs des cartes créatures
     * @param nam
     * @param cout en terrain
     * @param couelur
     * @param attaque
     * @param point de vie
     */
    CreatureCard(std::string nam, std::vector<int> mC, std::string cl, int ap, int hp);
    /**
     * Récuper les points de vie
     * @return hp
     */
    int getHp() const;
    /**
     * Recuper les points d'attaques
     * @return attaque
     */
    int getAttackPower() const;
    /**
     * Set les hp
     * @param hp
     */
    void setHp(int hp);
    /**
     * Set l'attaque
     * @param attackPower
     */
    void setAttackPower(int attackPower);
    void invocate();
    /**
     * boolean si premier tour
     * @return
     */
    bool isFirstTurn();
    /**
     * Affichage
     */
    void print();
    /**
     * Affichage par ligne
     * @param line
     */
    void printLine(int line);
    void attack();

protected:
    int hp;
    int defaultHp;
    int attackPower;
    bool firstTurn;
};


#endif //MAGIC_CREATURECARD_H
