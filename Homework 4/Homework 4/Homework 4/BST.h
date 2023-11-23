#pragma once
#ifndef _BST_
#define _BST_
#include <string>
#include <vector>
#include "Node.h"
#include "Node.cpp"
#include "TreeExceptions.h"

using namespace std;

template <class T>
class BST
{

private:
    Node<T> *root;
    int size;
    vector<T> vect;
    int checks = 0;

public:
    // Constructor
    BST();
    // Destructor
    ~BST();

    T *Find(T key); // Find a node with a given key
    void Find2(T key); // Find a node with a given key and increment checks

    void Insert(T inVal); // Insert a node with a given key

    T Remove(T key); // Remove a node with a given key

    T FindSmallestLarger(Node<T> *temp); // Find the smallest larger node
    T FindLargestSmaller(Node<T>* temp); // Find the largest smaller node

    int getSize(); // Get the size of the tree

    vector<T> GetAllAscending(); // Get all the nodes in ascending order
    vector<T> GetAllDescending(); // Get all the nodes in descending order

    void EmptyTree(); // Empty the tree
    void Print(Node<T> *temp); // Print the tree
    void PrintVect(vector<T> vects); // Print the vector

    void InOrder(Node<T> *troot); // In order traversal

    int Height(Node<T> *current, Node<T> *parent); // Get the height of the tree
    void RotateLeft(Node<T> *parent, Node<T> *pivot); // Rotate left
    void RotateRight(Node<T> *parent, Node<T> *pivot); // Rotate right
    void RotateLeftRight(Node<T>* parent, Node<T>* pivot); // Rotate left right
    void RotateRightLeft(Node<T>* parent, Node<T>* pivot); // Rotate right left

    bool isEmpty(); // Check if the tree is empty
    Node<T>* getRoot(); // Get the root of the tree

    void ResetChecks(); // Reset the checks
    int getChecks(); // Get the checks
};

#endif