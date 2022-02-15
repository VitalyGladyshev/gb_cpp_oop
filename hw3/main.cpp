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
    Parallelogram(float side, float height = 0) : _side(side), _height(height) {}

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
    Circle(float radius) : _radius(radius) {}

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
    Rectangle(float side_a, float side_b) : Parallelogram(side_a), _side_b(side_b) {}

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
    Square(float side) : Parallelogram(side) {}

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
    Rhombus(float side, float height) : Parallelogram(side, height) {}

    //Площадь ромба
    float area()
    {
        cout << "(" << __FUNCSIG__ << "): ";
        return _side * _height;
    }
};

//Задание 2
//Класс автомобиль
class Car
{
protected:
    string _company;    //компания
    string _model;      //модель

public:
    //Конструктор
    Car(string company, string model) : _company(company), _model(model)
    {
        cout << "\tКомпания: " << _company << " модель: " << _model << " (" << __FUNCSIG__ << ")" << endl;
    }
};

//Класс легковой автомобиль
class PassengerCar : virtual public Car
{
public:
    //Конструктор
    PassengerCar(string company, string model) : Car(company, model)
    {
        cout << "\tКомпания: " << _company << " модель: " << _model << " (" << __FUNCSIG__ << ")" << endl;
    }
};

//Класс автобус
class Bus : virtual public Car
{
public:
    //Конструктор
    Bus(string company, string model) : Car(company, model)
    {
        cout << "\tКомпания: " << _company << " модель: " << _model << " (" << __FUNCSIG__ << ")" << endl;
    }
};

//Класс автобус
class Minivan : public PassengerCar, Bus
{
public:
    //Конструктор
    Minivan(string company, string model) : PassengerCar(company, model), Bus(company, model), Car(company, model)
    {
        cout << "\tКомпания: " << _company << " модель: " << _model << " (" << __FUNCSIG__ << ")" << endl;
    }
};

//Задание 3
//Класс Дробь
class Fraction
{
private:
    int _numerator;     //числитель
    int _denominator;   //знаменатель

public:
    //Коррекция знака дроби
    void FractionSignCheck()
    {
        if (_denominator < 0)
        {
            if (_numerator < 0)
                _numerator = abs(_numerator);
            else
                _numerator *= -1;

            _denominator = abs(_denominator);
        }
    }
    //Распечатать дробь
    string ToString()
    {
        return to_string(_numerator) + "/" + to_string(_denominator);
    }

    //Конструктор
    Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator)
    {
        FractionSignCheck();
        if (!denominator)
        {
            _denominator = 1;
            cout << "\tЗнаменатель не может быть ревен нулю!" << endl;
            cout << "\tЗнаменатель установлен в 1!!!" << endl;
            cout << "\tДробь: " << ToString() << endl;
            cout << "\tЗадайте корректное значение - натуральное число!" << endl << endl;
        }
    }

    //Получить числитель
    int GetNumerator()
    {
        return _numerator;
    }
    //Задать числитель
    void SetNumerator(int numerator)
    {
        _numerator = numerator;
        FractionSignCheck();
    }
    //Получить знаменатель
    int GetDenominator()
    {
        return _denominator;
    }
    //Задать знаменатель
    void SetDenominator(int denominator)
    {
        if (!denominator)
        {
            _denominator = 1;
            cout << "\tЗнаменатель не может быть ревен нулю! Знаменатель установлен в 1!!! Задайте корректное значение - натуральное число!" << endl;
        }
        else
        {
            _denominator = denominator;
            FractionSignCheck();
        }
    }
    //Прегружаем оператор +
    friend Fraction operator+ (const Fraction& fr1, const Fraction& fr2)
    {
        return Fraction(fr1._numerator*fr2._denominator + fr2._numerator*fr1._denominator,
                        fr1._denominator*fr2._denominator);
    }
    //Прегружаем оператор бинарный -
    friend Fraction operator- (const Fraction& fr1, const Fraction& fr2)
    {
        return Fraction(fr1._numerator*fr2._denominator - fr2._numerator*fr1._denominator,
                        fr1._denominator*fr2._denominator);
    }
    //Прегружаем оператор унарный -
    Fraction operator- () const
    {
        return Fraction(-_numerator, _denominator);
    }
    //Прегружаем оператор *
    friend Fraction operator* (const Fraction& fr1, const Fraction& fr2)
    {
        return Fraction(fr1._numerator*fr2._numerator,fr1._denominator*fr2._denominator);
    }
    //Прегружаем оператор /
    friend Fraction operator/ (const Fraction& fr1, const Fraction& fr2)
    {
        return Fraction(fr1._numerator*fr2._denominator,fr1._denominator*fr2._numerator);
    }
    //Прегружаем оператор ==
    friend bool operator== (const Fraction& fr1, const Fraction& fr2)
    {
        return (fr1._numerator == fr2._numerator && fr1._denominator == fr2._denominator);
    }
    //Прегружаем оператор !=
    friend bool operator!= (const Fraction& fr1, const Fraction& fr2)
    {
        return (fr1._numerator != fr2._numerator && fr1._denominator != fr2._denominator);
    }
    //Прегружаем оператор <
    friend bool operator< (const Fraction& fr1, const Fraction& fr2)
    {
        return ((fr1 - fr2)._numerator < 0);
    }
    //Прегружаем оператор >
    friend bool operator> (const Fraction& fr1, const Fraction& fr2)
    {
        return ((fr1 - fr2)._numerator > 0);
    }
    //Прегружаем оператор <=
    friend bool operator<= (const Fraction& fr1, const Fraction& fr2)
    {
        return ((fr1 - fr2)._numerator <= 0);
    }
    //Прегружаем оператор >=
    friend bool operator>= (const Fraction& fr1, const Fraction& fr2)
    {
        return ((fr1 - fr2)._numerator >= 0);
    }
};

//Задание 4
//BlackJack Класс Card
class Card
{
public:
    enum class Suit                 //Перечисление: масти карты
    {
        Clubs = 0,
        Spades = 1,
        Hearts = 2,
        Diamonds = 3
    };

    enum class Value                //Перечисление: значение карты
    {
        Ace = 0,
        Two = 1,
        Three = 2,
        Four = 3,
        Five = 4,
        Six = 5,
        Seven = 6,
        Eight = 7,
        Nine = 8,
        Ten = 9,
        Jack = 10,
        Queen = 11,
        King = 12
    };

private:
    Suit _suit;                     //Масть карты
    vector<string> _suitNames;      //Название мастей карты

    Value _value;                   //Значение карты
    vector<string> _valueNames;     //Название карты
    vector<int> _valueScore;        //Очки карты

    bool _shirtUp;                  //Положение карты: true - рубашкой вверх

public:
    Card(Suit suit, Value value, bool shirtUp = true) :
        _suit(suit),
        _value(value),
        _shirtUp(shirtUp)
    {
        for (auto el : {"треф"s, "пик"s, "черв"s, "бубён"s})
            _suitNames.push_back(el);
        for (auto el : {"туз"s, "двойка"s, "тройка"s, "четвёрка"s, "пятёрка"s, "шестёрка"s, "семёрка"s,
                        "восьмёрка"s, "девятка"s, "десятка"s, "валет"s, "дама"s, "король"s})
            _valueNames.push_back(el);
        for (auto el : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 })
            _valueScore.push_back(el);
    }

    //Открываем карту
    bool Flip()
    {
        if (_shirtUp)
            _shirtUp = false;
        return _shirtUp;
    }
    //Возвращаем масть карты
    Suit GetSuit()
    {
        return _suit;
    }
    //Возвращаем название масти карты
    string GetSuitName()
    {
        return _suitNames[static_cast<int>(_suit)];
    }
    //Возвращаем значеие карты
    Value GetValue()
    {
        return _value;
    }
    //Возвращаем название значения карты
    string GetValuetName()
    {
        return _valueNames[static_cast<int>(_value)];
    }
    //Возвращаем очки карты
    int GetValueScore()
    {
        return _valueScore[static_cast<int>(_value)];
    }
};

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

    Car car("Камаз", "тягач");
    PassengerCar("ВАЗ", "Веста");
    Bus("ЛИАЗ", "5290");
    Minivan("Volkswagen", "Caravelle");
    cout << endl;

// Задание 3
    cout << "Задание 3" << endl;

    Fraction fraction_1(2, 0);
    fraction_1.SetDenominator(3);
    cout << "\tДробь 1: " << fraction_1.ToString() << endl;
    Fraction fraction_2(1, 3);
    cout << "\tДробь 2: " << fraction_2.ToString() << endl << endl;
    cout << "\tСумма: " << (fraction_1+fraction_2).ToString() << endl;
    cout << "\tРазность " << fraction_1.ToString() << " - " << fraction_2.ToString() << ": " << \
        (fraction_1-fraction_2).ToString() << endl;
    cout << "\tРазность " << fraction_2.ToString() << " - " << fraction_1.ToString() << ": " << \
        (fraction_2-fraction_1).ToString() << endl;
    cout << "\tПроизведение: " << (fraction_1*fraction_2).ToString() << endl;
    cout << "\tОтношение: " << (fraction_1/fraction_2).ToString() << endl;
    cout << "\tУнарный минус: " << (-fraction_1).ToString() << endl << endl;
    cout << "\t" << fraction_1.ToString() << " == " <<  fraction_2.ToString() << ": " << boolalpha << \
        (fraction_1 == fraction_2) << endl;
    cout << "\t" << fraction_1.ToString() << " != " <<  fraction_2.ToString() << ": " << boolalpha << \
        (fraction_1 != fraction_2) << endl;
    cout << "\t" << fraction_1.ToString() << " < " <<  fraction_2.ToString() << ": " << boolalpha << \
        (fraction_1 < fraction_2) << endl;
    cout << "\t" << fraction_1.ToString() << " > " <<  fraction_2.ToString() << ": " << boolalpha << \
        (fraction_1 > fraction_2) << endl;
    cout << "\t" << fraction_1.ToString() << " <= " <<  fraction_2.ToString() << ": " << boolalpha << \
        (fraction_1 <= fraction_2) << endl;
    cout << "\t" << fraction_1.ToString() << " >= " <<  fraction_2.ToString() << ": " << boolalpha << \
        (fraction_1 >= fraction_2) << endl;
    cout << "\t" << fraction_1.ToString() << " == " <<  fraction_1.ToString() << ": " << boolalpha << \
        (fraction_1 == fraction_1) << endl;
    cout << "\t" << fraction_1.ToString() << " <= " <<  fraction_1.ToString() << ": " << boolalpha << \
        (fraction_1 <= fraction_1) << endl;
    cout << "\t" << fraction_1.ToString() << " >= " <<  fraction_1.ToString() << ": " << boolalpha << \
        (fraction_1 >= fraction_1) << endl;
    cout << endl;

// Задание 4
    cout << "Задание 4" << endl;
    Card card_1(Card::Suit::Clubs, Card::Value::Eight);
    Card card_2(Card::Suit::Diamonds, Card::Value::Ace);
    Card card_3(Card::Suit::Hearts, Card::Value::Queen);

    vector<Card> hand { card_1, card_2, card_3 };

    int score = 0;
    for (auto card : hand)
    {
        cout << "\tКарта: " << card.GetValuetName() << " " << card.GetSuitName() << " - " << card.GetValueScore()  << \
            " очков" << endl;
        score += card.GetValueScore();
    }

    cout << endl << "\tВсего очков: " << score;
    cout << endl;
}