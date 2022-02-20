//
// Created by Гладышев ВВ on 20.02.2022.
// ООП на примере C++
// ДЗ к уроку 5 Совместное использование функций и методов
//

#include <iostream>
#include <string>

using namespace std;

//Шаблонный класс пара для элементов одинакового типа
template<typename T>
class Pair1
{
    T _first;
    T _second;

public:
    Pair1(T first, T second) : _first(first), _second(second) {}

    T first() const
    {
        return _first;
    }

    T second() const
    {
        return _second;
    }
};

//Шаблонный класс пара для двух разных типов
template<typename T1, typename T2>
class Pair
{
    T1 _first;
    T2 _second;

public:
    Pair(T1 first, T2 second) : _first(first), _second(second) {}

    T1 first() const
    {
        return _first;
    }

    T2 second() const
    {
        return _second;
    }
};

//Класс специализированная пара
template<typename T>
class StringValuePair : public Pair<string, T>
{
public:
    StringValuePair(string first, T second) : Pair<string, T>(first, second) {}
};

int main()
{
    setlocale(LC_ALL, "Russian");

// Задание 1
    cout << "Задание 1" << endl;

    Pair1<int> p1(6, 9);
    cout << "\tPair: " << p1.first() << ' ' << p1.second() << endl;

    const Pair1<double> p2(3.4, 7.8);
    cout << "\tPair: " << p2.first() << ' ' << p2.second() << endl;
    cout << endl;

// Задание 2
    cout << "Задание 2" << endl;

    Pair<int, double> p1_2(6, 7.8);
    cout << "\tPair: " << p1_2.first() << ' ' << p1_2.second() << endl;

    const Pair<double, int> p2_2(3.4, 5);
    cout << "\tPair: " << p2_2.first() << ' ' << p2_2.second() << endl;
    cout << endl;

// Задание 3
    cout << "Задание 3" << endl;

    StringValuePair<int> svp("Amazing", 7);
    cout << "\tPair: " << svp.first() << ' ' << svp.second() << endl;

    return 0;
}
