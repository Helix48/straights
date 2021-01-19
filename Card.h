#ifndef __CARD_H__
#define __CARD_H__
#include <iostream>

class Card{
    char suit;
    int value;
    public:
    // Initializes the card with suits (C = clubs, D = diamonds, H = hearts, S = spades) and values (1-13)
    Card(const char &suit, const int &value);
    // Returns the value of the suit field
    const char &getSuit() const;
    // Returns the value of the value field
    const int &getValue() const;
    // Prints the Card
    void print(std::ostream &out) const;
};

#endif
