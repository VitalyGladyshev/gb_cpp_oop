//
// Created by Гладышев ВВ on 06.02.2022.
//

#ifndef GB_CPP_OOP_POWER_H
#define GB_CPP_OOP_POWER_H

// Задание 1
// Класс реализует функционал операции умножение
class Power {
private:
    float _operand_1;   //Операнд операции умножение
    float _operand_2;   //Операнд операции умножение

public:
    //Конструктор
    Power(const float operand_1 = 0, const float operand_2 = 0);

    //Задание членов класса - опреандов операции умножение
    void set(const float operand_1 = 0, const float operand_2 = 0);
    //Вычисление операции: умножение
    float calculate() const;
    //Печать операндов и результата
    void print() const;
};


#endif //GB_CPP_OOP_POWER_H
