//
// Created by Гладышев ВВ on 20.02.2022.
//

#include <iostream>

//#include "..\hw4\Card.h"
//#include "..\hw4\Hand.h"
#include "Player.h"

//Указывает, что у игрока перебор
bool GenericPlayer::IsBoosted()
{
    if (GetTotal() > 11)
        _boosted = true;
    else
        _boosted = false;
    return _boosted;
}

//Объявляет, что у игрока перебор
void GenericPlayer::Bust()
{
    cout << "\tУ игрока " << _name << " перебор!" << endl;
}

//Возвращает имя игрока
string GenericPlayer::GetName() const
{
    return _name;
}

//Конструктор
Player::Player(string name, initializer_list<Card*> cards) : GenericPlayer(name, cards) {}

//Спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя
bool Player::IsHitting() const
{
    cout << "\tВзять карту (д/н)?" << endl;
    string userAnswer;
    cin >> userAnswer;
    vector<string> yesAnswer {"Д", "д", "Да", "да", "y", "Y"};
    bool yesAnswerFlag = false;

    for (auto answer : yesAnswer)
        if (userAnswer == answer)
            yesAnswerFlag = true;

    return yesAnswerFlag;
}

//Выводит на экран имя игрока и сообщение, что он выиграл
void Player::Win() const
{
    cout << "\tИгрок " << GetName() << " выиграл!" << endl;
}

//Выводит на экран имя игрока и сообщение, что он проиграл
void Player::Lose() const
{
    cout << "\tУ игрока " << GetName() << " перебор!" << endl;
}

//Выводит на экран имя игрока и сообщение, что он сыграл вничью
void Player::Push() const
{
    cout << "\tУ игрока " << GetName() << " перебор!" << endl;
}

//Конструктор
House::House(string name, initializer_list<Card*> cards) : GenericPlayer(name, cards) {}

//Спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя
bool House::IsHitting() const
{
    return (Hand::GetTotal() <= 16);
}
//Метод переворачивает первую карту дилера
void House::FlipFirstCard()
{
    if (Hand::FlipCardNumber(0))
        cout << "\tНет карты" << endl;
}
