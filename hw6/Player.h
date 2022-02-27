//
// Created by Гладышев ВВ on 20.02.2022.
//

#ifndef GB_CPP_OOP_PLAYER_H
#define GB_CPP_OOP_PLAYER_H

#include "..\hw4\Card.h"
#include "..\hw4\Hand.h"

//BlackJack Обобщенный класс - игрок
class GenericPlayer : public Hand
{
private:
    string _name;   //Имя игрока
    bool _boosted;  //Флаг перебор

public:
    //Конструктор
    GenericPlayer(string name, initializer_list<Card*> cards): Hand(cards), _name(name), _boosted(false) {}

    //Указывает, нужна ли игроку еще одна карта. Чистая виртуальная функция
    virtual bool IsHitting() const = 0;
    //Указывает, что у игрока перебор
    bool IsBoosted();
    //Объявляет, что у игрока перебор
    void Bust();
    //Возвращает имя игрока
    string GetName() const;
};

//Класс Игрок
class Player : public GenericPlayer
{
public:
    //Конструктор
    Player(string name, initializer_list<Card*> cards);

    //Спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя
    virtual bool IsHitting() const;
    //Выводит на экран имя игрока и сообщение, что он выиграл
    void Win() const;
    //Выводит на экран имя игрока и сообщение, что он проиграл
    void Lose() const;
    //Выводит на экран имя игрока и сообщение, что он сыграл вничью
    void Push() const;
};

//Класс Игрок
class House : public GenericPlayer
{
public:
    //Конструктор
    House(string name, initializer_list<Card*> cards);

    //Спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя
    virtual bool IsHitting() const;
    //Метод переворачивает первую карту дилера
    void FlipFirstCard();
};

#endif //GB_CPP_OOP_PLAYER_H
