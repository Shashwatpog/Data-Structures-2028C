#pragma once

#ifndef _Node_
#define _Node_

#include <string>
using namespace std;

template <class T>
class Node
{
public:
    T* data; // holds pointer to data in the node
    Node* next; // holds pointer to next node in the list
    Node* prev; // holds pointer to previous node in the list

    Node(T* inval); // constructor takes in a pointer to data
    Node(); // default constructor
    ~Node(); // destructor
    void setData(T* inval); // sets data to inval
    void setNext(T* n); // sets next to n
    void setPrev(T* n); // sets prev to n

    T getData(); // returns data
    T getNext(); // returns next
    T getPrev(); // returns prev
};

#endif