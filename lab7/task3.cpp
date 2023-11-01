#pragma once
#include "task3.h"
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
SpacedOrderedList<T>::SpacedOrderedList()
{
    PointerArray = new T * [ARRAY_SIZE];
    Size = ARRAY_SIZE;
    numItems = 0;
    indexMax = 0;
    numComps = 0;
    numMoves = 0;
    for (int i = 0; i < Size; i++)
    {
        PointerArray[i] = nullptr;
    }
}

template <class T>
void SpacedOrderedList<T>::addItem(T inval)
{
    int i;  
    int nl; 
    int nr; 

    if (isFull())
    {
        throw FullListException();
    }

    if (isEmpty())
    {
        PointerArray[0] = new T(inval);
        numMoves++;
        numItems++;
        indexMax = 0;
        return;
    }

    if (inval > (*PointerArray[indexMax]) && indexMax < ARRAY_SIZE - 2)
    {
        numComps++;
        PointerArray[indexMax + 2] = new T(inval);
        numMoves++;
        numItems++;
        indexMax = indexMax + 2;
        return;
    }

    int lessIndex = 0;
    int moreIndex = 0;

    for (i = 0; i <= indexMax; i++)
    {
        numComps++;
        if (i == indexMax)
        {
            break;
        }
        else if ((PointerArray[i] != nullptr) && (*PointerArray[i] < inval))
        {
            lessIndex = i;
            numComps++;
        }
        else if ((PointerArray[i] != nullptr) && (*PointerArray[i] > inval))
        {
            moreIndex = i;
            numComps++;
            break;
        }
    }

    if (moreIndex == 1 && PointerArray[lessIndex] == nullptr)
    {
        i = 0;
    }
    else if (moreIndex == 0 && lessIndex == 0)
    {
        i = 0;
    }
    else if (moreIndex - lessIndex > 2)
    {
        i = lessIndex + 2;
    }
    else
    {
        i = lessIndex + 1;
    }

    if (PointerArray[i] == nullptr)
    { 
        PointerArray[i] = new T(inval);
        numMoves++;
        numItems++;
        return;
    }
    else
    { 
        nl = i;
        nr = i;
        while (PointerArray[nl] != nullptr && PointerArray[nr] != nullptr)
        {
            if (nl > 0)
            {
                nl--;
            }
            if (nr < 24)
            {
                nr++;
            }
            numComps++;
        }
        if (PointerArray[nl] == nullptr) 
        {
            for (int j = nl; j < i; j++) 
            {
                numMoves++;
                PointerArray[j] = PointerArray[j + 1];
                if (moreIndex - lessIndex == 1)
                {
                    i -= 1;
                }
            }
        }
        else 
        {
            for (int j = nr; j > i; j--) 
            {
                numMoves++;
                PointerArray[j] = PointerArray[j - 1];
            }
        }
        PointerArray[i] = new T(inval);
        numMoves++;
        numItems++;
        for (int i = indexMax; i > 0; i--)
        {
            if (PointerArray[i] != nullptr)
            {
                indexMax = i;
                break;
            }
        }
    }

    for (int i = Size - 1; i > 0; i--)
    {
        if (PointerArray[i] != nullptr)
        {
            indexMax = i;
            break;
        }
    }
}

template <class T>
T SpacedOrderedList<T>::removeItem(T n)
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    int index = FindItem(n);

    T retval = (*PointerArray[index]);
    numMoves++;
    PointerArray[index] = nullptr;

    for (int i = indexMax; i > 0; i--)
    {
        if (PointerArray[i] != nullptr)
        {
            indexMax = i;
            break;
        }
    }
    if (PointerArray[indexMax] == nullptr)
    {
        indexMax = 0;
    }
    numItems--;
    return retval;
}

template <class T>
bool SpacedOrderedList<T>::isEmpty()
{
    return (numItems == 0);
}

template <class T>
bool SpacedOrderedList<T>::isFull()
{
    return (numItems == ARRAY_SIZE);
}

template <class T>
void SpacedOrderedList<T>::MakeEmpty()
{

    for (int i = 0; i < Size; i++)
    {
        PointerArray[i] = nullptr;
    }
    numItems = 0;
}

template <class T>
int SpacedOrderedList<T>::FindItem(T val)
{
    for (int i = 0; i < Size; i++)
    {
        numComps++;
        if ((PointerArray[i] != nullptr) && ((*PointerArray[i]) == val))
        {
            return (i);
        }
    }
    throw ItemNotFoundException();
}

template <class T>
string SpacedOrderedList<T>::Print()
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
string SpacedOrderedList<T>::PrintStats()
{
    string ret = "Number of Comparisons: " + to_string(numComps) + "\n" + "Number of Moves: " + to_string(numMoves);
    return (ret);
}

template <class T>
int SpacedOrderedList<T>::getIndexMax()
{
    return (indexMax);
}