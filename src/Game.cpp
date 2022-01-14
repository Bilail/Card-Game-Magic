//
// Created by bilai on 05/01/2022.
//

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
#include "header/Util.h"

#include "header/Player.h"
#include "header/Deck.h"
#include "header/Game.h"
#include "header/StrColor.h"


Game::Game() : p1("", Deck()), p2("", Deck()) {
    round = 0;
}


void Game::playGame() {
    showBanner();
    initGame();
    std::cout << "\nBienvenue aux joueurs " << p1.getName() << " et " << p2.getName() << " !\n\n";
    randomDraw();
    while(p1.getHp() > 0 && p2.getHp() > 0) {
        round++;
        std::cout << " ***---*** Début du tour n°" << round << " ***---*** " << std::endl;
        std::cout << " ***---*** C'est à " << playerTurn->getName() << " de jouer ***---***\n\n";
        // PHASE DE PIOCHE
        if (round != 1) {
            if (!playerTurn->drawCard()) { // Le joueur perd s'il ne peut plus piocher
                playerTurn->setHp(0);
                continue;
            }
        }
        // PHASE DE DESANGAGEMENT
        playerTurn->disengageCards();

        // PHASE PRINCIPALE
        mainPhase();
        // PHASE DE COMBAT
        // PHASE SECONDAIRE
        // FIN DE TOUR ET CHANGEMENT DE JOUEUR
        std::cout << std::endl << std::endl;
    }
    if (p1.getHp() <= 0 && p2.getHp() <= 0)
        std::cout << "Cette partie ce termine avec une égalité." << std::endl;
    else if (p1.getHp() <= 0)
        std::cout << "Le gagnant de cette partie est " + p2.getName() << std::endl;
    else if (p2.getHp() <= 0)
        std::cout << "Le gagnant de cette partie est " + p1.getName() << std::endl;
}


void Game::showBanner() {
    std::cout
            << "  _   _  ____ _______   __  __          _____ _____ _____ \n"
            << " | \\ | |/ __ \\__   __| |  \\/  |   /\\   / ____|_   _/ ____|\n"
            << " |  \\| | |  | | | |    | \\  / |  /  \\ | |  __  | || |     \n"
            << " | . ` | |  | | | |    | |\\/| | / /\\ \\| | |_ | | || |     \n"
            << " | |\\  | |__| | | |    | |  | |/ ____ \\ |__| |_| || |____ \n"
            << " |_| \\_|\\____/  |_|    |_|  |_/_/    \\_\\_____|_____\\_____|\n\n";
}

void Game::initGame() {
    Deck d;
    std::string nameP1("P1");
    std::string nameP2("P2");
    std::cout << "Quel est le nom du premier joueur ?\n";
    std::cin >> nameP1;
    std::cout << "\nQuel est le nom du deuxieme joueur ?\n";
    std::cin >> nameP2;
    d.generateRandomDeck();
    p1 = Player(nameP1,d);
    p1.setPrintColor("cyan");
    d.generateRandomDeck();
    p2 = Player(nameP2, d);
    p2.setPrintColor("magenta");
}

void Game::randomDraw() {
    std::cout << "### Tirage au sort du joueur qui commence ###\n\n";
    srand (time(NULL));
    bool randBool = std::rand()%2 == 1;
    if (randBool)
        playerTurn = &p1;
    else
        playerTurn = &p2;
    if (false) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Roulement de tambours" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << " 5 " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << " 4 " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << " 3 " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << " 2 " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << " 1 " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << " BONNE ANN... ah non enfaite. " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "\n\n";
    }
    std::cout << "C'est à " << playerTurn->getName() << " de commencer.\n\n";
}

void Game::mainPhase() {
    bool stopMainPhase = false;
    bool firstMainPhase = true;
    bool hasPlayedLandCard = false;
    while (!stopMainPhase) {
        std::vector <Card*> playableCards = playerTurn->getPlayableCards();
        if (hasPlayedLandCard) {
            for (int i = 0; i < playableCards.size(); i++) {
                if (dynamic_cast<const LandCard*>(playableCards.at(i))) {
                    playableCards.erase(playableCards.begin() + i);
                    i = -1;
                }
            }
        }
        if (playableCards.size() > 0) {
            std::cout << "Vous pouvez poser les cartes suivantes :\n";
            Card::print(playableCards);
            std::cout << std::endl;
            std::cout
                    << "Indiquer le nom de la carte que vous souhaitez jouer (tapez \"aucune\" pour ne rien jouer) :\n";
            bool validInput = false;
            while (!validInput) {
                std::string cardToPlay = "";
                std::cin >> cardToPlay;
                if (cardToPlay != "aucune") {
                    std::string cardColor = "white";
                    for (Card *c: playableCards) {
                        if (c->getName() == cardToPlay) {
                            validInput = true;
                            if (dynamic_cast<const LandCard*>(c))
                                hasPlayedLandCard =  true;
                            cardColor = c->getColor();
                            playerTurn->playCard(c);
                            break;
                        }
                    }
                    if (validInput) {
                        std::cout << "\nVous venez de jouer la carte " << StrColor::print(cardToPlay, cardColor) << std::endl;
                    } else {
                        std::cout << "Le nom de la carte est inconnu, veuillez réessayer :\n";
                    }
                }
                else {
                    std::cout << "Vous avez décidé de ne jouer aucune carte.\n";
                    validInput = true;
                    stopMainPhase = true;
                }
            }
        } else {
            if (firstMainPhase)
                std::cout << "Vous n'avez aucune carte jouable.\n";
            else
                std::cout << "Vous ne pouvez plus jouer de cartes pour ce tour.\n";
            stopMainPhase = true;
        }
        firstMainPhase = false;
    }
}

Player* Game::getOpponent() {
    return (playerTurn == &p1) ? &p1 : &p2;
}

void Game::fightPhase(){
    std::string cardToAttack  = "";
    std::vector<Card*> chosenCardsToAttack;
    bool stopAttack = false;
    while (!stopAttack)
    {
        std::vector<Card*> attackCards = playerTurn->getAttackCards();
        if (attackCards.size() == 0) {
            std::cout << "Vous ne pouvez pas attaquer.\n";
            stopAttack = true;
            break;
        }
        else {
            Card::print(attackCards);
            std::cout << "Vous pouvez attaqué avec les cartes suivantes :\n";
            std::cout << std::endl;
            std::cout << "Avec qui souhaitez-vous attaquer ? \n";

            bool validInput = false;
            while (!validInput) {
                std::string cardToPlay = "";
                std::cin >> cardToPlay;
                if (cardToPlay != "aucune") {
                    std::string cardColor = "white";
                    for (Card *c: attackCards) {
                        if (c->getName() == cardToPlay) {
                            validInput = true;
                            cardColor = c->getColor();
                            c->engage();
                            chosenCardsToAttack.push_back(c);
                            break;
                        }
                    }
                    if (validInput) {
                        std::cout << "\nVous venez d'enagager la carte " << StrColor::print(cardToPlay, cardColor)
                                  << std::endl;
                    } else {
                        std::cout << "Le nom de la carte est inconnu, veuillez réessayer :\n";
                    }
                } else {
                    std::cout << "Vous avez décidé d'engager aucune carte.\n";
                    validInput = true;
                    stopAttack = true;
                }
            }
        }
    }
    // Phase de défense
    if (chosenCardsToAttack.size() > 0) {
        Player* opponent = getOpponent();
        std::cout << "\nC'est à " << opponent->getName() << " de prendre la main." << std::endl;
        std::cout << "Voulez-vous vous défendre ? (y/n) ";
        std::string input;
        std::cin >> input;
        while (input != "y" || input != "n") {
            std::cout << "\nRéponse inconnue, veuillez réessayer : ";
            std::cin >> input;
        }
        if (input == "y") {
            std::vector<Card*> defenseCards = opponent->getDefenseCards();
            for (int i = 0; i < chosenCardsToAttack.size(); i++) {

            }
        }
        std::cout << "\nC'est à " << playerTurn->getName() << " de reprendre la main." << std::endl;
    }

}