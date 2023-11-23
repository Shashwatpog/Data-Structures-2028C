#include "pch.h"
#include "CppUnitTest.h"
#include "../Homework 4/HashTable.h"
#include "../Homework 4/HashTable.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableUnitTest
{
	TEST_CLASS(HashTableUnitTest)
	{
	public:
		
		TEST_METHOD(Find) // Tests the find method.
		{
			HashTable<int>* Hash1 = new HashTable<int>(); // Creates a new HashTable.
			HashTable<int>* Hash2 = new HashTable<int>(); // Creates a new HashTable.
			Hash1->Insert(new int(5)); // Inserts 5 into the tab. 
			Hash2->Insert(new int(5)); // Inserts 5 into the tab.
			Assert::AreEqual(Hash1->Find(new int(5)), Hash2->Find(new int(5))); // Checks to see if 5 is found in the table.
		}
		TEST_METHOD(Insert) // Tests the insert method.
		{
			HashTable<int>* Hash = new HashTable<int>(); // Creates a new HashTable.
			for(int i = 0; i <500; i++){ // Inserts 500 items into the table.
				Hash->Insert(new int(i)); 
			}
			Assert::AreEqual(Hash->GetLength(), 500); // Checks to see if the table is full.
		}
		TEST_METHOD(Remove)
		{
			HashTable<int>* Hash = new HashTable<int>(); // Creates a new HashTable.
			for (int i = 0; i < 500; i++) { // Inserts 500 items into the table.
				Hash->Insert(new int(i));
			}
			for (int i = 0; i < 500; i++) { // Removes 500 items from the table.
				Hash->Remove(new int(i));
			}
			Assert::AreEqual(Hash->GetLength(), 0); // Checks to see if the table is empty.
		}
	};
}
