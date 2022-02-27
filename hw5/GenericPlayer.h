//
// Created by Гладышев ВВ on 20.02.2022.
//

#ifndef GB_CPP_OOP_GENERICPLAYER_H
#define GB_CPP_OOP_GENERICPLAYER_H

#include "..\hw4\Card.h"
#include "..\hw4\Hand.h"

#include <iostream>

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
};


#endif //GB_CPP_OOP_GENERICPLAYER_H
