//
// Класс ArrayInt
//

#ifndef GB_CPP_OOP_ARRAYINT_H
#define GB_CPP_OOP_ARRAYINT_H

#include <cassert> // для assert()

//Класс контейнера целых чисел
class ArrayInt
{ private:
    int m_length;   //Длина
    int *m_data;    //Массив

public:
    //Конструкторы
    ArrayInt(): m_length(0), m_data(nullptr)
    { }
    ArrayInt(int length);
    //Деструктор
    ~ArrayInt()
    {
        delete[] m_data;
    }

    //Очистка массива
    void erase();
    //Получить длину
    int getLength() { return m_length; }
    //Оператор []
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    // Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
    void resize(int newLength);
    //Вставить элемент перед указанным
    void insertBefore(int value, int index);
    //Добавить элемент в конец
    void push_back(int value) { insertBefore(value, m_length); }
    //Удаление последнего элемента массива (аналог функции pop_back() в векторах)
    int pop_back();
    //Удаление первого элемента массива (аналог pop_front() в векторах)
    int pop_front();
    //Сортировка массива
    void sort();
    //Вывод на экран элементов
    void print();
};

#endif //GB_CPP_OOP_ARRAYINT_H
