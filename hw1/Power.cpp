//
// Created by Гладышев ВВ on 06.02.2022.
//

#include "Power.h"

#include <cmath>
#include <iostream>

using namespace std;

//Конструктор
Power::Power(const float basis, const float exponent)
    : _basis(basis), _exponent(exponent)
{
}

//Задание членов класса - основание, степень
void Power::set(const float basis, const float exponent)
{
    _basis = basis;
    _exponent = exponent;
}

//Вычисление операции: возведение в степень
float Power::calculate() const
{
    return pow(_basis, _exponent);
}

//Печать операндов и результата
void Power::print() const
{
    cout << "\t" << _basis << " ^ " << _exponent << " = " << calculate() << endl;
}
