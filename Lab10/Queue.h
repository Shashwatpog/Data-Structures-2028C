
#pragma once
#include <string>
#include "QueueExceptions.h"
#include "Node.cpp"

using namespace std;

class Queue
{
private:
    Node<int>* head = nullptr;
    int length = 0;

public:
    Queue(); // constructor
    ~Queue(); // destructor

    int Dequeue(); // remove from front 
    void Enqueue(int inval); // add to back
    int getLength(); // get length of queue
    bool isEmpty(); // check if queue is empty
};