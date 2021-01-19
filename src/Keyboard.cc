#include "Keyboard.h"

#include <iostream>

std::string Keyboard::get_move(){
    // get input and parse
    // "Play AS"
    std::string input;
    std::cin >> input;
    return input;
}

Card Keyboard::get_card(){
    std::string input;
    std::cin >> input;
    int value = input[0];
    if (value == 'A')
        value = 1;
    else if (value == 'T')
        value = 10;
    else if (value == 'J')
        value = 11;
    else if (value == 'Q')
        value = 12;
    else if (value == 'K')
        value = 13;
    else
        value = input[0] - '0';
    Card card{input[1],value};
    return card;
}

bool Keyboard::get_is_human(){
    char input;
    std::cin >> input;
    if (input == 'h')
        return true;
    else
        return false;
}
