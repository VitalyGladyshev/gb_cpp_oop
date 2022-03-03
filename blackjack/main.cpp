//
// Created by Гладышев ВВ on 27.02.2022.
// ООП на примере C++
// Игра BlackJack
//

#include <iostream>

#include "Game.h"
#include "Deck.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    srand (time(NULL));

    cout << "Проверка" << endl;

    Deck deck;

    for (int i = 0; i < 12; i++)
    {
        auto temp = deck.Deal();
        if (temp != nullptr)
        {
            temp->Flip();
            cout << "\t" << *temp;
        }
    }
    cout << endl;

    Player* player_1 = new Player("Вася", {});
    player_1->Add(deck.Deal());
    player_1->Add(deck.Deal());
    Player* player_2 = new Player("Петя", {});
    player_2->Add(deck.Deal());
    player_2->Add(deck.Deal());
    Player* player_3 = new Player("Сеня", {});
    player_3->Add(deck.Deal());
    player_3->Add(deck.Deal());

    Game game({player_1, player_2, player_3});

    for (int index = 0; index < 3; index++)
    {
        cout << "\t" << endl;
        game._players[index]->PrintHand();
    }

    delete player_1;
    delete player_2;
    delete player_3;

    return 0;
}