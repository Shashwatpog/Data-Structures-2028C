#include "Student.h"

Student::Student(string f, string l, long m)
{
	first = f;
	last = l;
	mnumber = m;
}

Student::Student(Student& s)
{
	first = s.first;
	last = s.last;
	mnumber = s.mnumber;
}

Student::~Student()
{

}

// helper function to return the specific key asked for by the sorting algorithms in the main (passed to the linked list sorting functions, then passed to this function)
string Student::getData(int key)
{
	if (key == 1)
	{
		return first;
	}
	else if (key == 2)
	{
		return last;
	}
	else
	{
		return to_string(mnumber);
	}
}

// print function to print the student's information
void Student::Print()
{
	cout << "First Name: " << first << "\t";
	if (first.length() < 4)
	{
		cout << "\t";
	}
	cout << "Last Name: " << last << "\t";
	if (last.length() < 5)
	{
		cout << "\t";
	}
	cout << "MNumber: " << mnumber << endl;
}