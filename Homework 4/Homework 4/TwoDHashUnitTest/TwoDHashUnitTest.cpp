#include "pch.h"
#include "CppUnitTest.h"
#include "../Homework 4/TwoDHash.h"
#include "../Homework 4/TwoDHash.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TwoDHashUnitTest
{
	TEST_CLASS(TwoDHashUnitTest)
	{
	public:
		TEST_METHOD(Insert)
		{
			TwoDHash* hash = new TwoDHash();
			hash->Insert(5);
			hash->Insert(3);
			hash->Insert(7);
			Assert::AreEqual(3, hash->getSize());
		}
		TEST_METHOD(Remove)
		{
			TwoDHash* hash = new TwoDHash();
			hash->Insert(5);
			hash->Insert(3);
			hash->Insert(7);
			hash->Remove(5);
			hash->Remove(3);
			hash->Remove(7);
			Assert::AreEqual(0, hash->getSize());
		}
		TEST_METHOD(Find)
		{
			TwoDHash* Hash1 = new TwoDHash();
			TwoDHash* Hash2 = new TwoDHash();
			Hash1->Insert(5);
			Hash2->Insert(5);
			Hash1->Insert(505);
			Hash2->Insert(505);
			Hash1->Insert(1005);
			Hash2->Insert(1005);
			Assert::AreEqual(Hash1->Find(1005), Hash2->Find(1005));
		}
	};
}