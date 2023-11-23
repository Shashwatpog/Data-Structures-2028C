#pragma once
#ifndef TWODHASH_H
#define TWODHASH_H
#include <string>
#include <iostream>
#include <math.h>
#include <exception>

class TwoDHash {

public:

	TwoDHash(); // Constructor
	~TwoDHash(); // Destructor

	bool isEmpty(); // Check if the tree is empty
	int Hash(int inval); // Hash function
	int Insert(int inval); // Insert a value into the table
	int Find(int inval); // Find a value in the table
	int Remove(int inval); // Remove a value from the table
	void Print() const; // Print the table
	int getSize(); // Get the size of the table

protected:
	int *table[100][5]; // 2D array
	const int MAX_SIZE = 500; // max size of the table
	int numItems = 0; // number of items in the table
};
#endif