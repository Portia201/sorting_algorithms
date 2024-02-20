#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: Array.
 * @item1: First array element.
 * @item2: Second array element.
 */
void swap(int *array, int item1, int item2)
{
	int tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
* shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with the Knuth sequence.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap using the Knuth sequence */
	while (gap < size / 3)
		gap = 3 * gap + 1;
	
	/* Start the sorting process with the calculated gap */
	while (gap >= 1)
	{
		/* Perform insertion sort for each gap */
		for (i = gap; i < size; i++)
		{
			/* Insertion sort within the gap */
			for (index = i; index >= gap && array[index] < array[index - gap]; index -= gap)
			{
				swap(array, index, index - gap);
				print_array(array, size);
			}
		}
		/* Reduce the gap according to the Knuth sequence */
		gap /= 3;
	}
}
