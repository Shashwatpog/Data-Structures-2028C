#include "Insertion.h"

void InsertionSort(int* arr, int n) // n is the size of the array arr
{
	int i, j, key;			// i is the index of the current element, j is the index of the previous element, key is the current element
	for (i = 1; i < n; i++) // start from the second element
	{
		key = arr[i];				   // set the current element to key
		j = i - 1;					   // set the previous element to j
		while (j >= 0 && arr[j] > key) // while the previous element is greater than the current element
		{
			arr[j + 1] = arr[j]; // move the previous element to the right
			j = j - 1;			 // move j to the left
		}
		arr[j + 1] = key; // set the current element to the left of the previous element
	}
}