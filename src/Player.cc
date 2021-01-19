#include "Player.h"

Player::Player(const Hand &hand, const bool &isHuman, const int &playerNum, const int &score)
    : hand{hand},
      discards{{}},
      legalPlays{{}},
      score{score},
      playerNum{playerNum},
      isHuman{isHuman} {}

void Player::play(const Card &card, Hand &Clubs, Hand &Diamonds, Hand &Hearts, Hand &Spades){
    hand.removeCard(card);
    if (card.getSuit() == 'C') {
        if (card.getValue() == 7)
            Clubs.addCard(card);
        else if (card.getValue() == Clubs.getBack().getValue() + 1)
            Clubs.addCard(card);
        else
            Clubs.addCardFront(card);
    }
    else if (card.getSuit() == 'D') {
        if (card.getValue() == 7)
            Diamonds.addCard(card);
        else if (card.getValue() == Diamonds.getBack().getValue() + 1)
            Diamonds.addCard(card);
        else
            Diamonds.addCardFront(card);
    }
    else if (card.getSuit() == 'H') {
        if (card.getValue() == 7)
            Hearts.addCard(card);
        else if (card.getValue() == Hearts.getBack().getValue() + 1)
            Hearts.addCard(card);
        else
            Hearts.addCardFront(card);
    }
    else if (card.getSuit() == 'S') {
        //std::cout << "hi " << card.getValue() << std::endl;
        if (card.getValue() == 7)
            Spades.addCard(card);
        else if (card.getValue() == Spades.getBack().getValue() + 1)
            Spades.addCard(card);
        else
            Spades.addCardFront(card);
    }
}

void Player::discard(const Card &card){
    hand.removeCard(card);
    discards.addCard(card);
}

void Player::calculateLegalPlays(const Hand &Clubs, const Hand &Diamonds, const Hand &Hearts, const Hand &Spades){
    legalPlays.emptyHand();
    if (Clubs.getSize() == 0 && Diamonds.getSize() == 0 && Hearts.getSize() == 0 && Spades.getSize() == 0) {
        legalPlays.addCard(Card{'S',7});
    } 
    else {
        if (Clubs.getSize() != 0) {
            if (hand.isCard(Card{'C',Clubs.getCard(0).getValue() - 1}))
                legalPlays.addCard(Card{'C',Clubs.getCard(0).getValue() - 1});
            if (hand.isCard(Card{'C',Clubs.getBack().getValue() + 1}))
                legalPlays.addCard(Card{'C',Clubs.getBack().getValue() + 1});
        }
        else if (hand.isCard(Card{'C',7}))
            legalPlays.addCard(Card{'C',7});
        if (Diamonds.getSize() != 0) {
            if (hand.isCard(Card{'D',Diamonds.getCard(0).getValue() - 1}))
                legalPlays.addCard(Card{'D',Diamonds.getCard(0).getValue() - 1});
            if (hand.isCard(Card{'D',Diamonds.getBack().getValue() + 1}))
                legalPlays.addCard(Card{'D',Diamonds.getBack().getValue() + 1});
        }
        else if (hand.isCard(Card{'D',7}))
            legalPlays.addCard(Card{'D',7});
        if (Hearts.getSize() != 0) {
            if (hand.isCard(Card{'H',Hearts.getCard(0).getValue() - 1}))
                legalPlays.addCard(Card{'H',Hearts.getCard(0).getValue() - 1});
            if (hand.isCard(Card{'H',Hearts.getBack().getValue() + 1}))
                legalPlays.addCard(Card{'H',Hearts.getBack().getValue() + 1});
        }
        else if (hand.isCard(Card{'H',7}))
            legalPlays.addCard(Card{'H',7});
        if (Spades.getSize() != 0) {
            if (hand.isCard(Card{'S',Spades.getCard(0).getValue() - 1}))
                legalPlays.addCard(Card{'S',Spades.getCard(0).getValue() - 1});
            if (hand.isCard(Card{'S',Spades.getBack().getValue() + 1}))
                legalPlays.addCard(Card{'S',Spades.getBack().getValue() + 1});
        }
    }
}

Card Player::computerMove(){
    if (legalPlays.getSize() > 0){
        //hand.removeCard(legalPlays.getCard(0));
        return legalPlays.getCard(0);
    }
    else{
        //discard(hand.getCard(0));
        return hand.getCard(0);
    }
}

const bool &Player::getIsHuman() const{
    return isHuman;
}

const int &Player::getScore() const{
    return score;
}

const Hand &Player::getHand() const{
    return hand;
}

const Hand &Player::getDiscards() const{
    return discards;
}

const Hand &Player::getLegalPlays() const{
    return legalPlays;
}

void Player::ragequit(){
    isHuman = false;
}
