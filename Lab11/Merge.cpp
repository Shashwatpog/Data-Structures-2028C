#include "Merge.h"

void merge(int* array, int const left, int const mid, int const right)
{
    int sizeLeft = mid - left + 1; // Size of left subarray
    int sizeRight = right - mid; // Size of right subarray

    int* leftArray = new int[sizeLeft], * rightArray = new int[sizeRight]; // Create temporary arrays

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (auto i = 0; i < sizeLeft; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < sizeRight; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexLeft = 0, indexRight = 0; // Initial index of first and second subarrays
    int indexMergeed = left; // Initial index of merged subarray

    while (indexLeft < sizeLeft && indexRight < sizeRight) // Merge the temp arrays back into arr[l..r]
    {
        if (leftArray[indexLeft] <= rightArray[indexRight]) // If left subarray's element is less than or equal to right subarray's element
        {
            array[indexMergeed] = leftArray[indexLeft]; // Copy the element from left subarray to merged subarray
            indexLeft++;
        }
        else
        {
            array[indexMergeed] = rightArray[indexRight]; // Copy the element from right subarray to merged subarray
            indexRight++;
        }
        indexMergeed++;
    }

    while (indexLeft < sizeLeft) // Copy the remaining elements of left subarray, if there are any
    {
        array[indexMergeed] = leftArray[indexLeft]; // Copy the element from left subarray to merged subarray
        indexLeft++;
        indexMergeed++;
    }

    while (indexRight < sizeRight) // Copy the remaining elements of right subarray, if there are any
    {
        array[indexMergeed] = rightArray[indexRight]; // Copy the element from right subarray to merged subarray
        indexRight++;
        indexMergeed++;
    }

    // Delete temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

void MergeSort(int* array, int const begin, int const end)
{
    if (begin >= end) {
        return; // base case is when sub array has a length of one
    }
    int mid = begin + (end - begin) / 2; // Find the middle point

    // Sort first and second halves
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);

    merge(array, begin, mid, end); // Merge the sorted halves
}