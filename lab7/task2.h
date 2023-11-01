#pragma once
#pragma once
#ifndef _task2_
#define _task2_

#include "task1.h"
#include "task1.cpp"
#include <string>

using namespace std;

template <class T>
class MiddleOrderedList : protected OrderedList<T>
{
protected:
    T** PointerArray;
    int Size;
    int MiddleIndex;
    int RightIndex;
    int LeftIndex;
    int numItems;
    int numComps;
    int numMoves;

public:
    
    MiddleOrderedList();
    void addItem(T inval);
    T removeItem(T n);
    int FindItem(T val); 
    bool isEmpty();
    bool isFull();
    void MakeEmpty();
    string Print();
    string PrintStats();

    int getRight();
    int getLeft();
};

#endif