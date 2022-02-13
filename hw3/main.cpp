//
// Created by Гладышев ВВ on 13.02.2022.
// ООП на примере C++
// ДЗ к уроку 3 Виртуальные функции и полиморфизм
//

#include <iostream>
#include <vector>
#include <cmath>

#ifndef __FUNCSIG__
#define __FUNCSIG__ __PRETTY_FUNCTION__
#endif

using namespace std;

//Задание 1
//Класс Фигура
class Figure
{
public:
    //Площадь
    virtual float area() = 0;
};

//Класс Параллелограмм
class Parallelogram : public Figure
{
protected:
    float _side;    //сторона параллелограмма
    float _height;  //высота параллелограмма

public:
    //Конструктор
    Parallelogram(float side, float height = 0) : _side(side), _height(height) {};

    //Площадь параллелограмма
    virtual float area()
    {
        cout << "(" << __FUNCSIG__ << "): ";
        return _side * _height;
    }
};

//Класс Круг
class Circle : public Figure
{
private:
    float _radius;  //радиус круга

public:
    //Конструктор
    Circle(float radius) : _radius(radius) {};

    //Площадь круга
    float area()
    {
        cout << "(" << __FUNCSIG__ << "): ";
        return _radius * _radius * M_PI;
    }
};

//Класс Прямоугольник
class Rectangle : public Parallelogram
{
private:
    float _side_b;  //сторона прямоугольника

public:
    //Конструктор
    Rectangle(float side_a, float side_b) : Parallelogram(side_a), _side_b(side_b) {};

    //Площадь прямоугольника
    float area()
    {
        cout << "(" << __FUNCSIG__ << "): ";
        return _side * _side_b;
    }
};

//Класс Квадрат
class Square : public Parallelogram
{
public:
    //Конструктор
    Square(float side) : Parallelogram(side) {};

    //Площадь квадрата
    float area()
    {
        cout << "(" << __FUNCSIG__ << "): ";
        return _side * _side;
    }
};

//Класс Ромб
class Rhombus : public Parallelogram
{
public:
    //Конструктор
    Rhombus(float side, float height) : Parallelogram(side, height){};

    //Площадь ромба
    float area()
    {
        cout << "(" << __FUNCSIG__ << "): ";
        return _side * _height;
    }
};

//Задание 2

//Задание 3

//Задание 4

int main() {
    setlocale(LC_ALL, "Russian");
// Задание 1
    cout << "Задание 1" << endl;

    vector<Figure*> figures;

    Parallelogram parallelogram(2, 3);
    figures.push_back(&parallelogram);
    Circle circle(2);
    figures.push_back(&circle);
    Rectangle rectangle(2, 3);
    figures.push_back(&rectangle);
    Square square(2);
    figures.push_back(&square);
    Rhombus rhombus(2, 3);
    figures.push_back(&rhombus);

    for(auto figure : figures)
        cout << "\tПлощадь " << figure->area() << endl;
    cout << endl;

// Задание 2
    cout << "Задание 2" << endl;

// Задание 3
    cout << "Задание 3" << endl;

}