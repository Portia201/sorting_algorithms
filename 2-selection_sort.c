#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @size: Size of the array.
 * @array: Array of integers to be sorted.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_index;
    int swap;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[min_index] > array[j])
                min_index = j;
        }

        if (min_index != i)
        {
            swap = array[i];
            array[i] = array[min_index];
            array[min_index] = swap;

            print_array(array, size);
        }
    }
}
