//
// Created by Гладышев ВВ on 20.02.2022.
//

#include "Card.h"

//Конструктор
Card::Card(Suit suit, Value value, bool shirtUp) :
    _suit(suit),
    _value(value),
    _shirtUp(shirtUp)
{
    for (auto el : {"треф"s, "пик"s, "черв"s, "бубён"s})
        _suitNames.push_back(el);
    for (auto el : {"туз"s, "двойка"s, "тройка"s, "четвёрка"s, "пятёрка"s, "шестёрка"s, "семёрка"s,
                    "восьмёрка"s, "девятка"s, "десятка"s, "валет"s, "дама"s, "король"s})
        _valueNames.push_back(el);
    for (auto el : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 })
        _valueScore.push_back(el);
}

//Открываем карту
bool Card::Flip()
{
    if (_shirtUp)
        _shirtUp = false;
    else
        _shirtUp = true;
    return _shirtUp;
}