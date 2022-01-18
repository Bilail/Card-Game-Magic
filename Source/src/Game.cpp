//
// Created by bilai on 05/01/2022.
//

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <map>

#include "../header/Util.h"

#include "../header/Player.h"
#include "../header/Deck.h"
#include "../header/Game.h"
#include "../header/StrColor.h"


int Game::MAX_CARDS_IN_HAND = 7;

std::string centerString(std::string s, int size) {
    std::string str = "";
    int l = s.length();
    int pos = size / 2 - l / 2;
    for (int i = 0; i < pos; i++)
        str += " ";
    str += s;
    for (int i = 0; i < pos; i++)
        str += " ";
    return str;
}

Game::Game() : p1("", Deck()), p2("", Deck()) {
    round = 0;
}

void Game::playGame() {
    showBanner();
    initGame();
    std::cout << "\nBienvenue aux joueurs " << p1.getColoredName() << " et " << p2.getColoredName() << " !\n\n";
    randomDraw();
    for (int i = 0; i < MAX_CARDS_IN_HAND; i++) {
        p1.drawCard();
        p2.drawCard();
    }
    while(p1.getHp() > 0 && p2.getHp() > 0) {
        round++;
        std::cout << " ***---*** Début du tour n°" << round << " ***---*** " << std::endl;
        std::cout << " ***---*** C'est à " << playerTurn->getColoredName() << " de jouer ***---***\n\n";
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
        fightPhase();
        if (p1.getHp() <= 0 || p2.getHp() <= 0)
            break;
        // PHASE SECONDAIRE
        // FIN DE TOUR ET CHANGEMENT DE JOUEUR
        std::cout << std::endl << std::endl;
    }
    if (p1.getHp() <= 0 && p2.getHp() <= 0) {
        std::cout << "\nCette partie ce termine avec une égalité." << std::endl;
    }
    else {
        std::cout << "\nLe gagnant de cette partie est :\n\n";
        if (p1.getHp() <= 0)
            std::cout << StrColor::yellow(centerString(p2.getName(),37)) << std::endl;
        else if (p2.getHp() <= 0)
            std::cout << StrColor::yellow(centerString(p1.getName(),37)) << std::endl;
        std::cout << StrColor::yellow("             ___________\n"
                                      "            '._==_==_=_.'\n"
                                      "            .-\\:      /-.\n"
                                      "           | (|:.     |) |\n"
                                      "            '-|:.     |-'\n"
                                      "              \\::.    /\n"
                                      "               '::. .'\n"
                                      "                 ) (\n"
                                      "               _.' '._\n"
                                      "              `\"\"\"\"\"\"\"`\n");
    }
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
    std::cout << "C'est à " << playerTurn->getColoredName() << " de commencer.\n\n";
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
                std::getline(std::cin, cardToPlay);
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
    return (playerTurn == &p1) ? &p2 : &p1;
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
            std::cout << "Vous pouvez attaquer avec les cartes suivantes :\n";
            Card::print(attackCards);
            std::cout << std::endl;
            std::cout << "Avec qui souhaitez-vous attaquer ? (tapez \"aucune\" pour ne pas attaquer)\n";
            bool validInput = false;
            while (!validInput) {
                std::string cardToPlay = "";
                std::getline(std::cin, cardToPlay);
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
        std::map<Card*, std::vector<Card*>> attackDefenseCards;
        for (Card * c : chosenCardsToAttack)
            attackDefenseCards[c] = std::vector<Card*>();
        std::cout << "\nC'est à " << opponent->getColoredName() << " de prendre la main." << std::endl;
        std::cout << "\nVotre adversaire vous attaque avec les cartes suivante :\n";
        Card::print(chosenCardsToAttack);
        std::cout << "\nVoulez-vous vous défendre ? (y/n) ";
        std::string input;
        std::cin >> input;
        while (input != "y" && input != "n") {
            std::cout << "\nRéponse inconnue, veuillez réessayer : ";
            std::cin >> input;
        }
        if (input == "y") {
            std::vector<Card*> defenseCards = opponent->getDefenseCards();
            if (defenseCards.size() > 0) {
                for (int i = 0; i < chosenCardsToAttack.size(); i++) {
                    std::cout << "Voici l'ensemble de vos créatures qui peuvent défendre :\n";
                    Card::print(defenseCards);
                    std::cout << "Avec quelle(s) carte(s) souhaitez-vous contrer la carte" << chosenCardsToAttack.at(i)->getColoredName() << " (tapez \"aucune\" pour ne pas défendre) :\n";
                    bool validInput = false;
                    do {
                        std::getline(std::cin, input);
                        if (input != "aucune") {
                            for (Card* c : defenseCards) {
                                if (c->getName() == input) {
                                    validInput = true;
                                    attackDefenseCards[chosenCardsToAttack.at(i)].push_back(c);
                                    std::cout << "\nVous avez décidé de défendre avec la carte " << c->getColoredName() << " pas contrer l'attaque.\n";
                                }
                            }
                        }
                        else {
                            validInput = true;
                            std::cout << "\nVous avez décidé de ne pas contrer l'attaque.\n";
                        }
                        if (!validInput)
                            std::cout << "\nRéponse inconnue, veuillez réessayer : ";
                    } while (!validInput);
                }
            }
            else {
                std::cout << "Vous n'avez aucune créature d'engagée donc vous ne pouvez pas vous défendre.\n";
            }
        }
        std::cout << "\nC'est à " << playerTurn->getColoredName() << " de reprendre la main.\n\n";
        for(auto it : attackDefenseCards) {
            CreatureCard* offensive_c = dynamic_cast<CreatureCard*>(it.first);
            if (it.second.size() > 0) {
                std::cout << "Votre carte " << offensive_c->getColoredName()  << " se fait contrer par les cartes suivantes :\n";
                Card::print(it.second);
                if (it.second.size() > 1) {
                    // TODO proposer au joueur de choisir l'ordre d'attaque
                }
                int remainingAtkPower = offensive_c->getAttackPower();
                for (Card* c : it.second) {
                    if (offensive_c->getHp() > 0) {
                        CreatureCard* defensive_c = dynamic_cast<CreatureCard*>(c);
                        if (offensive_c && defensive_c) {
                            std::cout << "La carte " << offensive_c->getColoredName() << " attaque la carte " << defensive_c->getColoredName() << "\n";
                            int defenseHp = defensive_c->getHp();
                            offensive_c->setHp(offensive_c->getHp() - defensive_c->getAttackPower());
                            defensive_c->setHp(defensive_c->getHp() - remainingAtkPower);
                            remainingAtkPower -= defenseHp;
                            if (remainingAtkPower < 0)
                                remainingAtkPower = 0;
                            if (defensive_c->getHp() <= 0) {
                                std::cout << "La carte " << defensive_c->getColoredName() << " meurt.\n";
                                opponent->discardCard(defensive_c);
                            }
                            if (offensive_c->getHp() <= 0) {
                                std::cout << "La carte " << offensive_c->getColoredName() << " meurt.\n";
                                playerTurn->discardCard(offensive_c);
                            }
                        }
                    }
                }
            }
            else {
                std::cout << "Votre carte " << offensive_c->getColoredName()  << " peut directement attaquer l'adversaire :\n";
                std::cout << "L'adversaire subit " << StrColor::red(std::to_string(offensive_c->getAttackPower()) + " point(s) de dégâts") << "\n";
                opponent->setHp(opponent->getHp() - offensive_c->getAttackPower());
                if (opponent->getHp() <= 0) {
                    std::cout << "L'adversaire " << StrColor::red("décède") << " de ses blessures.\n";
                    return;
                }
                std::cout << "L'adversaire n'a plus que " << StrColor::green(std::to_string(opponent->getHp()) + " point(s) de vie") << "\n";

            }
        }
    }
    std::cout << "\n### ### ### ### ### ### ### ### ### ###\n";
    std::cout << "###### FIN DE LA PHASE DE COMBAT ######\n";
    std::cout << "### ### ### ### ### ### ### ### ### ###\n\n";
}
