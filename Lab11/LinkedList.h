#pragma once
#pragma once
#ifndef _LinkedList_
#define _LinkedList_


#include <string>
#include "ListExceptions.h"
#include "Node.h"
#include "Node.cpp"

template <class T>
class LinkedList
{
private:
    Node<T>* head;
    int length = 0;
    Node<T>* current;

public:
    // constructor and destructor
    LinkedList();
    ~LinkedList();

    // Swap method
    void Swap(int i, int j);

    // additional methods
    void AddItem(T* item);
    void Reset();

    bool IsInList(T* item);
    bool isEmpty();

    int Size();

    T* SeeNext();
    T* SeePrev();
    T* SeeAt(int l);
    T* SeeAt();
    T* GetItem(T* item);

    // sorting methods
    void BubbleSort(int key, bool ascending);
    void InsertionSort(int choicekey, bool ascending);
    void HeapSort(int key, bool ascending);
    void heapify(int N, int i, int key, bool ascending);

    Node<T>* operator[](int index);

    // print
    void Print();
};

#endif