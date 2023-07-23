#include <stdio.h>
#include "sort.h"


/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
/**
 * heapify - Rearranges the array to satisfy the heap property.
 * @array: Pointer to the array.
 * @size: Size of the heap (not necessarily the whole array).
 * @base: Base index of the subarray to heapify.
 * @i: Index of the current root node.
 */
void heapify(int *array, size_t size, size_t base, size_t i)
{
size_t max_index = i;
size_t left_idx = 2 * i + 1;
size_t right_idx = 2 * i + 2;

if (left_idx < base && array[left_idx] > array[max_index])
max_index = left_idx;
if (right_idx < base && array[right_idx] > array[max_index])
max_index = right_idx;

if (!(max_index == i))
{
swap(array + i, array + max_index);
print_array(array, size);
heapify(array, size, base, max_index);
}
}



/**
 * heap_sort - Sorts an array of integers in ascending order
 * using Heap sort.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
int i;
if (array == NULL || size < 2)
{
return;
}
for (i = (size / 2) - 1; i >= 0; i--)
heapify(array, size, size, i);

i = size - 1;
while (i > 0)
{
swap(&array[0], &array[i]);
print_array(array, size);
heapify(array, size, i, 0);
i--;
}


}
