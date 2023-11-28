#pragma once
#include <string>
#include <iostream>

using namespace std;

class Student {
public:
	string first;
	string last;
	long mnumber;

	// Constructor / destructor
	Student(string f = "test", string l = "name", long m = 0);
	Student(Student& s);
	~Student();

	// getter to return a specific attribute based on the key
	string getData(int key);

	// print function
	void Print();
};