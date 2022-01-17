//
// Created by bilai on 17/01/2022.
//

vector<Card e* > Deck::CardtoJson(string nomDeck){
    vector<Card*> r = {};
    std::ifstream ifs(nomDeck+".json");
    json deck;
    ifs >> deck;

    // Ajout des créature dans le deck

}