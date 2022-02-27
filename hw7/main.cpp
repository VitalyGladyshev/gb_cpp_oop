//
// Created by Гладышев ВВ on 27.02.2022.
// ООП на примере C++
// ДЗ к уроку 7 Потоки ввода-вывода
//

#include <iostream>
#include <ostream>
#include <memory>

using namespace std;

//Класс Дата
class Date
{
public:
    //Конструктор
    Date(int day = 1, int month = 1, int year = 1970)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    };

    //Получить день
    int GetDay() { return _day; }
    //Задать день
    bool SetDay(int day)
    {
        if ((day >= 1) && (day <= 31))
        {
            _day = day;
            return true;
        }
        else
            return false;
    }
    //Получить месяц
    int GetMonth() { return _month; }
    //Задать месяц
    bool SetMonth(int month)
    {
        if ((month >= 1) && (month <= 12))
        {
            _month = month;
            return true;
        }
        else
            return false;
    }
    //Получить год
    int GetYear() { return _year; }
    //Задать год
    bool SetYear(int year)
    {
        if ((year >= 1970) && (year <= 2500))
        {
            _year = year;
            return true;
        }
        else
            return false;
    }
    //Перегрузка оператора вывода
    friend ostream& operator<< (ostream& os, const Date* aDate)
    {
        os << "\t\tДата: " << aDate->_year << "-" << aDate->_month << "-" << aDate->_day << endl;
        return os;
    }

private:
    int _day;       //День
    int _month;     //Месяц
    int _year;      //Год
};

//Сравнение дат. Возвращает более позднюю
shared_ptr<Date> date_compare(shared_ptr<Date> date1, shared_ptr<Date>date2)
{
    if ((date1 != nullptr) && (date2 != nullptr))
    {
        if (date1->GetYear() > date2->GetYear())
            return date1;
        if (date1->GetYear() < date2->GetYear())
            return date2;
        if (date1->GetMonth() > date2->GetMonth())
            return date1;
        if (date1->GetMonth() < date2->GetMonth())
            return date2;
        if (date1->GetDay() > date2->GetDay())
            return date1;
        else
            return date2;
    }
    return nullptr;
}

//Функция для обмена дат местами
void exchange(shared_ptr<Date>& date1, shared_ptr<Date>& date2)
{
    auto tempDate = shared_ptr<Date>();
    tempDate = date1;
    date1 = date2;
    date2 = tempDate;
}

int main()
{
    setlocale(LC_ALL, "Russian");

// Задание 1
    cout << "Задание 1" << endl;
    auto dateToday = shared_ptr<Date>(new Date(24, 02, 2022));
    auto dateDate = shared_ptr<Date>();
    dateDate = dateToday;
    if(dateToday)
        cout << dateToday;
    if(dateDate)
        cout << dateDate;
    cout << endl;
// Задание 2
    cout << "Задание 2" << endl;
    auto date1 = shared_ptr<Date>(new Date(24, 02, 2022));
    auto date2 = shared_ptr<Date>(new Date(25, 01, 2022));
    cout << date1 << date2;
    cout << "\tБолее поздняя дата:" << endl << date_compare(date1, date2);

    cout << endl << "\tОбмен датами:" << endl;
    cout << date1 << date2 << endl;
    exchange(date1, date2);
    cout << date1 << date2;
    cout << endl;
}
