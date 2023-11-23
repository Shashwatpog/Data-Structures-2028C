#pragma once
#include "Node.h"

using namespace std;

template <class T>
Node<T>::Node() //default constructor
{
    data = nullptr;
    next = nullptr;
    prev = nullptr;
}

template <class T>
Node<T>::Node(T* inval) //overloaded constructor
{
    data = inval;
    next = nullptr;
    prev = nullptr;
}

template <class T>
Node<T>::~Node() //destructor
{
    delete data;
}

template <class T>
void Node<T>::setData(T* inval) //Set data
{
    data = inval;
}

template <class T>
void Node<T>::setNext(T* n) //Set next
{
    next = n;
}

template <class T>
void Node<T>::setPrev(T* p) //Set prev
{
    prev = p;
}

template <class T>
T Node<T>::getData() //Get data
{
    return (*data);
}

template <class T>
T Node<T>::getNext() //Get next
{
    return (next);
}

template <class T>
T Node<T>::getPrev() //Get prev
{
    return (prev);
}