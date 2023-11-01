#pragma once
#pragma once
#include <exception>
#include <string>

using namespace std;

class EmptyListException : public std::exception
{
public:
    string what() 
    {
        return "The list is empty. Items cannot be found in or removed from an empty list";
    }
};

class FullListException : public std::exception
{
public:
    string what() 
    {
        return "The list is Full. Items cannot be added to a full list";
    }
};

class ItemNotFoundException : public std::exception
{
public:
    string what() 
    {
        return "The item you are looking for could not be found in the list";
    }
};

class EndOfListException : public std::exception
{
public:
    string what() 
    {
        return "You have reached the end of the list.";
    }
};