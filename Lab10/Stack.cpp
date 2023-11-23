#pragma once
#include "Stack.h"
#include "StackExceptions.h"

Stack::Stack(int MaxSize) // Constructor with parameter MaxSize (size of the stack) 
{
    StackArray = new int(MaxSize);
    for (int i = 0; i < MaxSize; i++)
    {
        StackArray[i] = 0;
    }
}

Stack::~Stack() // Destructor
{
}

void Stack::Push(int c) // Pushes an element to the stack
{
    if (Top < 5) // If the stack is not full
    {
        StackArray[Top] = c;
        Top++;
    }
    else
    {
        throw StackOverflowException();
    }
}

int Stack::Pop() // Pops an element from the stack
{
    if (isEmpty()) // If the stack is empty
    {
        throw StackUnderflowException();
    }
    Top--;
    return (StackArray[Top]);
}

int Stack::getLength() // Returns the length of the stack
{
    return (Top);
}

bool Stack::isEmpty() // Checks if the stack is empty
{
    if (Top == 0)
    {
        return true;
    }
    return false;
}