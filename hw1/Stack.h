//
// Created by Гладышев ВВ on 06.02.2022.
//

#ifndef GB_CPP_OOP_STACK_H
#define GB_CPP_OOP_STACK_H

// Задание 3
// Класс реализует функционал стека размером до 10 элементов
class Stack {
private:
    int* _ptr_stack_values; //указатель на тело стека
    int _values_counter;    //счётчик элементов стека

public:
    //Конструктор
    Stack();
    //Деструктор
    ~Stack();

    //Добавление элемента в стек
    bool push(const int& value);
    //Извлечение элемента из стека
    int pop();
    //Очистка стека
    void reset();
    //Печать элементов стека
    void print();
};


#endif //GB_CPP_OOP_STACK_H
