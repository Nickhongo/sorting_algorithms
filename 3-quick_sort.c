#include "sort.h"

/**
 * quick_sort - Sorts an array using quick sort algorithm (Lomuto partition)
 * @array: Array to be sorted
 * @size: Size of the array to be sorted
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	size_t lb, ub;

	if (array == NULL || size < 2)
	{
		return;
	}
	lb = 0;
	ub = size - 1;
	quick_sort_partition(array, size, lb, ub);
}

/**
 * swap - Swaps two elements
 * @a: Pointer to first element
 * @b: Pointer to second element
 *
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Creates Lomuto partitions
 * @array: Array to be sorted
 * @s: Size of the array
 * @lower_b: Lower bound of the partition
 * @upper_b: Upper bound of the partition
 *
 * Return: Correct position of the pivot element in the array
 */
size_t lomuto_partition(int *array, size_t s, size_t lower_b, size_t upper_b)
{
	int pivot, i, j;

	pivot = array[upper_b];
	i = (int) lower_b - 1;

	for (j = (int) lower_b; j <= (int) upper_b - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[upper_b]);
	print_array(array, s);
	return ((size_t) i + 1);
}


/**
 * quick_sort_partition - Sorts an array using Lomuto partitions
 * @array: Array to be sorted
 * @s: Size of the array
 * @lower_b: Lower bound of the partition
 * @upper_b: Upper bound of the partition
 *
 * Return: nothing
 */
void quick_sort_partition(int *array, size_t s, size_t lower_b, size_t upper_b)
{
	size_t pos;

	if (lower_b < upper_b)
	{
		pos = lomuto_partition(array, s, lower_b, upper_b);
		quick_sort_partition(array, s, lower_b, pos - 1);
		quick_sort_partition(array, s, pos + 1, upper_b);
	}
}
