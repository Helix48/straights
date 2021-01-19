#include "Deck.h"

Deck::Deck()
    : deck{{'C',1},{'C',2},{'C',3},{'C',4},{'C',5},{'C',6},{'C',7},{'C',8},{'C',9},{'C',10},{'C',11},{'C',12},{'C',13},
           {'D',1},{'D',2},{'D',3},{'D',4},{'D',5},{'D',6},{'D',7},{'D',8},{'D',9},{'D',10},{'D',11},{'D',12},{'D',13},
           {'H',1},{'H',2},{'H',3},{'H',4},{'H',5},{'H',6},{'H',7},{'H',8},{'H',9},{'H',10},{'H',11},{'H',12},{'H',13},
           {'S',1},{'S',2},{'S',3},{'S',4},{'S',5},{'S',6},{'S',7},{'S',8},{'S',9},{'S',10},{'S',11},{'S',12},{'S',13}} {}

void Deck::shuffleDeck(const int &seed){
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

std::vector<Card> Deck::createHand(const int start, const int end) {
    int index = 0;
    std::vector<Card> hand;
    for (auto i : deck){
        if (index >= start)
            hand.push_back(i);
        if (index == end)
            break;
        index++;
    }
    return hand;
}

int Deck::startPlayer() {
    int index = 0;
    for (auto i : deck){
        if (i.getSuit() == 'S' && i.getValue() == 7)
            break;
        index++;
    }
    return index / 13; 
}

void Deck::print(std::ostream &out) const{
    int index = 1;
    for (auto i : deck){
        i.print(out);
        if (index % 13 == 0){
            out << std::endl;
        }
        else{
            out << " ";
        }
        index++;
    }    
}

/*
DeckIterator Deck::begin() const{
    return DeckIterator{*deck[0]};
}

DeckIterator Deck::end() const{
    return DeckIterator{*deck[51]};
}

DeckIterator::DeckIterator(Card *c) : c{c} {}

Card *DeckIterator::operator*() const{
    return c;
}

DeckIterator DeckIterator::operator++(){
    ++c;
    return *this;
}

bool DeckIterator::operator==(const DeckIterator &other) const{
    return c == other.c;
}

bool DeckIterator::operator!=(const DeckIterator &other) const{
    return c != other.c;
}
*/
