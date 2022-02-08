//
// Created by Гладышев ВВ on 06.02.2022.
// ООП на примере C++
// ДЗ к уроку 1 Именованные состояния
//

#include <iostream>

#include "Power.h"
#include "RGBA.h"
#include "Stack.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
// Задание 1
    cout << "Задание 1" << endl;
    Power power_operation(5);
    power_operation.print();

    power_operation.set(2, 7);
    power_operation.print();

    power_operation.set(3, 3);
    power_operation.print();

// Задание 2
    cout << "\nЗадание 2" << endl;
    RGBA button_color;
    button_color.print();

    RGBA panel_color(60, 70, 250, 255);
    panel_color.print();

// Задание 3
    cout << "\nЗадание 3" << endl;
    Stack stack;

    stack.reset();
    stack.print();
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}