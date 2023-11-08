#pragma once
#include "BST.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
BST<T>::BST()
{
    root = nullptr;
    size = 0;
}

template <class T>
BST<T>::~BST()
{
}

template <class T>
bool BST<T>::isEmpty()
{
    if (this->size == 0)
    {
        return true;
    }
    return false;
}

template <class T>
Node<T> *BST<T>::getRoot()
{
    return (root);
}

template <class T>
void BST<T>::Insert(T inVal)
{
    if (root == nullptr)
    {
        Node<T> *temp = new Node<T>(inVal);
        root = temp;
    }
    else
    {
        Node<T> *temp = new Node<T>(inVal);
        temp = root;
        while (((inVal < temp->data) && (temp->left != nullptr)) || ((inVal >= temp->data) && (temp->right != nullptr)) && (inVal != temp->data))
        {
            if (inVal < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (inVal == temp->data)
        {
            throw DuplicateItemException();
        }

        if (inVal < temp->data)
        {
            temp->left = new Node<T>(inVal);
        }
        else
        {
            temp->right = new Node<T>(inVal);
        }
    }
    size++;

    Height(root, nullptr);

}

template <class T>
T *BST<T>::Find(T key) 
{
    if (size == 0)
    {
        throw EmptyTreeException();
    }
    Node<T> *temp = root;
    T *retval;
    while (true)
    {
        if (temp == nullptr)
        { 
            return nullptr;
        }
        if (temp->data == key)
        { 
            retval =  &(temp->data);
            return retval;
        }
        if (temp->data > key)
        { 
            temp = temp->left;
        }
        else
        { 
            temp = temp->right;
        }
    }
}

template <class T>
T BST<T>::Remove(T key)
{
    if (isEmpty()) 
    {
        throw EmptyTreeException();
    }
    if (Find(key) == nullptr) 
    {
        throw ItemNotFoundException();
    }

    Node<T> *temp = root;
    Node<T> *to_delete = nullptr;
    T retval;

    if (root->data == key) 
    {
        retval = root->data;
        if (root->right != nullptr) 
        {
            T replaceval = FindSmallestLarger(root->right);
            T removeval = Remove(replaceval);
            size++;
            root->data = removeval;
        }
        else if (root->left != nullptr) 
        {
            T replaceval = FindLargestSmaller(root->left);
            T removeval = Remove(replaceval);
            size++;
            root->data = removeval;
        }
        else 
        {
            EmptyTree();
        }

        Height(root, nullptr);

        size--;
        return (retval);
    }

    
    while ((temp->left != nullptr && temp->left->data != key) || (temp->right != nullptr && temp->right->data != key))
    {
        if (temp->data < key && temp->right->data != key)
        {
            temp = temp->right;
        }
        else if (temp->data > key && temp->left->data != key)
        {
            temp = temp->left;
        }
        else
        {
            break;
        }
    }

   

    if (temp->left != nullptr && temp->left->data == key) 
    {
        if (temp->left->left == nullptr && temp->left->right == nullptr) 
        {
            retval = temp->left->data;
            delete temp->left;
            temp->left = nullptr;
        }
        else if (temp->left->left != nullptr && temp->left->right != nullptr) 
        {
            to_delete = temp->left;
            T replaceval = FindSmallestLarger(to_delete->right);
            T removeval = Remove(replaceval); 
            size++;
            retval = to_delete->data;
            to_delete->data = removeval;
        }
        else 
        {
            to_delete = temp->left;
            if ((to_delete)->left != nullptr) 
            {
                temp->left = to_delete->left;
                retval = to_delete->data;
                to_delete->left = nullptr;
                to_delete->right = nullptr;
                delete to_delete;
            }
            else 
            {
                temp->left = to_delete->right;
                retval = to_delete->data;
                to_delete->left = nullptr;
                to_delete->right = nullptr;
                delete to_delete;
            }
        }
    }
    else 
    {
        if (temp->right->left == nullptr && temp->right->right == nullptr) 
        {
            retval = temp->right->data;
            delete temp->right;
            temp->right = nullptr;
        }
        else if (temp->right->left != nullptr && temp->right->right != nullptr) 
        {
            to_delete = temp->right;
            T replaceval = FindSmallestLarger(to_delete->right);
            T removeval = Remove(replaceval); 
            size++;
            retval = to_delete->data;
            to_delete->data = removeval;
        }
        else 
        {
            to_delete = temp->right;
            if ((to_delete)->left != nullptr)
            { 
                temp->right = to_delete->left;
                retval = to_delete->data;
                to_delete->left = nullptr;
                to_delete->right = nullptr;
                delete to_delete;
            }
            else
            { 
                temp->right = to_delete->right;
                retval = to_delete->data;
                to_delete->left = nullptr;
                to_delete->right = nullptr;
                delete to_delete;
            }
        }
    }

    size--;

    Height(root, nullptr);

    return retval;
}

template <class T>
T BST<T>::FindSmallestLarger(Node<T> *temp)
{
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp->data;
}

template <class T>
T BST<T>::FindLargestSmaller(Node<T> *temp)
{
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp->data;
}

template <class T>
void BST<T>::Print(Node<T> *toprint) 
{
    if (toprint == nullptr)
    {
        return;
    }

    cout << toprint->data << " (";
    if (toprint->left != nullptr)
    {
        cout << toprint->left->data;
    }
    cout << ", ";
    if (toprint->right != nullptr)
    {
        cout << toprint->right->data;
        cout << " )" << endl;
        Print(toprint->left);
    }
    else
    {
        cout << " )" << endl;
    }
    Print(toprint->right);
}

template <class T>
void BST<T>::PrintVect(vector<T> vects)
{
    for (int i = 0; i < vects.size(); i++)
    {
        cout << vects.at(i) << endl;
    }
}

template <class T>
int BST<T>::getSize()
{
    return (size);
}

template <class T>
vector<T> BST<T>::GetAllAscending()
{
    vect.clear();
    InOrder(root);
    return vect;
}

template <class T>
vector<T> BST<T>::GetAllDescending()
{
    vect.clear();
    InOrder(root);
    reverse(vect.begin(), vect.end());
    return vect;
}

template <class T>
void BST<T>::EmptyTree() 
{
    delete root;
    root = nullptr;
    size = 0;
}

template <class T>
void BST<T>::InOrder(Node<T> *troot) 
{
    if (troot == nullptr)
    {
        return;
    }
    InOrder(troot->left);
    vect.push_back(troot->data);
    InOrder(troot->right);
}



template <class T>
int BST<T>::Height(Node<T> *current, Node<T> *parent)
{
    
    if (current == nullptr)
    {
        return 0;
    }

    int L = Height(current->left, current);
    int R = Height(current->right, current);

    
    if (L - R >= 2)
    {
        if (current->left->left != nullptr)
        {
            RotateRight(parent, current);
            L--;
            R++;
        }
        else
        {
            RotateLeftRight(parent, current);
            L--;
            R++;
        }
    }
    else if (L - R <= -2)
    {
        if (current->right->right != nullptr)
        {
            RotateLeft(parent, current);
            L++;
            R--;
        }
        else
        {
            RotateRightLeft(parent, current);
            L++;
            R--;
        }
    }

    if (L > R)
    {
        return L + 1;
    }
    return R + 1;
}

template <class T>
void BST<T>::RotateLeft(Node<T> *parent, Node<T> *pivot) 
{
    if (pivot == root)
    {
        root = pivot->right;
        pivot->right = root->left;
        root->left = pivot;
    }
    else if (parent->left == pivot)
    { 
        parent->left = pivot->right;
        pivot->right = pivot->right->left;
        parent->left->left = pivot;
    }
    else
    { 
        parent->right = pivot->right;
        pivot->right = pivot->right->left;
        parent->right->left = pivot;
    }
}

template <class T>
void BST<T>::RotateRight(Node<T> *parent, Node<T> *pivot) 
{
    if (pivot == root)
    {
        root = pivot->left;
        pivot->left = root->right;
        root->right = pivot;
    }
    else if (parent->left == pivot)
    { 
        parent->left = pivot->left;
        pivot->left = pivot->left->right;
        parent->left->right = pivot;
    }
    else
    { 
        parent->right = pivot->left;
        pivot->left = pivot->left->right;
        parent->right->right = pivot;
    }
}

template <class T>
void BST<T>::RotateRightLeft(Node<T> *parent, Node<T> *pivot)
{
    if (pivot == root) 
    {
        root = pivot->right->left;
        pivot->right->left = root->right; 
        root->right = pivot->right;
        pivot->right = root->left;
        root->left = pivot;
    }
    else if (pivot == parent->left) 
    {
        parent->left = pivot->right->left; 
        pivot->right->left = parent->left->right;

        parent->left->right = pivot->right;
        pivot->right = parent->left->left;

        parent->left->left = pivot;
    }
    else 
    {
        parent->right = pivot->right->left; 
        pivot->right->left = parent->right->right;

        parent->right->right = pivot->right;
        pivot->right = parent->right->left;

        parent->right->left = pivot;
    }
}

template <class T>
void BST<T>::RotateLeftRight(Node<T> *parent, Node<T> *pivot)
{
    if (pivot == root) 
    {
        root = pivot->left->right;
        pivot->left->right = root->left;
        root->left = pivot->left;
        pivot->left = root->right;
        root->right = pivot;
    }
    else if (pivot == parent->left) 
    {
        parent->left = pivot->left->right; 
        pivot->left->right = parent->left->right;

        parent->left->left = pivot->left;
        pivot->left = parent->left->right;

        parent->left->right = pivot;
    }
    else 
    {
        parent->right = pivot->left->right; 
        pivot->left->right = parent->right->left;

        parent->right->left = pivot->left;
        pivot->left = parent->right->right;

        parent->right->right = pivot;
    }
}



