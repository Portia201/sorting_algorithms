#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two elements in an array if they are in incorrect order
 * @arr: Array to perform swap on
 * @item1: Index of the first item to swap
 * @item2: Index of the second item to swap
 * @order: 1 for ascending order, 0 for descending order
 */
void swap(int arr[], int item1, int item2, int order)
{
    int temp;

    if (order == (arr[item1] > arr[item2]))
    {
        temp = arr[item1];
        arr[item1] = arr[item2];
        arr[item2] = temp;
    }
}

/**
 * merge - Recursively sort bitonic sequences in both orders
 * @arr: Array to sort
 * @low: Index of the first element
 * @nelemnt: Number of elements
 * @order: 1 for ascending order, 0 for descending order
 */
void merge(int arr[], int low, int nelemnt, int order)
{
    int mid, i;

    if (nelemnt > 1)
    {
        mid = nelemnt / 2;
        for (i = low; i < low + mid; i++)
            swap(arr, i, i + mid, order);
        merge(arr, low, mid, order);
        merge(arr, low + mid, mid, order);
    }
}

/**
 * bitonicsort - Implement the bitonic sort algorithm
 * @arr: Array to sort
 * @low: Index of the first element
 * @nelemnt: Number of elements
 * @order: 1 for ascending order, 0 for descending order
 * @size: Length of the array
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
    int mid;

    if (nelemnt > 1)
    {
        if (order >= 1)
        {
            printf("Merging [%i/%i] (UP):\n", nelemnt, size);
            print_array(&arr[low], nelemnt);
        }
        else
        {
            printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
            print_array(&arr[low], nelemnt);
        }
        mid = nelemnt / 2;
        bitonicsort(arr, low, mid, 1, size);
        bitonicsort(arr, low + mid, mid, 0, size);
        merge(arr, low, nelemnt, order);
        if (order <= 0)
        {
            printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
            print_array(&arr[low], nelemnt);
        }
        if (order >= 1)
        {
            printf("Result [%i/%i] (UP):\n", nelemnt, size);
            print_array(&arr[low], nelemnt);
        }
    }
}

/**
 * bitonic_sort - Prepare the terrain for the bitonic sort algorithm
 * @array: Array to be sorted
 * @size: Length of the array
 */
void bitonic_sort(int *array, size_t size)
{
    int order = 1;

    if (!array || size < 2)
        return;
    bitonicsort(array, 0, size, order, size);
}
