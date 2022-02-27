//
// Created by Гладышев ВВ on 26.02.2022.
// ООП на примере C++
// ДЗ к уроку 6 Совместное использование функций и методов
//

#include <iostream>
#include <sstream>

#include "..\hw4\Card.h"
#include "..\hw4\Hand.h"
#include "..\hw6\Player.h"

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

    bool notNumber;
    string strValue;
    int number;

    do
    {
        cout << "\tВведите целое число: ";
        cin >> strValue;

        string::const_iterator it = strValue.begin();
        while (it != strValue.end() && std::isdigit(*it))
            ++it;

        if (!strValue.empty() && it == strValue.end())
            notNumber = false;
        else
        {
            notNumber = true;
            cout << "\tДанное значение не является целым числом!" << endl;
        }

    }
    while(notNumber);

    stringstream toNumber;
    toNumber << strValue;
    toNumber >> number;
    cout << "\tВведено целое число: " << number << endl << endl;

// Задание 2
    cout << "Задание 2" << endl;
    cout << "\tМанипулятор endll - двойной перевод строки" << endll;
    cout << "\tНовая строка!" << endll;

// Задания 3-5
    cout << "Задания 3-5" << endl;

    Card* card_1  = new Card(Card::Suit::Clubs, Card::Value::Eight);
    Card* card_2  = new Card(Card::Suit::Diamonds, Card::Value::Ace);
    Card* card_3  = new Card(Card::Suit::Hearts, Card::Value::Queen);

    Player player("Вася", {card_1, card_2, card_3}) ;
    cout << player;
    cout << endl;
}
