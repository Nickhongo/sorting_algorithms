#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap_nodes(listint_t *a, listint_t *b);
listint_t *create_listint(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *left, int *right, size_t s_l, size_t s_r);
void swap(int *a, int *b);
void quick_sort(int *array, size_t size);
size_t lomuto_partition(int *array, size_t s, size_t lower_b, size_t upper_b);
void quick_sort_partition(int *array, size_t s, size_t lower_b, size_t upper_b);
void radix_sort(int *array, size_t size);
void radix_count_sort(int *array, size_t size, int pos);
int get_max(int *array, size_t size);

#endif /* SORT_H */
