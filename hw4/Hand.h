//
// Created by Гладышев ВВ on 20.02.2022.
//

#ifndef GB_CPP_OOP_HAND_H
#define GB_CPP_OOP_HAND_H

#include "Card.h"

//BlackJack Класс - рука
class Hand {
private:
    vector<Card*> _cards;   //Карты на руке

public:
    //Конструктор
    Hand(initializer_list<Card*> cards);

    //Добавляет карту в руку.
    void Add(Card* pCard);
    //Очищает руку от карт.
    void Clear();
    //Возвращает сумму очков карт руки
    int GetTotal() const;
    //Распечатать карты на руке
    void PrintHand();
    //Перевернуть карту
    bool FlipCardNumber(int cardNumber);
};


#endif //GB_CPP_OOP_HAND_H
