//
// Created by bilai on 04/01/2022.
//

#ifndef MAGIC_CARD_H
#define MAGIC_CARD_H
#include <string>

class Card {
protected:
    std::string name;
    int manaCost;
    std::string color;
    bool isDiscarded = false;
    bool isEngaged = false;
    std::string typeOfCard;

public:
    Card(std::string nm, int mnCt, std::string clr);

    void setName(const std::string &name);

    void Engage();

    void Disengage();

    bool getEngage();

    void setManaCost(int manaCost);

    void setColor(const std::string &color);

    void setIsDiscarded(bool isDiscarded);


    const std::string &getName() const;

    int getManaCost() const;

    const std::string &getColor() const;

    bool getIsDiscarded() const;


     ~Card();

    void isStillOperational();


};

#endif //MAGIC_CARD_H
