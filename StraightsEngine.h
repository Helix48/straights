#ifndef __STRAIGHTS_ENGINE_H__
#define __STRAIGHTS_ENGINE_H__

#include "Model.h"
#include "Player.h"
#include "Deck.h" //?

class StraightsEngine : public Model{
    int currPlayer;
    int seed;
    std::vector<int> scores;
    Hand Clubs;
    Hand Diamonds;
    Hand Hearts;
    Hand Spades;
    Deck deck;
    std::vector<Player> players;
public:
    StraightsEngine(int seed);
    //std::vector<Player> &getPlayers();
    void getPlayers();
    //void resetBoard();
    void start();
    int getSeed() const;
};

#endif
