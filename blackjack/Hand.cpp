//
// Created by Гладышев ВВ on 20.02.2022.
//

#include <iostream>

#include "Card.h"
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
int Hand::GetTotal() const
{
    //Карта рубашкой вверх
    if (!_cards[0]->GetValueScore())
         return 0;

    int score = 0;
    bool containsAce = false;   // определяет, держит ли рука туз

    for (auto card : _cards)
    {
        score += card->GetValueScore();
        if (card->GetValue() == Card::Value::Ace)
        {
            containsAce = true;
        }
    }

    // если рука держит туз и сумма довольно маленькая, туз дает 11 очков
    if (containsAce && score <= 11)
    {
        // добавляем только 10 очков, поскольку мы уже добавили за каждый туз по одному очку
        score += 10;
    }

    return score;
}

//Распечатать карты на руке
void Hand::PrintHand()
{
    int score = 0;
    for (auto card : _cards)
        cout << "\t\t" << card->GetValueName() << " " << card->GetSuitName() << " - " << card->GetValueScore()  << \
            " очков" << endl;
}

//Распечатать карты на руке в поток
void Hand::PrintHand(ostream& os) const
{
    int score = 0;
    for (auto card : _cards)
        os << "\t\t" << card->GetValueName() << " " << card->GetSuitName() << " - " << card->GetValueScore()  << \
            " очков" << endl;
}

//Перевернуть карту
bool Hand::FlipCardNumber(int cardNumber)
{
    if (cardNumber < _cards.size())
    {
        _cards[cardNumber]->Flip();
        return true;
    }
    else
        return false;
}
