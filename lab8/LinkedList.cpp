#include "LinkedList.h"
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    current = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    delete head;
}

template <class T>
void LinkedList<T>::AddItem(T* item) 
{
    if (isEmpty())
    { // empty list 
        head = new Node<T>(item);
        length++;
        current = head;
    }
    else if ((*item) < (*head->data))
    { 
        Node<T>* h = new Node<T>(item);
        h->next = head;
        h->prev = nullptr;
        head->prev = h;
        head = h;
        length++;
    }
    else
    { 
        Node<T>* temp = head;
        while ((temp->next != nullptr) && ((*temp->next->data) < (*item)))
        {
            temp = temp->next;
        }
        if (temp->next == nullptr) 
        {
            Node<T>* newNode = new Node<T>(item);
            newNode->next = nullptr;
            newNode->prev = temp;
            temp->next = newNode;
            length++;
        }
        else 
        {
            Node<T>* newNode = new Node<T>(item);
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            length++;
        }
    }
}

template <class T>
T* LinkedList<T>::GetItem(T* item)
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    if (!IsInList(item))
    {
        throw ItemNotFoundException();
    }

    Node<T>* temp = head;

    while ((*temp->data) != (*item))
    {
        temp = temp->next;
    }

    T* ret = new T(temp->data);

    if (temp->prev == nullptr)
    { 
        if (length == 1)
        {
            head = nullptr;
            current = nullptr;
            delete temp;
            length--;
            return (ret);
        }

        if (temp->next != nullptr)
        {
            head = temp->next;
            head->prev = nullptr;
        }

        if (temp == current)
        {
            current = temp->next;
        }
    }
    else if (temp->next == nullptr)
    { 
        if (temp == current)
        {
            current = temp->prev;
        }
        temp->prev->next = nullptr;
    }
    else
    { 
        if (temp == current)
        {
            if (temp->next == nullptr)
            {
                current = temp->prev;
            }
            current = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    length--;
    return ret;
}

template <class T>
bool LinkedList<T>::IsInList(T* item)
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    Node<T>* temp = head;

    while (temp != nullptr)
    {
        if (*temp->data == *item)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    if (head == nullptr)
    {
        return (true);
    }
    return (false);
}

template <class T>
int LinkedList<T>::Size()
{
    return length;
}

template <class T>
T* LinkedList<T>::SeeNext()
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    if (current == nullptr || current->next == nullptr)
    {
        current = nullptr;
        return nullptr;
    }
    current = current->next;
    return (current->data);
}

template <class T>
T* LinkedList<T>::SeePrev()
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    if (current == nullptr || current->prev == nullptr)
    {
        current = nullptr;
        return nullptr;
    }
    current = current->prev;
    return (current->data);
}

template <class T>
T* LinkedList<T>::SeeAt(int l)
{
    if (l >= length)
    {
        throw EndOfListException();
    }
    if (isEmpty())
    {
        throw EmptyListException();
    }
    Node<T>* temp = head;
    for (int i = 0; i < l; i++)
    {
        temp = temp->next;
    }
    return (temp->data);
}

template <class T>
T* LinkedList<T>::SeeAt()
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    return (current->data);
}

template <class T>
void LinkedList<T>::Reset()
{
    current = head;
}


