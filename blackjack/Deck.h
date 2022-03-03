//
// Created by Гладышев ВВ on 03.03.2022.
//

#ifndef GB_CPP_OOP_DECK_H
#define GB_CPP_OOP_DECK_H

#include "Card.h"
#include "Hand.h"

//Класс колода
class Deck
{
public:
    //Конструктор
    Deck();
    //Деструктор
    virtual ~Deck();

    //Перетасовать карты
    void Shuffle();
    //Выдать одну карту
    Card* Deal(); //Hand& Hand);

private:
    vector<Card*> _deck;
};

#endif //GB_CPP_OOP_DECK_H
