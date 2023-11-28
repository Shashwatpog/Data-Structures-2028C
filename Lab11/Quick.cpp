#include "Quick.h"

void swap(int* arr, int i, int j) // utility function to swap two elements
{
    int temp = arr[i];
    arr[i] = arr[j]; // swap arr[i] and arr[j]
    arr[j] = temp;
}

int partition(int* arr, int low, int high) // utility function to partition the array
{
    int pivot = arr[high]; // pivot

    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) // loop through the array
    {
        if (arr[j] < pivot) // if current element is smaller than the pivot
        {
            i++;
            swap(arr, i, j); // swap arr[i] and arr[j]
        }
    }
    swap(arr, i + 1, high); // swap arr[i+1] and arr[high] (or pivot)
    return (i + 1); // return the pivot index
}

void QuickSort(int* arr, int low, int high) // main function to sort the array
{
    if (low < high) // if the array has more than one element
    {
        int pi = partition(arr, low, high); // pi is partitioning index, arr[p] is now at right place

        QuickSort(arr, low, pi - 1); // sort the elements before partition
        QuickSort(arr, pi + 1, high); // sort the elements after partition
    }
}