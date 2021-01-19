#ifndef __MODEL_H__
#define __MODE_H__

#include <vector>
#include <memory>
#include "Controller.h"
#include "View.h"

//class View;
//class Controller;
class Move;
class Deck;

class Model{
    std::vector<std::unique_ptr<View>> views;
    std::unique_ptr<Controller> control;
protected:
    void addView(std::unique_ptr<View> v);
    void addController(std::unique_ptr<Controller> c);
    std::string getMove();
    bool getIsHuman();
    Card getCard();
public:
    virtual ~Model() = default;
    //void updateViews();
    void updateViews(const std::string &error);
    void updateViews(int playerNum, const Hand &discards);
    void updateViews(int playerNum, int currScore, int totalScore);
    void updateViews(int playerNum, const std::string &action);
    void updateViews(int playerNum, const Card &card, const std::string &action);
    void updateViews(const Hand &Clubs, const Hand &Diamonds, const Hand &Hearts, const Hand &Spades, const Hand &hand, const Hand &legalPlays);
    void updateViews(const Deck &deck);
    //void updateViews(Player player, Card playedCard);
};

#endif
