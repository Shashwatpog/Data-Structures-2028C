#pragma once
#include "Graph.h"


Graph::Graph(int numVerts) {  // constructor
	verts = new LinkedList<int>[numVerts];
	for (int i = 0; i < numVerts; i++)
	{
		verts[i] = LinkedList<int>();
	}
	size = numVerts;
}

bool Graph::hasEdge(int from, int to) {  // check if edge exists
	if ((from < size) && (to < size))
	{
		if (verts[from].IsInList(new int(to)))
		{
			return true;
		}
		return false;
	}
	else {
		throw IndexOutOfBoundsException();
	}
}

void Graph::addEdge(int from, int to) { // int weight (optional)
	if (hasEdge(from, to))
	{
		throw DuplicateEdgeException();
	}
	if ((from < size) && (to < size))
	{
		verts[from].Insert(new int(to)); // insert connection (to) into linked list of index (from)
	}
	else {
		throw IndexOutOfBoundsException();
	}
}

void Graph::removeEdge(int from, int to) {
	if ((from < size) && (to < size))
	{
		try {
			verts[from].Remove(new int(to)); // remove connection (to) from linked list of index (from)
		}
		catch (ItemNotFoundException e) {
			cout << e.what() << endl;
		}
		catch (EmptyListException e) {
			cout << e.what() << endl;
		}
	}
	else {
		throw IndexOutOfBoundsException();
	}
}

int Graph::getSize() { // returns number of vertices
	return size;
}

LinkedList<int>* Graph::outEdges(int from) {
	LinkedList<int>* OutEdges = new LinkedList<int>();
	verts[from].Reset(); // resets current pointer for list of connections
	if (verts[from].isEmpty())
	{
		return OutEdges;
	}
	OutEdges->Insert(verts[from].SeeAt()); // inserts head of the list
	for (int i = 0; i < verts[from].Size() - 1; i++)
	{
		OutEdges->Insert(verts[from].SeeNext()); // move the current poitner to the next position and then returns that node's data to be added
	}
	return (OutEdges);
}

LinkedList<int>* Graph::inEdges(int to) {
	LinkedList<int>* InEdges = new LinkedList<int>();
	for (int i = 0; i < size; i++) { // iterate through all verticies
		if (verts[i].IsInList(new int(to))) { // check for to
			InEdges->Insert(new int(i)); // if it is found, insert it
		}
	}
	return InEdges;
}

void Graph::Print() { // prints all vertices and their connections
	for (int i = 0; i < size; i++)
	{
		cout << i << ": ";
		verts[i].Print();
	}
	cout << endl;
}

// DFS algorithm
bool Graph::depthFirstSearch(int search) {
	bool* visited = new bool[size];
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}
	Stack s = Stack(size);
	s.Push(0);
	while (!s.isEmpty())
	{
		int current = s.Pop();
		int edge = 0;
		visited[current] = true; // add top of stack to visited
		LinkedList<int>* neighbors = new LinkedList<int>(); // get neighbors
		neighbors = outEdges(current);
		if (neighbors->isEmpty())
		{
			continue;
		}
		neighbors->Reset();
		edge = *(neighbors->SeeAt());
		if (visited[edge] == false) // check head of neighbors
		{
			s.Push(edge);
		}
		for (int i = 1; i < neighbors->Size(); i++) // check rest of neighbors
		{
			edge = *(neighbors->SeeNext());
			if (visited[edge] == false)
			{
				s.Push(edge);
			}
		}
	}
	return (visited[search]); // return whether or not the traget vertex was visited
}

