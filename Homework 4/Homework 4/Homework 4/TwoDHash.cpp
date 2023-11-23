#include "TwoDHash.h"
#include "HashExceptions.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

TwoDHash::TwoDHash() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 5; j++) {
			table[i][j] = nullptr; //This initializes the default table value as null.  
		}
	}
}

int TwoDHash::Hash(int inval)
{
	return (inval % 100);
}

TwoDHash::~TwoDHash() { // fix
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			delete table[i][j];
			table[i][j] = nullptr;
		}
		delete[] table[i];
	}
}

//    c.Insert – accepts a value(integer), runs a hash function on the integer, and places it
//    in the hash table.This function should return the number of spots it checks before
//    inserting the item in the hash table so if it has no collisions, it should return 1 and
//    if it has 3 collisions and then finds a spot on the 4th try, it return 4.
int TwoDHash::Insert(int inval) {
	int index = Hash(inval);

	if (table[index][0] == nullptr)
	{
		table[index][0] = new int(inval);
		numItems++;
		return 1;
	}
	int checks = 0;
	int depth = 0;
	while (depth < 5 && table[index][depth] != nullptr)
	{
		depth++;
		checks++;
	}
	if (depth == 5){
		throw FullColumnException(checks);
	}
	table[index][depth] = new int(inval);
	numItems++;
	return(checks);
}

//        d.Find – accepts a value(integer), locates the value in the hash tableand returns the
//        number of spots it checked to find the item or determine it is not in the hash table.
//        This uses the same procedure as Insert to determine number of spots checked.
int TwoDHash::Find(int inval) {
	if (isEmpty())
	{
		throw EmptyTableException();
	}
	int index = Hash(inval);
	int checks = 1;
	int depth = 0;
	while (depth < 5 && table[index][depth] != nullptr && *table[index][depth] != inval)
	{
		depth++;
		checks++;
	}
	if (depth == 5)
	{
		throw ItemNotFoundException(checks);
	}
	return checks;
}

//        e.Remove – accepts a value(integer), locates the value in the hash tableand
//        removes it from the hash table.It returns the number of spots it checked to find
//        the item or determine it is not in the hash table.This uses the same procedure as
//        Insert to determine number of spots checked.
int TwoDHash::Remove(int inval) {
	if (isEmpty())
	{
		throw EmptyTableException();
	}
	int checks = 1;
	int depth = 0;
	int index = Hash(inval);
	
	while (depth < 5 && (table[index][depth] != nullptr && *table[index][depth] != inval))
	{
		depth++;
		checks++;
	}
	if (depth == 5)
	{
		throw ItemNotFoundException(checks);
	}
	table[index][depth] = nullptr;
	numItems--;
	return checks;
}


//        f.Print – prints all items in the hash table including an indication of which spots are
//        not occupied.
void TwoDHash::Print() const{
	for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (table[i][j] != nullptr)
            {
                cout << *(table[i][j]) << " ";
            }
            else
            {
                cout << "np ";
            }
        }
        cout << endl;
    }
}

bool TwoDHash::isEmpty() // Returns true if the table is empty
{
	if (numItems == 0)
	{
		return true;
	}
	return false;
}

int TwoDHash::getSize()
{
	return numItems;
}