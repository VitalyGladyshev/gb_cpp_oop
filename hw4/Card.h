//
// Created by Гладышев ВВ on 20.02.2022.
//

#ifndef GB_CPP_OOP_CARD_H
#define GB_CPP_OOP_CARD_H

#include<vector>
#include<string>
#include<ostream>

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
    string GetSuitName() const
    {
        return _suitNames[static_cast<int>(_suit)];
    }
    //Возвращаем значение карты
    Value GetValue()
    {
        return _value;
    }
    //Возвращаем название значения карты
    string GetValueName() const
    {
        return _valueNames[static_cast<int>(_value)];
    }
    //Возвращаем очки карты
    int GetValueScore() const
    {
        if (_shirtUp)
            return _valueScore[static_cast<int>(_value)];
        else
            return 0;
    }
    //Перегрузка оператора вывода
    friend ostream& operator<< (ostream& os, const Card& aCard)
    {
        if (aCard._shirtUp)
            os << "\t\tXX" << endl;
        else
            os << "\t\t" << aCard.GetValueName() << " " << aCard.GetSuitName() << " - " << aCard.GetValueScore()  << \
                " очков" << endl;
        return os;
    }
};

#endif //GB_CPP_OOP_CARD_H
