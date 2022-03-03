//
// Created by Гладышев ВВ on 03.03.2022.
//

#include <algorithm>

#include "Deck.h"

//Конструктор
Deck::Deck()
{
    for(int suit = static_cast<int>(Card::Suit::Clubs); suit <= static_cast<int>(Card::Suit:: Diamonds); suit++)
        for(int value = static_cast<int>(Card::Value::Ace); value <= static_cast<int>(Card::Value::King); value++)
            _deck.push_back(new Card(static_cast<Card::Suit>(suit), static_cast<Card::Value>(value)));

    Shuffle();
}

//Деструктор
Deck::~Deck()
{
    for (auto card : _deck)
        delete card;
}

//Перетасовать карты
void Deck::Shuffle()
{
    random_shuffle(_deck.begin(), _deck.end());
}

//Выдать одну карту
Card* Deck::Deal() //Hand& Hand)
{
    if (_deck.size())
    {
        auto temp = _deck.back();
        _deck.pop_back();
        return temp;
    }
    else
        return nullptr;
}
