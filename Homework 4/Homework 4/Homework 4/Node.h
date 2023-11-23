#pragma once
#ifndef _Node_
#define _Node_

#include <string>

using namespace std;

template <class T>
class Node
{
public:
    T data;     // pointer to data of node
    Node *left;  // holds pointer to right node in the list
    Node *right; // holds pointer to leftious node in the list

    // Constructor (Takes an invalue of type 'T')
    Node(T inval);
    Node(); // default constructor
    ~Node();
    void setData(T inval);
    void setRight(T *n);
    void setLeft(T *n);

    T getData();
    T getRight();
    T getLeft();
};

#endif