#include "Node.h"

using namespace std;

template <class T>
Node<T>::Node()
{
    data = T();
    right = nullptr;
    left = nullptr;
}

template <class T>
Node<T>::Node(T inval)
{
    data = inval;
    right = nullptr;
    left = nullptr;
}

template <class T>
Node<T>::~Node()
{
    delete left;
    delete right;
}

template <class T>
void Node<T>::setData(T inval)
{
    data = inval;
}

template <class T>
void Node<T>::setRight(T *n)
{
    right = n;
}

template <class T>
void Node<T>::setLeft(T *p)
{
    left = p;
}

template <class T>
T Node<T>::getData()
{
    return (data);
}

template <class T>
T Node<T>::getRight()
{
    return (right);
}

template <class T>
T Node<T>::getLeft()
{
    return (left);
}