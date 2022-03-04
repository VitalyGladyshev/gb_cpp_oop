//
// Created by Гладышев ВВ on 03.03.2022.
//

#include "Game.h"

//Конструктор
Game::Game(vector<Player*> players) : _house("Диллер", {}), _players(players)
{
    //_deck.

    for (auto player : _players)
    {
        player->Add(_deck.Deal());
        player->Add(_deck.Deal());
    }

    for (auto player : _players)
    {
        cout << "\tИгрок: " << player->GetName() << endl;
        player->PrintHand();
        cout << "\tВсего очков: " << player->GetTotal() << endl << endl;
    }

}
