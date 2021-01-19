#ifndef __TEXT_H__
#define __TEXT_H__

#include "View.h"

class StraightsEngine;

class TextView : public View{
    StraightsEngine &se;
public:
    TextView(StraightsEngine &se);
    void updateViews(const std::string &error) override;
    void updateViews(int playerNum, const Hand &discards) override;
    void updateViews(int playerNum, int currScore, int totalScore) override;
    void updateViews(int playerNum, const std::string &action) override;
    void updateViews(int playerNum, const Card &card, const std::string &action) override;
    void updateViews(const Hand &Clubs, const Hand &Diamonds, const Hand &Hearts, const Hand &Spades, const Hand &hand, const Hand &legalPlays) override;
    void updateViews(const Deck &deck) override;
};

#endif
