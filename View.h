#ifndef __VIEW_H__
#define __VIEW_H__
#include <string>

class Card;
class Hand;
class Deck;

class View{
public:
    virtual ~View() = default;
    virtual void updateViews(const std::string &error) = 0;
    virtual void updateViews(int playerNum, const Hand &discards) = 0;
    virtual void updateViews(int playerNum, int currScore, int totalScore) = 0;
    virtual void updateViews(int playerNum, const std::string &action) = 0;
    virtual void updateViews(int playerNum, const Card &card, const std::string &action) = 0;
    virtual void updateViews(const Hand &Clubs, const Hand &Diamonds, const Hand &Hearts, const Hand &Spades, const Hand &hand, const Hand &legalPlays) = 0;
    virtual void updateViews(const Deck &deck) = 0;
};

#endif
