#pragma once
#include <iomanip>
#include <random>
#include <time.h>
#include <chrono>
#include <vector>
#include "LinkedList.cpp"
#include "Student.h"

// Sort Function Files
#include "Bubble.h"
#include "Insertion.h"
#include "Quick.h"
#include "Merge.h"


using namespace std;
typedef chrono::high_resolution_clock Clock;

void MakeArrays(int* arr, int seed, int choice)
{
	std::mt19937 mt(seed); // allows for random numbers to be generated above the typical rand max
	std::uniform_real_distribution<double> dist;

	switch (choice) {
	case 0:
		for (int i = 0; i < 10; i++)
		{
			double x = dist(mt);
			x *= 20;
			arr[i] = int(x) + 1;
		}
		break;
	case 1:
		for (int i = 0; i < 100; i++)
		{
			double x = dist(mt);
			x *= 200;
			arr[i] = int(x) + 1;
		}
		break;
	case 2:
		for (int i = 0; i < 500; i++)
		{
			double x = dist(mt);
			x *= 1000;
			arr[i] = int(x) + 1;
		}
		break;
	case 3:
		for (int i = 0; i < 5000; i++)
		{
			double x = dist(mt);
			x *= 10000;
			arr[i] = int(x) + 1;
		}
		break;
	case 4:
		for (int i = 0; i < 25000; i++)
		{
			double x = dist(mt);
			x *= 50000;
			arr[i] = int(x) + 1;
		}
		break;
	case 5:
		for (int i = 0; i < 100000; i++)
		{
			double x = dist(mt);
			x *= 100000;
			arr[i] = int(x) + 1;
		}
		break;
	default:
		break;
	}
}

// Function to print an array
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// print the 2d array that holds the times
void PrintResults(long long arr[7][6])
{
	cout << "Time in Nanoseconds" << endl;
	cout << "Sizes:\t" << "\t";
	for (int j = 0; j < 6; j++) {
		switch (j) {
		case 0:
			cout << "10\t";
			break;
		case 1:
			cout << "100\t";
			break;
		case 2:
			cout << "500\t";
			break;
		case 3:
			cout << "5000\t\t";
			break;
		case 4:
			cout << "25000\t\t";
			break;
		case 5:
			cout << "100000\t\t";
			break;
		default:
			break;
		}
	}
	cout << endl << endl;
	for (int i = 0; i < 4; i++) {

		switch (i) {
		case 0:
			cout << "Bubble Sort: " << "\t";
			break;
		case 1:
			cout << "Insert Sort: " << "\t";
			break;
		case 2:
			cout << "Quick Sort: " << "\t";
			break;
		case 3:
			cout << "Merge Sort: " << "\t";
			break;
		}
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j] << "\t";
			if (j > 2 && arr[i][j] < 9999999) {
				cout << "\t";
			}
		}
		cout << endl;
	}
}

// function to call / time bubble sort
auto Bubble(int* arr, int n)
{
	auto t1 = Clock::now();
	BubbleSort(arr, n);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}

// function to call / time insertion sort
auto Insertion(int* arr, int n)
{
	auto t1 = Clock::now();
	InsertionSort(arr, n);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}

// function to call / time quick sort
auto Quick(int* arr, int n)
{

	auto t1 = Clock::now();
	QuickSort(arr, 0, n - 1);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}

// function to call / time merge sort
auto Merge(int* arr, int n)
{
	auto t1 = Clock::now();
	MergeSort(arr, 0, n - 1);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}



// DRIVER FOR TASK 1
void main1()
{
	// initialize arrays to be sorted
	int* arr1 = new int[10];
	int* arr2 = new int[100];
	int* arr3 = new int[500];
	int* arr4 = new int[5000];
	int* arr5 = new int[25000];
	int* arr6 = new int[100000];

	long long results[7][6] = { 0 };

	int seed = 0;
	long long averagetime = 0;

	// loop through each array size and call bubble sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++)
	{
		averagetime = 0;
		switch (i)
		{
		case 0:
			for (int i = 0; i < 11; i++) // each for loop opertes in the same format
			{
				MakeArrays(arr1, seed, 0); // populate the array with random values to be sorted
				averagetime += Bubble(arr1, 10); // call the respective sort function one time and add the time to the running count
				seed++;
			}
			results[0][0] = averagetime / 10; // calculate the average and store it in a 2D array
			seed = 0;
			break;
		case 1:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr2, seed, 1);
				averagetime += Bubble(arr2, 100);
				seed++;
			}
			results[0][1] = averagetime / 10;
			seed = 0;
			break;
		case 2:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr3, seed, 2);
				averagetime += Bubble(arr3, 500);
				seed++;
			}
			results[0][2] = averagetime / 10;
			seed = 0;
			break;
		case 3:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr4, seed, 3);
				averagetime += Bubble(arr4, 5000);
				seed++;
			}
			results[0][3] = averagetime / 10;
			seed = 0;
			break;
		case 4:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr5, seed, 4);
				averagetime += Bubble(arr5, 25000);
				seed++;
			}
			results[0][4] = averagetime / 10;
			seed = 0;
			break;
		case 5:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr6, seed, 5);
				averagetime += Bubble(arr6, 100000);
				seed++;
			}
			results[0][5] = averagetime / 10;
			seed = 0;
			break;
		default:
			cout << "Invalid Array" << endl;
			break;
		}
	}
	cout << endl;
	// loop through each array size and call insertion sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++)
	{
		averagetime = 0;
		switch (i)
		{
		case 0:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr1, seed, 0);
				averagetime += Insertion(arr1, 10);
				seed++;
			}
			results[1][0] = averagetime / 10;
			seed = 0;
			break;
		case 1:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr2, seed, 1);
				averagetime += Insertion(arr2, 100);
				seed++;
			}
			results[1][1] = averagetime / 10;
			seed = 0;
			break;
		case 2:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr3, seed, 2);
				averagetime += Insertion(arr3, 500);
				seed++;
			}
			results[1][2] = averagetime / 10;
			seed = 0;
			break;
		case 3:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr4, seed, 3);
				averagetime += Insertion(arr4, 5000);
				seed++;
			}
			results[1][3] = averagetime / 10;
			seed = 0;
			break;
		case 4:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr5, seed, 4);
				averagetime += Insertion(arr5, 25000);
				seed++;
			}
			results[1][4] = averagetime / 10;
			seed = 0;
			break;
		case 5:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr6, seed, 5);
				averagetime += Insertion(arr6, 100000);
				seed++;
			}
			results[1][5] = averagetime / 10;
			seed = 0;
			break;
		default:
			cout << "Invalid Array" << endl;
			break;
		}
	}

	// loop through each array size and call quick sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++)
	{
		averagetime = 0;
		switch (i)
		{
		case 0:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr1, seed, 0);
				averagetime += Quick(arr1, 10);
				seed++;
			}
			results[2][0] = averagetime / 10;
			seed = 0;
			break;
		case 1:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr2, seed, 1);
				averagetime += Quick(arr2, 100);
				seed++;
			}
			results[2][1] = averagetime / 10;
			seed = 0;
			break;
		case 2:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr3, seed, 2);
				averagetime += Quick(arr3, 500);
				seed++;
			}
			results[2][2] = averagetime / 10;
			seed = 0;
			break;
		case 3:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr4, seed, 3);
				averagetime += Quick(arr4, 5000);
				seed++;
			}
			results[2][3] = averagetime / 10;
			seed = 0;
			break;
		case 4:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr5, seed, 4);
				averagetime += Quick(arr5, 25000);
				seed++;
			}
			results[2][4] = averagetime / 10;
			seed = 0;
			break;
		case 5:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr6, seed, 5);
				averagetime += Quick(arr6, 100000);
				seed++;
			}
			results[2][5] = averagetime / 10;
			seed = 0;
			break;
		default:
			cout << "Invalid Array" << endl;
			break;
		}
	}

	// loop through each array size and call merge sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++)
	{
		averagetime = 0;
		switch (i)
		{
		case 0:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr1, seed, 0);
				averagetime += Merge(arr1, 10);
				seed++;
			}
			results[3][0] = averagetime / 10;
			seed = 0;
			break;
		case 1:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr2, seed, 1);
				averagetime += Merge(arr2, 100);
				seed++;
			}
			results[3][1] = averagetime / 10;
			seed = 0;
			break;
		case 2:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr3, seed, 2);
				averagetime += Merge(arr3, 500);
				seed++;
			}
			results[3][2] = averagetime / 10;
			seed = 0;
			break;
		case 3:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr4, seed, 3);
				averagetime += Merge(arr4, 5000);
				seed++;
			}
			results[3][3] = averagetime / 10;
			seed = 0;
			break;
		case 4:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr5, seed, 4);
				averagetime += Merge(arr5, 25000);
				seed++;
			}
			results[3][4] = averagetime / 10;
			seed = 0;
			break;
		case 5:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr6, seed, 5);
				averagetime += Merge(arr6, 100000);
				seed++;
			}
			results[3][5] = averagetime / 10;
			seed = 0;
			break;
		default:
			cout << "Invalid Array" << endl;
			break;
		}
	}
	

	// output results
	PrintResults(results);
}


int main() {
	
	main1(); // run task 1 driver
	return 0;
}