#ifndef SORT_H
#define SORT_H


#include <stddef.h>
#include <stdlib.h>


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

/* Print Functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/* mandatory Sorting Algorithms Functions */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_items(int *array, size_t l, size_t r);
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size);
void quick_sort_lomuto(int *array, size_t low, size_t high, size_t size);


/* advanced tasks sorting algorithm functions */
void shell_sort(int *array, size_t size);
void _swap(int *array, int i, int j);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void merge_sort(int *array, size_t size);
void merge(int *arr, int *buff, size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *arr, int *buff, size_t front, size_t back);
void print_subarray(int *array, size_t start, size_t end);
void heapify(int *array, size_t size, size_t base, size_t i);
void swap(int *a, int *b);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
int get_max(const int *array, size_t size);




/*Check if USE_PREVIOUS_COUNTING_SORT is defined */
#ifdef USE_PREVIOUS_COUNTING_SORT
void counting_sort(int *array, size_t size);
#else
void counting_sort(int *array, size_t size, int exp);
#endif




#endif /* SORT_H */
