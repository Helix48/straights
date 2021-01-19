#include "TextView.h"
#include <iostream>

#include "StraightsEngine.h"
#include "Card.h"
#include "Deck.h"

TextView::TextView(StraightsEngine &se): se{se} {}

// void TextView::updateViews(){
//     // update visuals
//     auto &players = se.getPlayers();
// }

void TextView::updateViews(const std::string &error){
    if (error == "play")
        std::cout << "This is not a legal play." << std::endl;
    else if (error == "discard")
        std::cout << "You have a legal play. You may not discard." << std::endl;
}

void TextView::updateViews(int playerNum, const Hand &discards){
    std::cout << "Player" << playerNum << "\'s discards:";
    discards.print(std::cout, "");
}

void TextView::updateViews(int playerNum, int currScore, int totalScore){
    std::cout << "Player" << playerNum << "\'s score: " << totalScore << " + " << currScore << " = " << currScore + totalScore << std::endl;
}

void TextView::updateViews(int playerNum, const std::string &action){
    if (action == "IsHuman")
        std::cout << "Is Player" << playerNum << " a human (h) or a computer (c)?" << std::endl;
    else if (action == "Ragequit")
        std::cout << "Player" << playerNum << " ragequits. A computer will now take over." << std::endl;
    else if (action == "Win")
        std::cout << "Player" << playerNum << " wins!" << std::endl;
    else if (action == "Round")
        std::cout << "A new round begins. It's Player" << playerNum << "\'s turn to play." << std::endl;
}

void TextView::updateViews(int playerNum, const Card &card, const std::string &action){
    std::cout << "Player" << playerNum << " " << action << " ";
    card.print(std::cout);
    std::cout << "." << std::endl;
}

void TextView::updateViews(const Hand &Clubs, const Hand &Diamonds, const Hand &Hearts, const Hand &Spades, const Hand &hand, const Hand &legalPlays){
    std::cout << "Cards on the table:" << std::endl;
    Clubs.printNums(std::cout, "Clubs");
    Diamonds.printNums(std::cout, "Diamonds");
    Hearts.printNums(std::cout, "Hearts");
    Spades.printNums(std::cout, "Spades");
    hand.print(std::cout, "Your hand:");
    legalPlays.print(std::cout, "Legal plays:");
}

void TextView::updateViews(const Deck &deck){
    deck.print(std::cout);
}
