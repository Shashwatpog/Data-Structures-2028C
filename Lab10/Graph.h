#pragma once
#pragma once
#ifndef _Graph_
#define _Graph_

#include "LinkedList.cpp"
#include "Stack.h"
#include "Queue.h"
#include "GraphExceptions.h"

class Graph {
public:
	LinkedList<int>* verts; // dynamic array to represent verticies. Each index holds a linked list of integers representing the indicies it is connect to
	int size;

	// constructor
	Graph(int numVerts = 10);

	// destructor
	~Graph();

	// additional method
	void addEdge(int from, int to); // add edge from vertex "from" to vertex "to"
	void removeEdge(int from, int to); // remove edge from vertex "from" to vertex "to"
	bool hasEdge(int from, int to); // returns true if there is an edge from vertex "from" to vertex "to"
	int getSize(); // returns the number of vertices in the graph

	LinkedList<int>* outEdges(int from); // returns a linked list of integers representing the vertices that vertex "from" is connected to
	LinkedList<int>* inEdges(int to); // returns a linked list of integers representing the vertices that vertex "to" is connected to

	bool depthFirstSearch(int search); // returns true if the graph connects to the value "search" using depth first search
	

	void Print();
};

#endif