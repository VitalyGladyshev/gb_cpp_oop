//
// Created by Гладышев ВВ on 20.02.2022.
//

#include <iostream>

#include "GenericPlayer.h"

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
