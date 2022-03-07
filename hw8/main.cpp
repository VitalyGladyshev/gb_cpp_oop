//
// Created by Гладышев ВВ on 05.03.2022.
//

#include <iostream>
#include <vector>
#include <cstdlib>

#define FIELD_SIZE 10

using namespace std;

//Шаблонная функция деления
template<typename T>
std::ldiv_t div_(T numerator, T denominator)
{
    std::ldiv_t temp;
    if (denominator != 0)
        temp = std::div(static_cast<long>(numerator),  static_cast<long>(denominator));
    else
        throw "DivisionByZero";
    return temp;
}

//Класс исключения
class Ex
{
private:
    double _x;   //Вещественный параметр

public:
    //Конструктор
    Ex(double Parametr) : _x(Parametr) {}
};

//Класс Bar
class Bar
{
private:
    double _y;   //Вещественный параметр

public:
    //Конструктор
    Bar(double Parameter = 0) : _y(Parameter) {}

    //Метод устаноки параметра
    void set(double a)
    {
        if (_y + a > 100)
            throw Ex(a * _y);
        else
            _y = a;
    }

    //Получить значение параметра
    double get()
    {
        return _y;
    }
};

//Класс робот
class Robot
{
public:
    enum class Command  //Перечисление: команды движения
    {
        Up = 1,
        Down = 2,
        Right = 3,
        Left = 4
    };

private:
    int _xPosition;     //Позиция по оси х
    int _yPosition;     //Позиция по оси y
    Command _direction; //Последняя выполненная команда

public:
    //Конструктор
    Robot(int x = 0, int y = 0) //где x = 0, y = 0 верхняя левая точка поля
    {
        if ((x >= 0) && (x < FIELD_SIZE))
            _xPosition = x;
        if ((y >= 0) && (y < FIELD_SIZE))
            _yPosition = y;
    }

    //Выполнить перемещение
    void Move(Command command)
    {
        if((command >= Command::Up) && (command <= Command::Left))
        {
            switch(command)
            {
            case Command::Up:
                if (_yPosition > 0)
                    _yPosition--;
                else
                    throw "OffTheField";
                break;
            case Command::Down:
                if (_yPosition < FIELD_SIZE - 1)
                    _yPosition++;
                else
                    throw "OffTheField";
                break;
            case Command::Right:
                if (_xPosition < FIELD_SIZE - 1)
                    _xPosition++;
                else
                    throw "OffTheField";
                break;
            case Command::Left:
                if (_xPosition > 0)
                    _xPosition--;
                else
                    throw "OffTheField";
                break;
            default:
                throw "IllegalCommand";
            }
        }
        else
            throw "IllegalCommand";

        cout << "\tРобот переместился в точку: x = "
             << GetX() + 1 << ", y = " << GetY() + 1 << endl;
    }

    //Получить координату X
    int GetX()
    {
        return _xPosition;
    }

    //Получить координату Y
    int GetY()
    {
        return _yPosition;
    }

    //Получить направление (последняя выполненная команда)
    string GetDirection()
    {
        switch(_direction)
        {
            case Command::Up:
                return "вверх"s;
            case Command::Down:
                return "вниз"s;
            case Command::Right:
                return "вправо"s;
            case Command::Left:
                return "влево"s;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

// Задание 1
    cout << "Задание 1" << endl;

    try
    {
        auto result = div_(56, 0);
        cout << "\t56 / 0 = " << result.quot << "," << result.rem << endl;
    }
    catch(const char* ex)
    {
        cout << "\tОшибка: " << ex << endl;
    }
    catch(exception& ex)
    {
        cout << "\tОшибка: " << ex.what() << endl;
    }

    cout << endl;
// Задание 2
    cout << "Задание 2" << endl;

    int input;
    Bar barObject;

    do
    {
        cout << "\ty = " << barObject.get() << endl;
        cout << "\tВведите параметр a (для выхода введите 0): ";
        cin >> input;

        try
        {
            barObject.set(input);
        }
        catch(Ex& ex)
        {
            cout << "\ty + a > 100!  y = " << barObject.get() << endl;
        }
        catch(exception& ex)
        {
            cout << "\tОшибка: " << ex.what() << endl;
        }
        cout << endl;
    }
    while(input != 0);
// Задание 3
    cout << "Задание 3" << endl;

    Robot robot(4, 4);
    bool yesAnswerFlag;
    vector<string> yesAnswer {"Д", "д", "Да", "да", "y", "Y"};
    string userAnswer;
    int command;

    do
    {
        cout << "\tТекущая позиция робота на поле 10х10: x = "
            << robot.GetX() + 1 << ", y = " << robot.GetY() + 1 << ")" << endl;
        cout << "\tВведите комаду перемещения" << endl;
        cout << "\t\tВверх - 1" << endl;
        cout << "\t\tВниз - 2" << endl;
        cout << "\t\tВправо - 3" << endl;
        cout << "\t\tВлево - 4" << endl;
        cout << "\t\t> ";

        cin >> command;

        try
        {
            robot.Move(static_cast<Robot::Command>(command));
        }
        catch(const char* ex)
        {
            string str(ex);
            if (str == "IllegalCommand")
            {
                cout << "\tОшибка! Неверная команда!" << endl;
            }
            else if (str == "OffTheField")
            {
                cout << "\tОшибка! Нарушение границы поля! Позиция: x " << robot.GetX()  + 1
                    << " y " << robot.GetY() + 1 << endl;
            }
            cin.clear();
            cin.sync (); // Пустой поток
        }
        catch(exception& ex)
        {
            cout << "\tОшибка: " << ex.what() << endl;
            cin.clear();
            cin.sync (); // Пустой поток
        }
        catch(...)
        {
            cout << "\tНеизвестная шибка!" << endl;
            cin.clear();
            cin.sync (); // Пустой поток
        }

        cout << "\tНовая команда (д/н)? ";
        cin >> userAnswer;
        cout << endl;

        for (auto answer : yesAnswer)
        {
            if (userAnswer == answer)
            {
                yesAnswerFlag = true;
                break;
            }
            else
                yesAnswerFlag = false;
        }
    }
    while(yesAnswerFlag);

    cout << endl;
    return 0;
}
