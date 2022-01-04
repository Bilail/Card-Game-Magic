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
    bool isDiscarded;
    std::string typeOfCard;

public:
    Card(std::string nm, int mnCt, std::string clr, std::string typeOfCard);

    void setName(const std::string &name);

    void setManaCost(int manaCost);

    void setColor(const std::string &color);

    void setIsDiscarded(bool isDiscarded);

    void setTypeOfCard(const std::string &typeOfCard);

    const std::string &getName() const;

    int getManaCost() const;

    const std::string &getColor() const;

    bool getIsDiscarded() const;

    const std::string &getTypeOfCard() const;

    virtual ~Card();



};

#endif //MAGIC_CARD_H
