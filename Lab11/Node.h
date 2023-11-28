
#pragma once
#ifndef _Node_
#define _Node_

#include <string>
using namespace std;

template <class T>
class Node
{
public:
    T* data;     // pointer to data of node
    Node* next; // holds pointer to next node in the list
    Node* prev; // holds pointer to previous node in the list

    // Constructor (Takes an invalue of type 'T')
    Node(T* inval);
    Node(); // default constructor
    ~Node();
    void setData(T* inval);
    void setNext(T* n);
    void setPrev(T* n);

    T getData();
    T getNext();
    T getPrev();
};

#endif