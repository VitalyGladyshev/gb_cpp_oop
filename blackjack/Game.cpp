//
// Created by Гладышев ВВ on 03.03.2022.
//

#include "Game.h"

//Конструктор
Game::Game(vector<Player*> players) : _house("Диллер", {}), _players(players)
{
    for (auto player : _players)
    {
        player->Add(_deck.Deal());
        player->Add(_deck.Deal());
    }
    _house.Add(_deck.Deal());

    printHands();

    bool yesAnswerFlag;
    vector<string> yesAnswer {"Д", "д", "Да", "да", "y", "Y"};
    string userAnswer;

    for (auto player : _players)
    {
        while (player->GetTotal() < 21)
        {
            cout << "\tИгрок: " << player->GetName() << endl;
            cout << "\t\tВзять карту (д/н)? ";

            cin >> userAnswer;
            cout << endl;

            for (auto answer : yesAnswer)
            {
                if (userAnswer == answer)
                {
                    yesAnswerFlag = true;
                    break;
                }
                else
                    yesAnswerFlag = false;
            }

            if (yesAnswerFlag)
            {
                player->Add(_deck.Deal());
                player->PrintHand();
                cout << "\tВсего очков: " << player->GetTotal() << endl;
                cout << endl;
            }
            else
                break;
        }
    }

    if (_house.GetTotal() < 21)
    {
        cout << "\tДиллер: себе" << endl;
        while (_house.GetTotal() < 17)
        {
            _house.Add(_deck.Deal());
        }
        _house.PrintHand();
        cout << "\tВсего очков: " << _house.GetTotal() << endl << endl;
    }

    cout << endl << "\tИтог:" << endl << endl;
    printHands();

    for (auto player : _players)
    {
        if ((player->GetTotal() == 21) && (_house.GetTotal() != 21))
            player->Win();
        else if (player->GetTotal() == _house.GetTotal())
            player->Push();
        else if (player->GetTotal() > 21)
            player->Lose();
        else if (_house.GetTotal() > 21)
            player->Win();
        else if (player->GetTotal() > _house.GetTotal())
            player->Win();
        else
            player->Lose();
    }
    cout << endl;
}

//Распечатать карты всех игроков
void Game::printHands()
{
    for (auto player : _players)
    {
        cout << "\tИгрок: " << player->GetName() << endl;
        player->PrintHand();
        cout << "\tВсего очков: " << player->GetTotal() << endl << endl;
    }
    cout << "\tДиллер" << endl;
    _house.PrintHand();
    cout << "\tВсего очков: " << _house.GetTotal() << endl << endl;
}
