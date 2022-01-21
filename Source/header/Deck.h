//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_DECK_H
#define MAGIC_DECK_H

#include <vector>
#include <bits/stdc++.h>
#include "Card.h"
#include "GameCards.h"
#include <string>

class Deck {
protected:
    std::vector<Card*> inPlayCards;
    std::vector<Card*> handCards;
    std::vector<Card*> library;
    std::vector<Card*> disCards;
public:
    static const int DECK_SIZE;
    /**
     * Constructeur avec un deck par default
     */
    Deck();
    /**
     * Constructeur avec le choix d'un deck stocké en json
     * @param nomDeck
     */
    Deck(std::string nomDeck);
    ~Deck();
    /**
     * Affiche toute les cartes du joueurs
     */
    void printLibrary();
    /**
     * Affiche les cartes que le joueur peut jouer
     */
    void printInPlayCards();
    /**
     * Mélange le deck
     */
    void generateRandomDeck();
    /**
     * Piocher une carte
     * @return
     */
    bool drawCard();
    /**
     * désengager la carte
     */
    void disengageCards();
    /**
     * Obtenir les cartes jouable par le joueurs
     * @return
     */
    std::vector<Card*> getPlayableCards();
    /**
     * Les cartes qui peuvent attaquer
     * @return
     */
    std::vector<Card*> getAttackCards();
    /**
     * Les cartes qui peuvent défendre
     * @return
     */
    std::vector<Card*> getDefenseCards();
    /**
     * Les cartes jouables
     * @param c
     */
    std::vector<Card*> getHandCards();
    void playCard(Card* c);
    /**
     * Les cartes dans le cimetière
     * @param c
     */
    void discardCard(Card* c);
    /**
     * Fonction qui convertit un fichier json de carte en deck jouable
     * @param nomDeck
     */
    void JsonToDeck(std::string nomDeck);
    void CardtoJson(std::string nomDeck);
    void exportToJson(std::string filename);

};


#endif //MAGIC_DECK_H
