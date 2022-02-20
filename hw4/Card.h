//
// Created by Гладышев ВВ on 20.02.2022.
//

#ifndef GB_CPP_OOP_CARD_H
#define GB_CPP_OOP_CARD_H

#include<vector>
#include<string>

using namespace std;

//BlackJack Класс - игральная карта
class Card {
public:
    enum class Suit                 //Перечисление: масти карты
    {
        Clubs = 0,
        Spades = 1,
        Hearts = 2,
        Diamonds = 3
    };

    enum class Value                //Перечисление: значение карты
    {
        Ace = 0,
        Two = 1,
        Three = 2,
        Four = 3,
        Five = 4,
        Six = 5,
        Seven = 6,
        Eight = 7,
        Nine = 8,
        Ten = 9,
        Jack = 10,
        Queen = 11,
        King = 12
    };

private:
    Suit _suit;                     //Масть карты
    vector<string> _suitNames;      //Название мастей карты

    Value _value;                   //Значение карты
    vector<string> _valueNames;     //Название карты
    vector<int> _valueScore;        //Очки карты

    bool _shirtUp;                  //Положение карты: true - рубашкой вверх

public:
    //Конструктор
    Card(Suit suit, Value value, bool shirtUp = true);

    //Открываем карту
    bool Flip();
    //Возвращаем масть карты
    Suit GetSuit()
    {
        return _suit;
    }
    //Возвращаем название масти карты
    string GetSuitName()
    {
        return _suitNames[static_cast<int>(_suit)];
    }
    //Возвращаем значеие карты
    Value GetValue()
    {
        return _value;
    }
    //Возвращаем название значения карты
    string GetValuetName()
    {
        return _valueNames[static_cast<int>(_value)];
    }
    //Возвращаем очки карты
    int GetValueScore()
    {
        return _valueScore[static_cast<int>(_value)];
    }
};

#endif //GB_CPP_OOP_CARD_H
