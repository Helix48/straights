#include "Card.h"

Card::Card(const char &suit, const int &value)
    : suit{suit},
      value{value} {}

const char &Card::getSuit() const{
    return suit;
}

const int &Card::getValue() const{
    return value;
}

void Card::print(std::ostream &out) const{
    switch (value)
    {
    case 1:
        out << "A";
        break;
    case 10:
        out << "T";
        break;
    case 11:
        out << "J";
        break;
    case 12:
        out << "Q";
        break;
    case 13:
        out << "K";
        break;
    default:
        out << value;
    }
    out << suit;
}
