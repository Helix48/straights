#ifndef __DECK_H__
#define __DECK_H__
#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>

class Deck{
    std::vector<Card> deck;
    public:
    // Initializes the deck with the standard 52 playing cards in order
    Deck();
    // Shuffles the deck using the given seed
    void shuffleDeck(const int &seed);
    // Returns a vector of cards from the given range
    std::vector<Card> createHand(const int start, const int end);
    // Returns an int that represents the starting player
    int startPlayer();
    // Prints the deck
    void print(std::ostream &out) const;
    // DeckIterator begin() const;
    // DeckIterator end() const;
    // friend class DeckIterator;
};

/*
class DeckIterator{
    Card *c;
    explicit DeckIterator(Card *c)
    public:
    Card *operator*() const;
    DeckIterator operator++();
    bool operator==(const DeckIterator &other) const;
    bool operator!=(const DeckIterator &other) const;
    friend class Deck;
}*/

#endif
