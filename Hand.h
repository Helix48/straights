#ifndef __HAND_H__
#define __HAND_H__
#include "Card.h"
#include <vector>

class Hand{
    std::vector<Card> hand;
    public:

    // Card &operator[](size_t i);
    // const Card &operator[](size_t i) const;

    // Initializes the hand with the given vector of cards
    Hand(std::vector<Card> hand);
    // Adds the given card to the (back of) hand
    void addCard(Card card);
    // Adds the given card to the front of the hand
    void addCardFront(Card card);
    // Removes the given card from the hand
    void removeCard(Card card);
    // Empties the hand of all of the cards
    void emptyHand();
    // Returns the size of the hand
    int getSize() const;
    // Returns the back card of the hand
    Card getBack() const;
    // Returns the card in the hand given by the slot
    Card getCard(int slot) const;
    // Determines whether the given card is in the hand
    bool isCard(Card card) const;
    // Prints the hand
    void print(std::ostream &out, const std::string message) const;
    // Prints the hand, omitting the suits of the cards
    void printNums(std::ostream &out, const std::string suit) const;
};

#endif
