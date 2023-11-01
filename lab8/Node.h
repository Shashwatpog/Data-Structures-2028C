#pragma once
#ifndef _Node_
#define _Node_

#include <string>
using namespace std;

template <class T>
class Node
{
public:
    T* data;     
    Node* next; 
    Node* prev; 

    
    Node(T* inval);
    Node(); 
    ~Node();
    void setData(T* inval);
    void setNext(T* n);
    void setPrev(T* n);

    T getData();
    T getNext();
    T getPrev();
};

#endif