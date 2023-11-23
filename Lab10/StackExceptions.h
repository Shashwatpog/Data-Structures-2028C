#pragma once
#include <exception>
#include <string>

using namespace std;

class StackUnderflowException : public std::exception // When the stack is empty, throw this exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The stack is empty.";
    }
};

class StackOverflowException : public std::exception // When the stack is full, throw this exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The stack is full.";
    }
};