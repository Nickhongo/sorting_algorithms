#include "sort.h"

/**
 * selection_sort - Sorts an array using Selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int i = 0, j, value, position;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (i < (int) size)
	{
		value = array[i];
		for (j = i + 1; j < (int) size; j++)
		{
			if (array[j] < value)
			{
				value = array[j];
				position = j;
			}
		}
		if (value != array[i])
		{
			temp = array[i];
			array[i] = value;
			array[position] = temp;
			print_array(array, size);
		}
		i++;
	}
}
