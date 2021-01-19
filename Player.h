#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Hand.h"

class Player{
    Hand hand;
    Hand discards;
    Hand legalPlays;
    int playerNum;
    int score;
    bool isHuman;
    public:
    // Initializes the player with the given hand and whether they are a human and their number
    Player(const Hand &hand, const bool &isHuman, const int &playerNum, const int &score);
    // Plays the given card
    void play(const Card &card, Hand &Clubs, Hand &Diamonds, Hand &Hearts, Hand &Spades);
    // Discards the given card
    void discard(const Card &card);
    // Updates legalPlays given the cards that are valid to play in hand
    void calculateLegalPlays(const Hand &Clubs, const Hand &Diamonds, const Hand &Hearts, const Hand &Spades);
    // Plays the first card from legalPlays
    Card computerMove();
    // Returns teh value of the isHuman field
    const bool &getIsHuman() const;
    // Returns the value of the score field
    const int &getScore() const;
    // Returns the value of the hand field
    const Hand &getHand() const;
    // Returns the value of the discards field
    const Hand &getDiscards() const;
    // Returns the value of the legalPlays field
    const Hand &getLegalPlays() const;
    // Replaces the current human player with a computer player, and resumes the game
    void ragequit();
};

#endif
