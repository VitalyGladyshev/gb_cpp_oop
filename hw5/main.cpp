//
// Created by Гладышев ВВ on 20.02.2022.
// ООП на примере C++
// ДЗ к уроку 5 Совместное использование функций и методов
//

#include <iostream>
#include <vector>

using namespace std;

//Класс
class Pair1
{

};

//Класс
class Pair
{

};

//Класс
class StringValuePair
{

};

int main()
{
    setlocale(LC_ALL, "Russian");

// Задание 1
    cout << "Задание 1" << endl;

//    Pair1<int> p1(6, 9);
//    cout << "\tPair: " << p1.first() << ' ' << p1.second() << endl;
//
//    const Pair1<double> p2(3.4, 7.8);
//    cout << "\tPair: " << p2.first() << ' ' << p2.second() << endl;

    cout << endl;

// Задание 2
    cout << "Задание 2" << endl;

//    Pair<int, double> p1(6, 7.8);
//    cout << "\tPair: " << p1.first() << ' ' << p1.second() << endl;
//
//    const Pair<double, int> p2(3.4, 5);
//    cout << "\tPair: " << p2.first() << ' ' << p2.second() << endl;

    cout << endl;

// Задание 3
    cout << "Задание 3" << endl;

//    StringValuePair<int> svp("Amazing", 7);
//    cout << "\tPair: " << svp.first() << ' ' << svp.second() << endl;

    cout << endl;

    return 0;
}