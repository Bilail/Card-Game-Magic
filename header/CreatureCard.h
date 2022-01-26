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
     * @param couleur
     * @param attaque
     * @param point de vie
     */
    CreatureCard(std::string nam, std::vector<int> mC, std::vector<std::string> capa, std::string cl, int ap, int hp);
    /**
     * Récupère les points de vie
     * @return hp
     */
    int getHp() const;
    /**
     * Récupère les points d'attaques
     * @return attaque
     */
    int getAttackPower() const;
    /**
     * getter pour les capacités
     * @return
     */
    std::vector<std::string> getCapacities() const;
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
    /**
     * set le boolean firstTurn
     * @param b
     */
    void setFirstTurn(int b);
    /**
     * boolean si premier tour
     * @return
     */
    bool isFirstTurn();
    /**
     * Affichage des capacités
     * @return
     */
    std::string capacitiesToString();
    /**
     * Affichage par ligne
     * @param line
     */
    void printLine(int line);
    /**
     * Désengager une carte
     */
    void disengage();
    /**
     * Réinitialise les points de vie de la créature
     */
    void resetHp();
    /**
     * Permet de savoir si la carte possède la capacité transmise en paramètre
     * @param capacity
     * @return
     */
    bool hasCapacity(std::string capacity);
protected:
    int hp;
    int defaultHp;
    int attackPower;
    bool firstTurn;
    std::vector<std::string> capacities;
};


#endif //MAGIC_CREATURECARD_H
