#include "sort.h"

/**
 * swap_indexes - swap the values at two indexes
 * @a: the first index to be swapped
 * @b: the second index to be swapped
 *
 * Return: nothing
 */
void swap_indexes(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - partitions the array
 * @array: the array to be sorted
 * @lo: the lower bound of the array
 * @hi: the upper bound of the array
 * @size: number of elements that the array has
 *
 * Return: the index of the pivot
 */
int partition(int *array, int lo, int hi, int size)
{
	int pivot = array[hi], j = lo - 1;
	int i = 0;

	for (i = lo; i < hi; i++)
	{
		if (array[i] <= pivot)
		{
			j++;
			if (j != i)
			{
				swap_indexes(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (pivot < array[j + 1])
	{
		swap_indexes(&array[hi], &array[j + 1]);
		print_array(array, size);
	}
	return (j + 1);
}

/**
 * sorter - quick sort function
 * @array: the array to be sorted
 * @lo: the lower bound of the array
 * @hi: the upper bound of the array
 * @size: number of elements that the array has
 */
void sorter(int *array, int lo, int hi, size_t size)
{
	size_t p = 0;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		if (p > 0)
			sorter(array, lo, p - 1, size);
		if (p != size)
			sorter(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - a function that sorts an array by quick sort
 * @array: the array to be sorted
 * @size: number of elements that the array has
 */
void quick_sort(int *array, size_t size)
{
	int lo = 0, hi = size - 1;

	if (!array || size == 0)
		return;

	sorter(array, lo, hi, size);
}
