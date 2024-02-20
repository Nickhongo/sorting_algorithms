#include "sort.h"

/**
 * shell_sort - Sorts an array using Shell sort algorithm - Knuth Sequence
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int gap, i = 0, j = 0, knuth = 0;
	int temp1, temp2;

	if (size < 2)
	{
		return;
	}
	gap = 1;
	while ((gap = (gap * 3) + 1) < (int) size)
		knuth += 1;

	for (gap = (knuth * 3) + 1; gap > 0; gap = (gap - 1) / 3)
	{
		for (j = gap; j < (int) size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				temp1 = array[i];
				temp2 = array[i + gap];
				if (temp2 > temp1)
					break;
				array[i] = temp2;
				array[i + gap] = temp1;
			}
		}
		print_array(array, size);
	}
}
