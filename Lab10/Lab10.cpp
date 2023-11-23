#pragma once
#include "Graph.h"
#include <string>
#include <iostream>

int printOptions() { // Prints the options for the user to choose from 
    string option;
    cout << "Press (1) to add an edge to graph." << endl;
    cout << "Press (2) remove an edge from graph." << endl;
    cout << "Press (3) Find an edge in the graph." << endl;
    cout << "Press (4) Find the out edges of a vertices. (uses from)" << endl;
    cout << "Press (5) Find the in edges of a vertices. (uses to)" << endl;
    cout << "Press (6) to Search using Depth. (uses to)" << endl;
    cout << "Press (7) to quit." << endl;
    cout << "> ";
    cin >> option;
    cout << endl;
    return stoi(option);
}

int getFrom() { // Gets the from value from the user
    int from;
    cout << "Enter From" << endl;
    cout << "> ";
    cin >> from;
    cout << endl;
    return from;
}

int getTo() { // Gets the to value from the user
    int to;
    cout << "Enter To" << endl;
    cout << "> ";
    cin >> to;
    cout << endl;
    return to;
}

int main() { // Main function
    int graphSize, from, to;
    bool result = false;
    cout << "Enter desired size of graph:" << endl;
    cout << "> ";
    cin >> graphSize;
    cout << endl;

    Graph* G = new Graph(graphSize);
    int ans = 0;

    while (ans == 0) {
        int option = printOptions();

        from = getFrom();
        to = getTo();

        switch (option) {
        case 1: // When adding an edge
            try {
                G->addEdge(from, to);
            }
            catch (IndexOutOfBoundsException e) {
                cout << e.what() << endl;
            }
            catch (DuplicateEdgeException e) {
                cout << e.what() << endl;
            }
            break;
        case 2: // When removing an edge
            try {
                G->removeEdge(from, to);
            }
            catch (IndexOutOfBoundsException e) {
                cout << e.what() << endl;
            }
            break;
        case 3: // When finding an edge
            try {
                result = G->hasEdge(from, to);
            }
            catch (DuplicateEdgeException e) {
                cout << e.what() << endl;
            }
            if (result == true) {
                cout << "Found!" << endl << endl;
            }
            else {
                cout << "Not Found!" << endl << endl;
            }
            break;
        case 4: // When finding out edges
            G->outEdges(from)->Print();
            cout << endl;
            break;
        case 5: // When finding in edges
            G->inEdges(to)->Print();
            cout << endl;
            break;
        case 6: // When searching using depth
            result = G->depthFirstSearch(to);
            if (result == true) {
                cout << "Found!" << endl << endl;
            }
            else {
                cout << "Not Found!" << endl << endl;
            }
            break;
        case 7: // When quitting
            cout << "Goodbye!" << endl;
            ans = 1;
            break;
        default:
            break;
        }
        G->Print();
    }
    return(0);
}