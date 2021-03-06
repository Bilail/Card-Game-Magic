//
// Created by bilai on 05/01/2022.
//

#ifndef MAGIC_DECK_H
#define MAGIC_DECK_H

#include <vector>
#include <bits/stdc++.h>
#include "Card.h"
#include "GameCards.h"
#include "EnchantmentCard.h"
#include <string>

class Deck {
protected:
    std::vector<Card*> inPlayCards;
    std::vector<Card*> handCards;
    std::vector<Card*> library;
    std::vector<Card*> disCards;
    std::vector<Card*> enchantmentInGame;
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
    /**
     * Constructeur avec le choix des créatures
     * @param creatures
     */
    Deck(std::vector<CreatureCard> creatures);
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
     * @param filename
     */
    void importFromJson(std::string filename);
    /**
     * Fonction qui convertit un deck de carte en fichier json
     * @param filename
     */
    void exportToJson(std::string filename);

    std::vector<Card*> getEnchantmentInGame();
    bool hasEnchant(std::string e);
    std::vector<Card*> getCreatureCard();
    std::vector<Card*> getCardInPlay();
    int getNbForest();
    void addCardInPlay(Card* c);
    void removeCard(Card* c );

};


#endif //MAGIC_DECK_H
