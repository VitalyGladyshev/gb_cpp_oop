//
// Created by Гладышев ВВ on 06.02.2022.
//

#ifndef GB_CPP_OOP_POWER_H
#define GB_CPP_OOP_POWER_H

// Задание 1
// Класс реализует функционал операции возведение в степень
class Power {
private:
    float _basis;       //Основание
    float _exponent;    //Степень

public:
    //Конструктор
    Power(const float basis = 0, const float exponent = 0);

    //Задание членов класса - основание, степень
    void set(const float basis = 0, const float exponent = 0);
    //Вычисление операции: возведение в степень
    float calculate() const;
    //Печать операндов и результата
    void print() const;
};


#endif //GB_CPP_OOP_POWER_H
