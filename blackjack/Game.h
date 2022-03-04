//
// Created by Гладышев ВВ on 03.03.2022.
//

#ifndef GB_CPP_OOP_GAME_H
#define GB_CPP_OOP_GAME_H

#include "Deck.h"
#include "Player.h"

//Класс игра Блэкджек
class Game
{
public:
    //Конструктор
    Game(vector<Player*> players);

    //Колода
    Deck _deck;
    //Рука диллера
    House _house;
    //Игроки
    vector<Player*> _players;
};


#endif //GB_CPP_OOP_GAME_H
