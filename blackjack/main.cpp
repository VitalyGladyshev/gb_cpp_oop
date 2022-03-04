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

    vector<Player*> players;
    bool yesAnswerFlag;
    vector<string> yesAnswer {"Д", "д", "Да", "да", "y", "Y"};
    string userAnswer;

    do
    {
        cout << "Игра Blackjack" << endl << endl;
        do
        {
            cout << "\tВведите имя игрока: ";
            cin >> userAnswer;
            players.push_back(new Player(userAnswer, {}));

            cout << "\tДобавить ещё одного игрока (д/н)? ";
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
        }
        while(yesAnswerFlag);

        Game game(players);

        cout << "\tСыграть ещё (д/н)? ";
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
        for (auto player : players)
            delete player;
        players.clear();
    }
    while(yesAnswerFlag);

    return 0;
}
