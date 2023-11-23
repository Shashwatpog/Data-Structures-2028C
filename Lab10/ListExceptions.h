#pragma once
#include <exception>
#include <string>

using namespace std;

class EmptyListException : public std::exception // When the list is empty, this exception is thrown
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The list is empty. Items cannot be found in or removed from an empty list";
    }
};

class ItemNotFoundException : public std::exception // When the item is not found in the list, this exception is thrown
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The item you are looking for could not be found in the list";
    }
};

class EndOfListException : public std::exception // When the end of the list is reached, this exception is thrown
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "You have reached the end of the list.";
    }
};