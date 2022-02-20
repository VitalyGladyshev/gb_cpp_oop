//
// Created by Гладышев ВВ on 20.02.2022.
//

#include <iostream>

#include "Hand.h"

//Конструктор
Hand::Hand(initializer_list<Card*> cards) : _cards(cards) {}

//Добавляет карту в руку.
void Hand::Add(Card* pCard)
{
    _cards.push_back(pCard);
}

//Очищает руку от карт.
void Hand::Clear()
{
    _cards.clear();
}

//Возвращает сумму очков карт руки
int Hand::GetTotal()
{
    int score = 0;
    for (auto card : _cards)
        score += card->GetValueScore();
    return score;
}

//Распечатать карты на руке
void Hand::PrintHand()
{
    int score = 0;
    for (auto card : _cards)
        cout << "\t\t" << card->GetValuetName() << " " << card->GetSuitName() << " - " << card->GetValueScore()  << \
            " очков" << endl;
}
