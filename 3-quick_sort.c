#include "sort.h"


/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 */
void swap_items(int *array, size_t l, size_t r)
{
int tmp;

if (array != NULL)
{
tmp = array[l];
array[l] = array[r];
array[r] = tmp;
}
}

/**
 * lomuto_partition - Partitions the array using Lomuto's scheme.
 * @array: The array to be partitioned.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 * Return: The index of the pivot element after partitioning.
 */

size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
int pivot = array[high];
size_t i = low - 1;
size_t j;

for (j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
swap_items(array, i, j);
print_array(array, size);
}
}
}

if ((i + 1) != high)
{
swap_items(array, i + 1, high);
print_array(array, size);
}

return (i + 1);
}

/**
 * quick_sort_lomuto - Sorts a sub array using the
 * quick sort algorithm and Lomuto's partition scheme.
 * @array: The array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 */

void quick_sort_lomuto(int *array, size_t low, size_t high, size_t size)
{
size_t pivot_idx;
if (low < high)
{
pivot_idx = lomuto_partition(array, low, high, size);

if (pivot_idx > 0)
quick_sort_lomuto(array, low, pivot_idx - 1, size);
quick_sort_lomuto(array, pivot_idx + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 * and Lomuto's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 */

void quick_sort(int *array, size_t size)
{
if (array != NULL && size > 1)
{
quick_sort_lomuto(array, 0, size - 1, size);
}
}
