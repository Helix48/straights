#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <memory>
#include "Card.h"

class Move;

class Controller{
    virtual std::string get_move() = 0;
    virtual bool get_is_human() = 0;
    virtual Card get_card() = 0;
public:
    std::string getMove();
    Card getCard();
    bool getIsHuman();
    virtual ~Controller() = default;
};

#endif
