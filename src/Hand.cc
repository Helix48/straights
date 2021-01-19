#include "Hand.h"

Hand::Hand(std::vector<Card> hand)
    : hand{hand} {}

void Hand::addCard(Card card){
    hand.push_back(card);
}

void Hand::addCardFront(Card card){
    hand.insert(hand.begin(), card);
}

void Hand::removeCard(Card card){
    int index = 0;
    for (auto i : hand){
        if (i.getSuit() == card.getSuit() && i.getValue() == card.getValue())
            break;
        index++;
    }
    hand.erase(hand.begin() + index);
}

void Hand::emptyHand(){
    hand.clear();
}

int Hand::getSize()const{
    return hand.size();
}

Card Hand::getBack()const{
    return hand.back();
}

Card Hand::getCard(int slot) const{
    return hand[slot];
}

bool Hand::isCard(Card card) const{
    for (auto i : hand){
        if (card.getSuit() == i.getSuit() && card.getValue() == i.getValue()) {
            return true;
        }
    }
    return false;
}

void Hand::print(std::ostream &out, const std::string message) const{
    out << message;
    for (auto i : hand){
        out << " ";
        i.print(out);
    }
    out << std::endl;
}

void Hand::printNums(std::ostream &out, const std::string suit) const{
    out << suit << ":";
    for (auto i : hand){
        int value = i.getValue();
        if (value == 1)
            out << " A";
        else if (value == 10)
            out << " T";
        else if (value == 11)
            out << " J";
        else if (value == 12)
            out << " Q";
        else if (value == 13)
            out << " K";
        else
            out << " " << i.getValue();
    }
    out << std::endl;
}
