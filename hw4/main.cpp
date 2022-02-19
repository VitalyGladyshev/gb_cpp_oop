//
// Created by Гладышев ВВ on 19.02.2022.
// ООП на примере C++
// ДЗ к уроку 4 Отношения между объектами в С++
//

#include <iostream>
#include <vector>

#include "arrayint.h"

using namespace std;

//Задание 2

//Задание 3

int main()
{
    setlocale(LC_ALL, "Russian");
// Задание 1
    cout << "Задание 1" << endl;
    ArrayInt array(0);

    for (auto el : {12, 45, 32, 67, 54, 89, 54, 21})
        array.push_back(el);
    array.print();

    array.sort();
    array.print();

    array.pop_front();
    array.pop_back();
    array.print();

    array.erase();
    array.print();

    cout << endl;

// Задание 2
    cout << "Задание 2" << endl;

    cout << endl;

// Задание 3
    cout << "Задание 3" << endl;


}