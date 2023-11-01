#include "Node.h"

using namespace std;

template <class T>
Node<T>::Node()
{
    data = nullptr;
    next = nullptr;
    prev = nullptr;
}

template <class T>
Node<T>::Node(T* inval)
{
    data = inval;
    next = nullptr;
    prev = nullptr;
}

template <class T>
Node<T>::~Node()
{
    delete data;
}

template <class T>
void Node<T>::setData(T* inval)
{
    data = inval;
}

template <class T>
void Node<T>::setNext(T* n)
{
    next = n;
}

template <class T>
void Node<T>::setPrev(T* p)
{
    prev = p;
}

template <class T>
T Node<T>::getData()
{
    return (data);
}

template <class T>
T Node<T>::getNext()
{
    return (next);
}

template <class T>
T Node<T>::getPrev()
{
    return (prev);
}