#pragma once
#include "task1.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 25;

template <class T>
OrderedList<T>::OrderedList()
{
    PointerArray = new T * [ARRAY_SIZE];
    Size = ARRAY_SIZE;
    numItems = 0;
    numMoves = 0;
    numComps = 0;
    for (int i = 0; i < Size; i++)
    {
        PointerArray[i] = nullptr;
    }
}

template <class T>
void OrderedList<T>::addItem(T inval)
{

    if (isFull())
    {
        cout << "Got Full" << endl;
        throw FullListException();
    }

    
    if (isEmpty())
    {
        PointerArray[0] = new T(inval);
        numMoves++;
        numItems++;
        return;
    }

    
    if ((*PointerArray[numItems - 1]) < inval)
    {
        PointerArray[numItems] = new T(inval);
        numMoves++;
        numItems++;
        return;
    }

    
    int i;                         
    for (i = 0; i < numItems; i++) 
    {
        numComps++;
        if ((*PointerArray[i]) > inval)
        {
            break;
        }
    }
    for (int j = numItems; j > i; j--) 
    {
        PointerArray[j] = PointerArray[j - 1];
        numMoves++;
    }
    PointerArray[i] = new T(inval);
    numMoves++;
    numItems++;
}

template <class T>
T OrderedList<T>::removeItem(T n)
{
    if (isEmpty())
    {
        cout << "Got Empty" << endl;
        throw EmptyListException();
    }
    int index = FindItem(n);
    T retval = (*PointerArray[index]);
    numMoves++;
    for (int i = index; i < numItems; i++) 
    {
        PointerArray[i] = PointerArray[i + 1];
        numMoves++;
    }
    numItems--;
    return retval;
}

template <class T>
bool OrderedList<T>::isEmpty()
{
    return (numItems == 0);
}

template <class T>
bool OrderedList<T>::isFull()
{
    return (numItems == ARRAY_SIZE);
}

template <class T>
void OrderedList<T>::MakeEmpty()
{
    numItems = 0;
}

template <class T>
int OrderedList<T>::FindItem(T val)
{
    for (int i = 0; i < numItems; i++)
    {
        numComps++;
        if ((*PointerArray[i]) == val)
        {
            return (i);
        }
    }
    throw ItemNotFoundException();
}

template <class T>
string OrderedList<T>::Print()
{
    string ret = "";
    for (int i = 0; i < Size; i++)
    {
        if (PointerArray[i] == nullptr)
        {
            ret += "np ";
        }
        else
        {
            ret += to_string((*PointerArray[i]));
            ret += " ";
        }
    }
    return (ret);
}

template <class T>
string OrderedList<T>::PrintStats()
{
    string ret = "";
    ret += "Number of Comparisons: ";
    ret += to_string(numComps);
    ret += "\n";
    ret += "Number of Moves: ";
    ret += to_string(numMoves);
    return (ret);
}