//
// Created by dope on 24/01/2022.
//
#include <iostream>
#include "../header/GameCards.h"
#include "../header/Deck.h"
#include "../header/DeckCreator.h"

DeckCreator::DeckCreator() {}

void DeckCreator::startApp() {
    showBanner();
    GameCards gc;
    std::cout << "Indiquer le nom du deck que vous souhaitez créer : ";
    std::string filename;
    std::getline(std::cin, filename);

    std::cout << "\nUn deck comporte 30 cartes au total.\n";
    std::cout << "10 cartes sont des terrains par défaut (2 de chaque couleur)\n";
    std::cout << "Vous allez donc choisir 20 créatures.\n";
    int nbCardsRemaining = 3;
    std::vector<CreatureCard> availableCreatures = gc.getCreatures();
    std::vector<CreatureCard> chosenCreatures;
    while (nbCardsRemaining > 0) {
        std::cout << "\nVoici la liste des cartes disponibles :\n";
        for (CreatureCard c : availableCreatures)
            std::cout << c.getColoredName() << " - ";
        std::cout << "\n";
        std::cout << "Il vous reste " << nbCardsRemaining << " carte(s) à choisir pour completer votre deck.\n";
        std::cout << "Indiquer le nom de la carte à ajouter : ";
        bool validInput = false;
        while (!validInput) {
            std::string input;
            std::getline(std::cin, input);
            for (int i = 0; i < availableCreatures.size(); i++) {
                if (availableCreatures[i].getName() == input) {
                    validInput = true;
                    std::cout << "Voici les détails de la carte sélectionnée :\n";
                    availableCreatures[i].print();
                    std::cout << "Voulez-vous l'ajouter au votre deck ? (y/n) ";
                    std::getline(std::cin, input);
                    while (input != "y" && input != "n") {
                        std::cout << "Réponse inconnue, veuillez réessayer : ";
                        std::getline(std::cin, input);
                    }
                    if (input == "y") {
                        std::cout << "La carte " << availableCreatures[i].getColoredName()
                                  << " est ajouté à votre deck.\n";
                        chosenCreatures.push_back(availableCreatures[i]);
                        availableCreatures.erase(availableCreatures.begin() + i);
                        nbCardsRemaining--;
                    }
                    break;
                }
            }
            if (!validInput)
                std::cout << "Réponse inconnue, veuillez réessayer : ";
        }
    }
    std::cout << "\nVotre deck est désormais complet.\n";
    std::cout << "Export du deck au format JSON ...\n";
    Deck d(chosenCreatures);
    d.exportToJson(filename);
    std::cout << "Le deck à bien été exporté !\n";
    std::cout << "Ciao.\n\n";
}

void DeckCreator::showBanner() {
    std::cout << "______          _      _____                _             \n"
                 "|  _  \\        | |    /  __ \\              | |            \n"
                 "| | | |___  ___| | __ | /  \\/_ __ ___  __ _| |_ ___  _ __ \n"
                 "| | | / _ \\/ __| |/ / | |   | '__/ _ \\/ _` | __/ _ \\| '__|\n"
                 "| |/ /  __/ (__|   <  | \\__/\\ | |  __/ (_| | || (_) | |   \n"
                 "|___/ \\___|\\___|_|\\_\\  \\____/_|  \\___|\\__,_|\\__\\___/|_|\n\n";
}