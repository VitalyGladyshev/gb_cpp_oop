//
// Created by Гладышев ВВ on 06.02.2022.
//

#include "Power.h"

#include <iostream>

using namespace std;

//Конструктор
Power::Power(const float operand_1, const float operand_2)
    : _operand_1(operand_1), _operand_2(operand_2)
{
}

//Задание членов класса - опреандов операции умножение
void Power::set(const float operand_1, const float operand_2)
{
    _operand_1 = operand_1;
    _operand_2 = operand_2;
}

//Вычисление операции: умножение
float Power::calculate() const
{
    return _operand_1 * _operand_2;
}

//Печать операндов и результата
void Power::print() const
{
    cout << "\t" << _operand_1 << " * " << _operand_2 << " = " << calculate() << endl;
}
