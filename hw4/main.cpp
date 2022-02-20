//
// Created by Гладышев ВВ on 19.02.2022.
// ООП на примере C++
// ДЗ к уроку 4 Отношения между объектами в С++
//

#include <iostream>
#include <vector>

#include "arrayint.h"
#include "Card.h"
#include "Hand.h"

using namespace std;

//Задание 2
//Класс бинарного поиска
class BinTree
{
private:
    //Узел дерева бинарного поиска
    struct Node
    {
        int* pValue;        //Указатель на значение узла
        Node* pLessNode;    //Указатель на узел меньший по значению
        Node* pGreaterNode; //Указатель на узел больший по значению

        //Конструктор
        Node(): pValue(nullptr), pLessNode(nullptr),  pGreaterNode(nullptr) {}
    };

    vector<Node*> _nodes;   //Массив узлов дерева
    int* _sourceArray;      //Массив значений для построения дерева
    int _lenght;            //Длина массива значений

public:
    //Конструктор
    BinTree(vector<int>& sourceVector) : _sourceArray(sourceVector.data()), _lenght(sourceVector.size())
    {
        if (_lenght)
        {
            Node* currentNode = new Node;
            currentNode->pValue = _sourceArray;
            _nodes.push_back(currentNode);

            for (int i = 1; i < _lenght; i++)
            {
                currentNode = _nodes[0];
                while (true)
                {
                    if (_sourceArray[i] == *(currentNode->pValue))
                        break;
                    if (_sourceArray[i] > *(currentNode->pValue))
                    {
                        if (currentNode->pGreaterNode != nullptr)
                            currentNode = currentNode->pGreaterNode;
                        else
                        {
                            Node* nextNode = new Node;
                            nextNode->pValue = _sourceArray + i;
                            _nodes.push_back(nextNode);
                            currentNode->pGreaterNode = nextNode;
                            break;
                        }
                    }
                    else
                    {
                        if (currentNode->pLessNode != nullptr)
                            currentNode = currentNode->pLessNode;
                        else
                        {
                            Node* nextNode = new Node;
                            nextNode->pValue = _sourceArray + i;
                            _nodes.push_back(nextNode);
                            currentNode->pLessNode = nextNode;
                            break;
                        }
                    }
                }
            }
        }

    }
    //Деструктор
    ~BinTree()
    {
        for (auto node : _nodes)
            delete node;
    }

    //Получить количество уникальных значений
    int GetUniqueCounter()
    {
        return _nodes.size();
    }
    //Вывод на экран элементов
    void print()
    {
        cout << "\t{ ";
        if (_lenght)
        {
            for (int i = 0; i < _lenght-1; i++)
                cout << _sourceArray[i] << ", ";
            cout << _sourceArray[_lenght-1] << " ";
        }
        cout << "}" << endl;
    }
};
//Задание 3

int main()
{
    setlocale(LC_ALL, "Russian");
// Задание 1
    cout << "Задание 1" << endl;
    ArrayInt array(0);

    for (auto el : {12, 45, 32, 67, 54, 89, 54, 21})
        array.push_back(el);
    array.print();

    array.sort();
    array.print();

    array.pop_front();
    array.pop_back();
    array.print();

    array.erase();
    array.print();

    cout << endl;

// Задание 2
    cout << "Задание 2" << endl;
    vector<int> arrayForUnique {45, 76, 65, 87, 43, 76, 23 ,78, 45, 90, 45, 65, 90, 76, 54, 67};
    BinTree tree(arrayForUnique);
    tree.print();
    cout << "\tУникальных элементов: " << tree.GetUniqueCounter() << endl;
    cout << endl;

// Задание 3
    cout << "Задание 3" << endl;

    Card* card_1  = new Card(Card::Suit::Clubs, Card::Value::Eight);
    Card* card_2  = new Card(Card::Suit::Diamonds, Card::Value::Ace);
    Card* card_3  = new Card(Card::Suit::Hearts, Card::Value::Queen);

    Hand hand { card_1, card_2 };
    hand.Add(card_3);

    cout << "\tКарты на руке:" << endl;
    hand.PrintHand();
    cout << endl << "\tВсего очков: " << hand.GetTotal();
    cout << endl << endl;

    Card* card_4  = new Card(Card::Suit::Clubs, Card::Value::Two);
    Card* card_5  = new Card(Card::Suit::Hearts, Card::Value::Five);

    Hand hand_2 { card_2, card_4, card_5 };

    cout << "\tКарты на руке:" << endl;
    hand_2.PrintHand();
    cout << endl << "\tВсего очков: " << hand_2.GetTotal();
    cout << endl;

    for (auto card: {card_1, card_2, card_3, card_4, card_5})
        delete card;
}
