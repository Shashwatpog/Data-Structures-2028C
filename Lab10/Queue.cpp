#pragma once
#include "Queue.h"

Queue::Queue() // constructor
{
    head = nullptr;
}

Queue::~Queue() // destructor
{
}

void Queue::Enqueue(int inVal) // add to the end of the queue
{
    if (isEmpty())
    {
        head = new Node<int>(new int(inVal));
    }
    else
    {
        Node<int>* h = new Node<int>(new int(inVal));
        h->next = head;
        head = h;
    }
    length++;
}

int Queue::Dequeue() // remove from the front of the queue
{
    if (isEmpty())
    {
        throw EmptyQueueException();
    }
    if (length == 1)
    {
        int retval = head->getData();
        delete head;
        head = nullptr;
        length--;
        return retval;
    }
    Node<int>* temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    int retval = temp->next->getData();
    delete temp->next;
    temp->next = nullptr;
    length--;
    return retval;
}

bool Queue::isEmpty() // check if the queue is empty
{
    if (length == 0)
    {
        return true;
    }
    return false;
}

int Queue::getLength() // get the length of the queue
{
    return length;
}
