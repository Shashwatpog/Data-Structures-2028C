#pragma once
#pragma once
#ifndef _task3_
#define _task3_

#include <string>
#include "ListExceptions.h"
#include "task1.h"
#include "task1.cpp"

using namespace std;

template <class T>
class SpacedOrderedList : protected OrderedList<T>
{
protected:
    T** PointerArray;
    int Size;
    int numItems;
    int indexMax;
    int numComps;
    int numMoves;

public:
    
    SpacedOrderedList();
    virtual void addItem(T inval);
    virtual T removeItem(T n);
    virtual int FindItem(T val); 
    bool isEmpty();
    bool isFull();
    virtual void MakeEmpty();
    virtual string Print();
    string PrintStats();

    int getIndexMax();
};

#endif