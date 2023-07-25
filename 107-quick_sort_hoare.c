#include "sort.h"
#include <stdio.h>

/**
 * int_swap - Swaps two integers.
 * @array: array to be swapped
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void int_swap(int *array, ssize_t a, ssize_t b)
{
int tmp = array[a];
array[a] = array[b];
array[b] = tmp;
}

/**
 * hoare_partition - Partitions the array using the Hoare
 * partition scheme.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 *
 * Return: Index of the pivot element after partitioning.
 */
int hoare_part(int *array, int low, int high, int size)
{
int pivot = array[low + (high - low) / 2];
int i = low - 1;
int j = high + 1;

while (1)
{
while (array[++i] < pivot)
{
/* Find the element on the left to swap */
}

while (array[--j] > pivot)
{
/* Find the element on the right to swap */
}
if (i >= j)
{
return (j);
}
int_swap(array, i, j);
print_array(array, size);
}
}
  
/**
 * quick_sort_helper - Recursive helper function for Quick sort.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 * @size: array size
 */

void quick_sort_helper(int *array, ssize_t low, ssize_t high, int size)
{
int pivot_index = 0;
if (low < high)
{
pivot_index = hoare_part(array, low, high, size);
quick_sort_helper(array, low, pivot_index, size);
quick_sort_helper(array, pivot_index + 1, high, size);
}
}
/**
 * quick_sort_hoare - Sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * with the Hoare partition scheme.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_helper(array, 0, size - 1, size);
}
