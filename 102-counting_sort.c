#include "sort.h"

/**
 * counting_sort - Sorts an array using Counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int k, i, *array_cpy, *count, counter = 0;

	if (size < 2)
	{
		return;
	}
	k = array[0];
	for (i = 1; i < (int) size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	array_cpy = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * (k + 1));

	for (i = 0; i <= k; i++)
		count[i] = 0;

	/* Count the number of distinct key values and store in count array */
	for (i = 0; i < (int) size; i++)
		count[array[i]] += 1;

	/* Update count array */
	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];

	print_array(count, k + 1);

	/* Loop backward to update array copy with sorted elements */
	for (i = size - 1; i >= 0; i--)
	{
		counter = array[i];
		count[counter] = count[counter] - 1;
		array_cpy[count[counter]] = counter;
	}
	for (i = 0; i < (int) size; i++)
		array[i] = array_cpy[i];
	free(count);
	free(array_cpy);
}
