#pragma once
#ifndef _LHT_
#define _LHT_
#include <string>
#include <vector>

using namespace std;

template <class T>
class HashTable
{

protected:
    const int MAX_SIZE = 500;
    T **arr;
    bool *deleted; // initialize to false
    int numItems = 0;
    int comparisons = 0;

public:
    HashTable();
    ~HashTable();
    int Hash(int inval);
    int Insert(T *inval);
    int Remove(T *key);
    int Find(T *key);
    void Print(); 

    // not needed for this assignment but present from previous project
    T *GetItem(T *key);
    int GetLength(); // get number of items in the table
    bool isEmpty(); // check if table is empty
    int getComps(); // get number of comparisons
};

#endif