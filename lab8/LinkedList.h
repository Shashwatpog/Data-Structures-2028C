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
    
    LinkedList();
    ~LinkedList();

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

};

#endif