#include "sort.h"


/**
 * radix_sort - Sorts an array using radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int pos, max;

	if (array == NULL || size < 2)
	{
		return;
	}

	max = get_max(array, size);
	for (pos = 1; max / pos; pos *= 10)
	{
		radix_count_sort(array, size, pos);
		print_array(array, size);
	}
}

/**
 * radix_count_sort - Performs a count sort on radix sort algorithm
 * @array: array to sort
 * @size: Size of the array
 * @pos: Place value of the digit in an integer
 *
 * Return: nothing
 */
void radix_count_sort(int *array, size_t size, int pos)
{
	int *count, i, k = 9, *array_cpy;

	array_cpy = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);
	for (i = 0; i <= k; i++)
		count[i] = 0;

	for (i = 0; i < (int) size; i++)
		count[(array[i] / pos) % 10]++;

	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
		array_cpy[--count[(array[i] / pos) % 10]] = array[i];

	for (i = 0; i < (int) size; i++)
		array[i] = array_cpy[i];

	free(count);
	free(array_cpy);
}

/**
 * get_max - Retrieves the largest integer from an array
 * @array: Array
 * @size: Size of the array
 *
 * Return: biggest integer
 */
int get_max(int *array, size_t size)
{
	int max, i;

	max = array[0];
	for (i = 1; i < (int) size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
