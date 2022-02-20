//
// Created by Гладышев ВВ on 19.02.2022.
//

#include <iostream>
#include <cstdlib>

#include "arrayint.h"

using namespace std;

//Конструктор
ArrayInt::ArrayInt(int length): m_length(length)
{
    assert(length >= 0);
    if (length > 0)
        m_data = new int[length];
    else
        m_data = nullptr;
}

//Очистка массива
void ArrayInt::erase()
{
    delete[] m_data;

// Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
    m_data = nullptr;
    m_length = 0;
}

// Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
void ArrayInt::resize(int newLength)
{
    // Если массив уже нужной длины — return
    if (newLength == m_length)
        return;

    // Если нужно сделать массив пустым — делаем это и затем return
    if (newLength <= 0)
    {
        erase();
        return;
    }

    // Теперь знаем, что newLength > 0
    // Выделяем новый массив
    int *data = new int[newLength];

    // Затем нужно разобраться с количеством копируемых элементов в новый массив
    // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
    if (m_length > 0)
    {
        int elementsToCopy = (newLength > m_length) ? m_length : newLength;
        // Поочередно копируем элементы
        for (int index=0; index < elementsToCopy ; ++index)
            data[index] = m_data[index];
    }

    // Удаляем старый массив, так как он нам уже не нужен
    delete[] m_data;

    // И используем вместо старого массива новый! Обратите внимание, m_data указывает
    // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
    // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
    m_data = data;
    m_length = newLength;
}

//Вставить элемент перед указанным
void ArrayInt::insertBefore(int value, int index)
{
    // Проверка корректности передаваемого индекса
    assert(index >= 0 && index <= m_length);

    // Создаем новый массив на один элемент больше старого массива
    int *data = new int[m_length+1];

    // Копируем все элементы до index-а
    for (int before=0; before < index; ++before)
        data[before] = m_data[before];

    // Вставляем новый элемент в новый массив
    data[index] = value;

    // Копируем все значения после вставляемого элемента
    for (int after=index; after < m_length; ++after)
        data[after+1] = m_data[after];

    // Удаляем старый массив и используем вместо него новый
    delete[] m_data;
    m_data = data;
    ++m_length;
}

//Удаление последнего элемента массива (аналог функции pop_back() в векторах)
int ArrayInt::pop_back()
{
    if (m_length)
    {
        int last = m_data[m_length-1];
        int* new_data = new int[m_length-1];

        for (int i = 0; i < m_length-1; i++)
            new_data[i] = m_data[i];

        delete[] m_data;
        m_data = new_data;
        --m_length;

        return last;
    }
    return -1;
}

//Удаление первого элемента массива (аналог pop_front() в векторах)
int ArrayInt::pop_front()
{
    if (m_length)
    {
        int first = m_data[0];
        int* new_data = new int[m_length-1];

        for (int i = 1; i < m_length; i++)
            new_data[i-1] = m_data[i];

        delete[] m_data;
        m_data = new_data;
        --m_length;

        return first;
    }
    return -1;
}

// функция сравнения элементов массива
int compare(const void* x1, const void* x2)
{
    return (*(int*)x1 - *(int*)x2);
}
//Сортировка массива
void ArrayInt::sort()
{
    qsort(m_data, m_length, sizeof(int), compare);
}

//Вывод на экран элементов
void ArrayInt::print()
{
    cout << "\t{ ";
    if (m_length)
    {
        for (int i = 0; i < m_length-1; i++)
            cout << m_data[i] << ", ";
        cout << m_data[m_length-1] << " ";
    }
    cout << "}" << endl;
}
