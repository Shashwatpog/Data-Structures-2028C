#pragma once
#include "HashTable.h"
#include "HashExceptions.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

template <class T>
HashTable<T>::HashTable()
{
    arr = new T*[MAX_SIZE];
    deleted = new bool[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = nullptr;
        deleted[i] = false;
    }
}

template <class T>
HashTable<T>::~HashTable()
{
}

// The sum of all the ASCII values for the passed in string and modulus by the maximum size of the table
template <class T>
int HashTable<T>::Hash(int inval)
{
    return (inval % MAX_SIZE);
}

template <class T>
int HashTable<T>::Insert(T *inval)
{ // Linear probing
    int index = Hash(*inval);

    if (arr[index] == nullptr)
    {
        arr[index] = inval;
        deleted[index] = false;
        numItems++;
        return 1;
    }
    int checks = 0;
    while ((arr[index] != nullptr && arr[index] != inval) || (deleted[index] == true))
    {
        index = (index + 1) % MAX_SIZE; // wraps around
        checks++;
    }
    arr[index] = inval;
    numItems++;
    deleted[index] = false;
    return(checks);
}

template <class T>
int HashTable<T>::Find(T *key)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    int checks = 1;
    int index = Hash(*key);
    while ((arr[index] != nullptr && *arr[index] != *key) || (deleted[index] == true)) // if the index is not null and the value at the index is not equal to the key or the index is deleted
    {
        index = (index + 1) % MAX_SIZE;
        checks++;
    }
    if (arr[index] == nullptr)
    {
        throw ItemNotFoundException(checks); // pass checks to exception even if the item isn't found
    }
    return checks;
}

template <class T>
int HashTable<T>::Remove(T *key)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    int checks = 1;
    int index = Hash(*key);
    while ((arr[index] != nullptr && *arr[index] != *key) || (deleted[index] == true))
    {
        index = (index + 1) % MAX_SIZE;
        checks++;
    }
    if (arr[index] == nullptr)
    {
        throw ItemNotFoundException(checks); // pass checks to exception even if the item isn't found
    }
    delete arr[index];
    arr[index] = nullptr;
    deleted[index] = true;
    numItems--;
    return checks;
}

template <class T>
void HashTable<T>::Print() // prints the table
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (arr[(i * 50) + j] != nullptr)
            {
                cout << *(arr[(i * 50) + j]) << " ";
            }
            else
            {
                cout << "np ";
            }
        }
        cout << endl;
    }
}



// not needed for this assignment but present from a previous project

template <class T>
T* HashTable<T>::GetItem(T* key)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    int index = Hash((string)*key);
    while ((arr[index] != nullptr && arr[index] != key) || (deleted[index] == true))
    {
        index = (index + 1) % MAX_SIZE;
        comparisons++;
    }
    if (arr[index] == nullptr)
    {
        throw ItemNotFoundException();
    }
    return arr[index];
}


template <class T>
int HashTable<T>::GetLength()
{
    return (numItems);
}

template <class T>
bool HashTable<T>::isEmpty()
{
    if (numItems == 0)
    {
        return true;
    }
    return false;
}

template <class T>
int HashTable<T>::getComps() {
    return(comparisons);
}