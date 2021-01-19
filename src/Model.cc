#include "Model.h"
#include "Hand.h"

void Model::updateViews(const std::string &error){
    for(auto &view : views){
        view->updateViews(error);
    }
}

void Model::updateViews(int playerNum, const Hand &discards){
    for(auto &view : views){
        view->updateViews(playerNum, discards);
    }
}

void Model::updateViews(int playerNum, int currScore, int totalScore){
    for(auto &view : views){
        view->updateViews(playerNum, currScore, totalScore);
    }
}

void Model::updateViews(int playerNum, const std::string &action){
    for(auto &view : views){
        view->updateViews(playerNum, action);
    }
}

void Model::updateViews(int playerNum, const Card &card, const std::string &action){
    for(auto &view : views){
        view->updateViews(playerNum, card, action);
    }
}

void Model::updateViews(const Hand &Clubs, const Hand &Diamonds, const Hand &Hearts, const Hand &Spades, const Hand &hand, const Hand &legalPlays){
    for(auto &view : views){
        view->updateViews(Clubs, Hearts, Diamonds, Spades, hand, legalPlays);
    }
}

void Model::updateViews(const Deck &deck){
    for(auto &view : views){
        view->updateViews(deck);
    }
}

/*
void Model::updateViews(other){
    for(auto &view : views){
        view->updateViews(other);
    }
}
*/

void Model::addView(std::unique_ptr<View> v){
    views.emplace_back(std::move(v));
}

void Model::addController(std::unique_ptr<Controller> c){
    control = std::move(c);
}

std::string Model::getMove(){
    return control->getMove();
}

bool Model::getIsHuman(){
    return control->getIsHuman();
}

Card Model::getCard(){
    return control->getCard();
}
