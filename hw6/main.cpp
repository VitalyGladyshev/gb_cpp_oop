//
// Created by Гладышев ВВ on 26.02.2022.
// ООП на примере C++
// ДЗ к уроку 6 Совместное использование функций и методов
//

#include <iostream>
#include <sstream>

using namespace std;

//Манипулятор вывода двойного перевода строки
template< class CharT, class Traits >
std::basic_ostream<CharT, Traits>& endll( std::basic_ostream<CharT, Traits>& os )
{
    os.put(os.widen('\n'));
    os.put(os.widen('\n'));
    os.flush();

    return os;
}

int main()
{
    setlocale(LC_ALL, "Russian");

// Задание 1
    cout << "Задание 1" << endl;

    bool getException;
    string strValue;
    int number;

    do
    {
        cout << "\tВведите целое число: ";
        cin >> number;
        if (cin.good())
            getException = false;
        else
        {
            getException = true;
            cout << "\tДанное значение не является целым числом!" << endl;
        }
        cin.clear();
        _flushall();
    }
    while(getException);
    cout << "\tВведено целое число: " << number << endl << endl;

// Задание 2
    cout << "Задание 2" << endl;
    cout << "\tМанипулятор endll - двойной перевод строки" << endll;
    cout << "\tНовая строка!" << endll;

// Задание 3
    cout << "Задание 3" << endl;

    cout << endl;

// Задание 4
    cout << "Задание 4" << endl;

    cout << endl;

// Задание 5
    cout << "Задание 5" << endl;

    cout << endl;
}
