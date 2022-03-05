//
// Created by Гладышев ВВ on 05.03.2022.
//

#include <iostream>

using namespace std;

template<typename T>
double div_(T divisible, T divisor)
{
    double temp = divisible / divisor;
    return temp;
}

int main()
{
    setlocale(LC_ALL, "Russian");

// Задание 1
    cout << "Задание 1" << endl;
    cout << "\t56 / 7 = " << div_(56, 7) << endl;
    cout << endl;
// Задание 2
    cout << "Задание 2" << endl;

    cout << endl;
// Задание 3
    cout << "Задание 3" << endl;

    cout << endl;
    return 0;
}
