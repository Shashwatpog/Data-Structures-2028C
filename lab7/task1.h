#pragma once
#pragma once
#ifndef _task1_
#define _task1_

#include <string>
#include "ListExceptions.h"

using namespace std;

template <class T>
class OrderedList
{
protected:
    T** PointerArray;
    int Size;
    int numItems;
    int numComps;
    int numMoves;

public:
    
    OrderedList();
    virtual void addItem(T inval);
    virtual T removeItem(T n);
    virtual int FindItem(T val); 
    bool isEmpty();
    bool isFull();
    virtual void MakeEmpty();
    string Print();
    string PrintStats();
};

#endif