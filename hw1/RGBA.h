//
// Created by Гладышев ВВ on 06.02.2022.
//

#ifndef GB_CPP_OOP_RGBA_H
#define GB_CPP_OOP_RGBA_H

#include <cstdint>

using namespace std;

// Задание 2
// Класс реализует объект хранения компонентов цвета
// Каналы: RGB + A
class RGBA {
private:
    uint8_t _m_red;     //красный компонент цвета
    uint8_t _m_green;   //зелёный компонент цвета
    uint8_t _m_blue;    //синий компонент цвета
    uint8_t _m_alpha;   //канал прозрачности

public:
    //Конструктор
    RGBA(const uint8_t red = 0, const uint8_t green = 0, const uint8_t blue = 0, const uint8_t alpha = 255);

    //Печать компонентов цвета
    void print() const;
};


#endif //GB_CPP_OOP_RGBA_H
