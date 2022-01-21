//
// Created by dope on 08/01/2022.
//

#ifndef MAGIC_GAMECARDS_H
#define MAGIC_GAMECARDS_H

#include <vector>
#include "Card.h"
#include "CreatureCard.h"
#include "LandCard.h"

class GameCards {
private:
    std::vector<CreatureCard> creatures;
    std::vector<LandCard> lands;
public:
    /**
     * Créer un deck par défaut
     */
    GameCards();
    const std::vector<CreatureCard>& getCreatures();
    const std::vector<LandCard>& getLands();
};


#endif //MAGIC_GAMECARDS_H
