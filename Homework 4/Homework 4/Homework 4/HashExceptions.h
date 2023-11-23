#pragma once
#include <exception>
#include <string>

using namespace std;

class EmptyTableException : public std::exception
{
public:
    string what()
    {
        return "The table is empty. Items cannot be found or removed from an empty table";
    }
};

class ItemNotFoundException : public std::exception
{
private:
    int c;
public:
    ItemNotFoundException(int c) : c(c) {} // takes in an integer and sets it to the private variable c
    
    int what()
    {
        return c;
    }
};

class EndOfListException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "You have reached the end of the list.";
    }
};

class FullColumnException : public std::exception
{
private:
    int c;
public:
    FullColumnException(int c) : c(c) {}

    int what()
    {
        return c;
    }
};