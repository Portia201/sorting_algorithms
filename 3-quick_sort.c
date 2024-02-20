#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: Array.
 * @item1: First array element.
 * @item2: Second array element.
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * lomuto_partition - Lomuto partition sorting scheme implementation.
 * @array: Array.
 * @first: First array element.
 * @last: Last array element.
 * @size: Size of the array.
 * Return: Position of the last element sorted.
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}

	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}

	return (current);
}

/**
 * quicksort - Quicksort algorithm implementation.
 * @array: Array.
 * @first: First array element.
 * @last: Last array element.
 * @size: Size of the array.
 */
void quicksort(int *array, ssize_t first, ssize_t last, size_t size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		quicksort(array, first, position - 1, size);
		quicksort(array, position + 1, last, size);
	}
}

/**
 * quick_sort - Prepares the terrain for the quicksort algorithm.
 * @array: Array.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
