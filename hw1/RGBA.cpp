//
// Created by Гладышев ВВ on 06.02.2022.
//

#include "RGBA.h"

#include <iostream>

using namespace std;

//Конструктор
RGBA::RGBA(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha)
    : _m_red(red), _m_green(green), _m_blue(blue), _m_alpha(alpha)
{
}

//Печать компонентов цвета
void RGBA::print() const
{
    cout << "\tЦвет RGBA: " << static_cast<int>(_m_red) << ", " << static_cast<int>(_m_green) << ", " <<
        static_cast<int>(_m_blue) << ", " << static_cast<int>(_m_alpha) << endl;
}
