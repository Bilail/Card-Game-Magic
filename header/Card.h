//
// Created by bilai on 04/01/2022.
//

#ifndef MAGIC_CARD_H
#define MAGIC_CARD_H

#include <iostream>
#include <string>
#include <vector>

class Card {
protected:
    std::string name;
    std::vector<int> manaCost; // { Forest Green , Island Blue , Mountain Red, Plain Yellow, Swamp Black, Other }
    std::string color;
    bool isEngaged = false;

public:
    /**
     * Constructeur de card
     * @param nm : le nom de la carte
     * @param mnCt : son cout en terrain
     * @param clr : sa couleur
     */
    Card(std::string nm, std::vector<int> mnCt, std::string clr);
    static std::vector<std::string> ColorCode;
    /**
     * Fonction qui permet de saisir le nom d'une carte
     * @param name le nom de la carte
     */
    void setName(const std::string &name);
    /**
     * Engager une carte
     */
    void engage();
    /**
     * Désengager une carte
     */
    virtual void disengage();
    /**
     * Saisir le cout en terrain
     * @param manaCost
     */
    void setManaCost(std::vector<int> manaCost);
    /**
     * Saisir la couleur
     * @param color
     */
    void setColor(const std::string &color);
    /**
     * Récupéré le nom de la carte
     * @return name
     */
    const std::string &getName() const;
    /**
     * Récupéré le nom de la couleur  de la carte
     * @return couleur
     */
    const std::string getColoredName() const;
    /**
     * Affiche le nom de la carte coloré
     * @return
     */
    std::vector<int> getManaCost() const;
    /**
     * Récupérer la couleur
     * @return
     */
    const std::string &getColor() const;
    /**
     * Engagé ou pas
     * @return
     */
    bool getIsEngaged() const;
    /**
     * Destructeur
     */
     ~Card();
    /**
     * Fonction d'affichage
     */
    virtual void print();
    /**
     * Fonction d'affichage par ligne
     * Pour l'affiche en ligne et non pas en colonne
     * @param line
     */
    virtual void printLine(int line);
    /**
     * Cout en terrain en string
     * @return
     */
    std::string manaToString();
    static void print(std::vector<Card*> v);

};

#endif //MAGIC_CARD_H
