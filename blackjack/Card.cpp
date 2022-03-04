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
    _shirtUp = !_shirtUp;
    return _shirtUp;
}

//Возвращаем масть карты
Card::Suit Card::GetSuit()
{
    return _suit;
}

//Возвращаем название масти карты
string Card::GetSuitName() const
{
    return _suitNames[static_cast<int>(_suit)];
}

//Возвращаем значение карты
Card::Value Card::GetValue()
{
    return _value;
}

//Возвращаем название значения карты
string Card::GetValueName() const
{
    return _valueNames[static_cast<int>(_value)];
}

//Возвращаем очки карты
int Card::GetValueScore() const
{
    return _valueScore[static_cast<int>(_value)];
}

//Перегрузка оператора вывода
ostream& operator<< (ostream& os, const Card& aCard)
{
    if (aCard._shirtUp)
        os << "\t\tXX" << endl;
    else
        os << "\t\t" << aCard.GetValueName() << " " << aCard.GetSuitName() << " - " << aCard.GetValueScore()  << \
                " очков" << endl;
    return os;
}
