#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "Controller.h"

class Keyboard : public Controller{

public:
    std::string get_move() override;
    Card get_card() override;
    bool get_is_human() override;
};

#endif
