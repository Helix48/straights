#include "Controller.h"

std::string Controller::getMove(){
    return get_move();
}

Card Controller::getCard(){
    return get_card();
}

bool Controller::getIsHuman(){
    return get_is_human();
}
