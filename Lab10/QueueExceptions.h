#pragma once
#include <exception>
#include <string>

using namespace std;

class EmptyQueueException : public std::exception // When the queue is empty, this exception is thrown
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The Queue is empty.";
    }
};

class ItemNotFoundExceptionQ : public std::exception // When the item is not found in the queue, this exception is thrown
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The item you are looking for could not be found in the queue.";
    }
};

class EndOfQueueException : public std::exception // When the end of the queue is reached, this exception is thrown
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "You have reached the end of the queue.";
    }
};