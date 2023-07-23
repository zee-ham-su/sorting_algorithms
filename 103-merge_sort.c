#include "sort.h"
#include <stdio.h>

/**
 * merge_subarray - Merge and sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to temporarily store the sorted subarray.
 * @start: The starting index of the subarray.
 * @middle: The middle index of the subarray.
 * @end: The ending index of the subarray.
 */

void merge_subarray(int *subarray, int *buffer, size_t start,
		  size_t middle, size_t end)
{
size_t left_idx, right_idx, merge_idx;

printf("Merging...\n[left]: ");
print_array(subarray + start, middle - start);

printf("[right]: ");
print_array(subarray + middle, end - middle);

for (left_idx = start, right_idx = middle, merge_idx = 0; left_idx <
middle && right_idx < end; merge_idx++)
{
if (subarray[left_idx] < subarray[right_idx])
buffer[merge_idx] = subarray[left_idx++];
else
buffer[merge_idx] = subarray[right_idx++];
}

while (left_idx < middle)
buffer[merge_idx++] = subarray[left_idx++];

while (right_idx < end)
buffer[merge_idx++] = subarray[right_idx++];

for (left_idx = start, merge_idx = 0; left_idx < end; left_idx++)
subarray[left_idx] = buffer[merge_idx++];

printf("[Done]: ");
print_array(subarray + start, end - start);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @start: The front index of the subarray.
 * @end: The back index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buffer, size_t start, size_t end)
{
size_t middle;

if (start < end - 1)
{
middle = start + (end - start) / 2;
merge_sort_recursive(subarray, buffer, start, middle);
merge_sort_recursive(subarray, buffer, middle, end);
merge_subarray(subarray, buffer, start, middle, end);
}
}


/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the Merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 **/

void merge_sort(int *array, size_t size)
{
int *buffer = NULL;

if (!array || size < 2)
return;

buffer = calloc(size, sizeof(int));
if (!buffer)
return;
merge_sort_recursive(array, buffer, 0, size);
free(buffer);
}
