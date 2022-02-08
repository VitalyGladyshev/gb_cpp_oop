//
// Created by Гладышев ВВ on 08.02.2022.
//

#include <iostream>

using namespace std;

//Класс Человек
class Person
{
public:
    //Конструктор
    Person(string name, int age, int sex, int weight) :
            _Name(name), _Age(age), _Sex(sex), _Weight(weight) {}

    //Установка имени
    void SetName(string name) { _Name = name; }
    //Установка возраста
    void SetAge(int age) { _Age = age; }
    //Установка веса
    void SetWeight(int weight) { _Weight = weight; }

private:
    string _Name;	//Имя
    int _Age;		//Возраст
    int _Sex;		//Пол
    int _Weight;	//Вес
};

//Класс Студент
class Student
{
public:
    //Конструктор
    Student() {}

private:

};

int main()
{
    setlocale(LC_ALL, "Russian");
// Задание 1

// Задание 2

// Задание 3

    return 0;
}