#include "sort.h"
#include <stdio.h>

/**
 * getMax - A utility function to get the maximum value in an array
 * @arr: array
 * @n: size of the array
 * Return: maximum value
 */
int getMax(int *arr, int n)
{
    int i, max_value = arr[0];

    for (i = 1; i < n; i++)
        if (arr[i] > max_value)
            max_value = arr[i];
    return max_value;
}

/**
 * countSort - A function to perform counting sort of arr[] according to
 * the digit represented by exp.
 * @arr: array
 * @n: size of the array
 * @exp: the exponent, representing the current digit place
 * @output: array to store temporary values
 */
void countSort(int *arr, size_t n, int exp, int *output)
{
    int i;
    int count[10] = {0};

    /* Store count of occurrences in count[] */
    for (i = 0; i < (int)n; i++)
        count[(arr[i] / exp) % 10]++;

    /* Change count[i] so that count[i] now contains the actual position of this digit in output[] */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    /* Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit */
    for (i = 0; i < (int)n; i++)
        arr[i] = output[i];
}

/**
 * radix_sort - The main function to sort an array of integers using Radix Sort
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
    int exp, max_value = 0;
    int *output_array = NULL;

    if (array == NULL || size < 2)
        return;

    max_value = getMax(array, size);
    output_array = malloc(size * sizeof(int));
    if (output_array == NULL)
        return;

    /* Perform counting sort for every digit place */
    for (exp = 1; max_value / exp > 0; exp *= 10)
    {
        countSort(array, size, exp, output_array);
        print_array(array, size);
    }

    free(output_array);
}
