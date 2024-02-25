#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using Bubble sort algorithm
 * @array: Array to sort
 * @size: Size of the array to sort
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, passes;
	int temp, swap;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (passes = size - 1; passes > 0; passes--)
	{
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
		if (!swap)
			break;
	}
}
