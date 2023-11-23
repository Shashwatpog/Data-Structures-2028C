#pragma once
#pragma once
#include <string>

using namespace std;

class Stack
{
protected:
    int Top = 0; // Top of the stack
    int* StackArray; // Array to hold the stack

public:
    Stack(int MaxSize = 0); // Constructor with MaxSize value as default 0 
    ~Stack(); // Destructor

    int Pop(); // Pop the top element of the stack
    void Push(int c); // Push an element to the stack
    int getLength(); // Get the length of the stack
    bool isEmpty(); // Check if the stack is empty
};