#include "sort.h"

/**
 * merge_sort - Sorts an array using merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int i, j = 0, mid, *left, *right;
	size_t size_l, size_r;

	if (array == NULL || size <= 1)
	{
		return;
	}
	mid = (int) size / 2;
	size_l = size / 2;
	left = malloc(sizeof(int) * (size_l));
	if (size % 2)
		size_r = (size / 2) + 1;
	else
		size_r = (size / 2);
	right = malloc(sizeof(int) * (size_r));

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < (int) size; i++)
	{
		right[j++] = array[i];
	}
	merge_sort(left, size_l);
	merge_sort(right, size_r);

	merge(array, left, right, size_l, size_r);
	printf("[Done]: ");
	print_array(array, size);
	free(left);
	free(right);
}

/**
 * merge - merge sorted arrays
 * @array: Array to be merged after splitting and sorting
 * @left: first half of elements in the array
 * @right: last half of elements in the array
 * @s_l: Size of the left array
 * @s_r: Size of the right array
 *
 * Return: nothing
 */
void merge(int *array, int *left, int *right, size_t s_l, size_t s_r)
{
	int a = 0, b = 0, c = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, s_l);
	printf("[right]: ");
	print_array(right, s_r);

	while (a < (int) s_l && b < (int) s_r)
	{
		if (left[a] <= right[b])
		{
			array[c] = left[a];
			a++;
		}
		else
		{
			array[c] = right[b];
			b++;
		}
		c++;
	}

	while (a < (int) s_l)
	{
		array[c] = left[a];
		a++;
		c++;
	}
	while (b < (int) s_r)
	{
		array[c] = right[b];
		b++;
		c++;
	}
}
