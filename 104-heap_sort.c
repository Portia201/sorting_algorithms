#include "sort.h"
#include <stdio.h>

/**
 * swap - utility function to swap two integers
 * @a: integer a
 * @b: integer b
 **/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * maxHeapify - Function to heapify a Max Heap starting from a given index
 * @array: array to heapify
 * @size: size of the array
 * @idx: index to start heapifying from
 * @n: size of the heap
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
    int largest = idx;
    int left_child = 2 * idx + 1;
    int right_child = 2 * idx + 2;

    if (left_child < (int)n && array[left_child] > array[largest])
        largest = left_child;

    if (right_child < (int)n && array[right_child] > array[largest])
        largest = right_child;

    if (largest != idx)
    {
        swap(&array[idx], &array[largest]);
        print_array(array, size);
        maxHeapify(array, size, largest, n);
    }
}

/**
 * heap_sort - Function to perform Heap Sort on an array
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    /* Build heap (rearrange array) */
    for (i = (size - 2) / 2; i >= 0; --i)
        maxHeapify(array, size, i, size);

    /* One by one extract an element from heap */
    for (i = size - 1; i > 0; --i)
    {
        /* Move current root to end */
        swap(&array[0], &array[i]);
        print_array(array, size);

        /* Call maxHeapify on the reduced heap */
        maxHeapify(array, size, 0, i);
    }
}
