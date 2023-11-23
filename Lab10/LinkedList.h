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
    LinkedList(); // LinkedList constructor
    ~LinkedList(); // LinkedList destructor

    void Insert(T* item); // insert item into list
    T* Remove(T* item); // remove item from list

    bool IsInList(T* item); // check if item is in list
    bool isEmpty(); // check if list is empty

    int Size(); // return size of list

    void Reset(); // reset current to head
    T* SeeNext(); // return current and move current to next
    T* SeeAt(); // return current

    void Print(); // print list
};

#endif
