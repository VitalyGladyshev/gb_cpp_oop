//
// Created by Гладышев ВВ on 06.02.2022.
//

#include "Stack.h"

#include <iostream>

#define SIZE 10

using namespace std;

//Конструктор
Stack::Stack() : _values_counter(0)
{
    _ptr_stack_values = new int[SIZE]; //указатель на тело стека
    reset();
}

//Деструктор
Stack::~Stack()
{
    delete[] _ptr_stack_values;
}

//Добавление элемента в стек
bool Stack::push(const int& value)
{
    if (_values_counter < SIZE)
    {
        _ptr_stack_values[_values_counter] = value;
        _values_counter++;
        return true;
    }
    else
        return false;
}

//Извлечение элемента из стека
int Stack::pop()
{
    if (_values_counter > 0)
    {
        _values_counter--;
        return _ptr_stack_values[_values_counter];
    }
    else
        cout << "\tСтек пуст! Возвращён код ошибки" << endl;
    return -1;
}

//Очистка стека
void Stack::reset()
{
    _values_counter = 0;
    for (int i = 0; i < SIZE; i++)
        _ptr_stack_values[i] = 0;
}

//Печать элементов стека
void Stack::print()
{
    cout << "\t( ";
    if (_values_counter)
        for (int i = 0; i < _values_counter; i++)
            cout <<  _ptr_stack_values[i] << " ";
    cout << ")" << endl;
}
