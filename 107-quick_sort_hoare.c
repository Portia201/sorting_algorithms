#include "sort.h"

/**
 * swap - Swap the positions of two elements in an array
 * @array: Array
 * @item1: Index of the first element
 * @item2: Index of the second element
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
    int tmp = array[item1];
    array[item1] = array[item2];
    array[item2] = tmp;
}

/**
 * hoare_partition - Implement the Hoare partition scheme for Quick Sort
 * @array: Array to partition
 * @first: Index of the first element
 * @last: Index of the last element
 * @size: Size of the array
 *
 * Return: Index of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
    int pivot = array[last];
    int current = first - 1, finder = last + 1;

    while (1)
    {
        do {
            current++;
        } while (array[current] < pivot);
        
        do {
            finder--;
        } while (array[finder] > pivot);

        if (current >= finder)
            return current;

        swap(array, current, finder);
        print_array(array, size);
    }
}

/**
 * qs - Implement the Quick Sort algorithm recursively
 * @array: Array to sort
 * @first: Index of the first element
 * @last: Index of the last element
 * @size: Size of the array
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
    ssize_t position = 0;

    if (first < last)
    {
        position = hoare_partition(array, first, last, size);
        qs(array, first, position - 1, size);
        qs(array, position, last, size);
    }
}

/**
 * quick_sort_hoare - Prepare the terrain for Quick Sort using the Hoare scheme
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    qs(array, 0, size - 1, size);
}
