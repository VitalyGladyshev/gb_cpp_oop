//
// Created by Гладышев ВВ on 08.02.2022.
// ООП на примере C++
// ДЗ к уроку 2 Наследование
//

#include <iostream>

using namespace std;

//Задание 1
//Класс Человек
class Person
{
public:
    //Конструктор
    Person(string name, int age, string sex, int weight) :
            _name(name), _age(age), _sex(sex), _weight(weight) {}

    //Установка имени
    void SetName(string name) { _name = name; }
    //Установка возраста
    void SetAge(int age) { _age = age; }
    //Установка веса
    void SetWeight(int weight) { _weight = weight; }

protected:
    string _name;	//Имя
    int _age;		//Возраст
    string _sex;	//Пол
    int _weight;	//Вес
};

//Класс Студент
class Student : public Person
{
public:
    //Конструктор
    Student(string name, int age, string sex, int weight, int study_year = 1) : Person(name, age, sex, weight),
        _study_year(study_year) { _id = _student_index++; }

    //Установка года обучения
    void SetStudyYear(int study_year) { _study_year = study_year; }
    //Установка года обучения
    int SetStudyYearIncrement() { return ++_study_year; }
    //Печать информации о студенте
    void print() const;

private:
    int _study_year;            //Год обучения
    int _id;                    //id студента
    static int _student_index;  //Индекс студента
};

int Student::_student_index = 0;

void Student::print() const
{
    cout << "\tСтудент: " << _name << endl;
    cout << "\t\tid: " << _id << endl;
    cout << "\t\tвозраст: " << _age << endl;
    cout << "\t\tпол: " << _sex << endl;
    cout << "\t\tвес: " << _weight << " кг." << endl;
    cout << "\t\tгод обучения: " << _study_year << endl << endl;;
}

//Задание 2
//Класс Фрукт
class Fruit
{
public:
    //Получить имя
    string getName() const { return _name; }
    //Получить цвет
    string getColor() const { return _color; }

protected:
    //Конструктор
    Fruit(string name, string color) : _name(name), _color(color) {};

    const string _name;   //Имя
    const string _color;  //Цвет
};

//Класс Яблоко
class Apple : public Fruit
{
protected:
    //Конструктор для цепочки наследования
    Apple(string name, string color) : Fruit(name, color) {};
public:
    //Конструктор
    Apple(string color = "красное") : Fruit("Яблоко", color) {};
};

//Класс Банан
class Banana : public Fruit
{
public:
    //Конструктор
    Banana(string color = "желтый") : Fruit("Банан", color) {};
};

//Класс Яблоко ГрениСмит
class GrannySmith : public Apple
{
public:
    //Конструктор
    GrannySmith(string color = "зелёный") : Apple("ГрениСмит", color) {};
};

int main()
{
    setlocale(LC_ALL, "Russian");
// Задание 1
    cout << "Задание 1" << endl;
    Student student_pet("Петя", 18, "мужской", 65);
    Student student_vas("Вася", 20, "мужской", 75, 2);
    Student student_sen("Сеня", 21, "мужской", 80, 2);
    student_pet.print();
    student_vas.print();
    student_sen.SetStudyYearIncrement();
    student_sen.SetStudyYearIncrement();
    student_sen.print();

// Задание 2
    cout << "Задание 2" << endl;

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "\tMy " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "\tMy " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "\tMy " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;

// Задание 3
//Игра Blackjack
//class Card
//        масть
//        тип
//        количество очков
//
//class Сhip
//        номинал
//
//class Сroupier
//        vector<Card> Shoe
//        ShoeGenerator()
//        vector<Card> Cards
//        vector<Chip> Bank
//
//class Player
//        vector<Card> Cards
//        vector<Chip> Chips
//        vector<Chip> Bet
//
//class Shuffle : Сroupier
//        vector<Player> Players
}