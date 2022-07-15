#include "sort.h"

/**
* selection_sort - sort an array in ascending order
* @array: array of integers
* @size: size of array
* Return: Nothing
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
