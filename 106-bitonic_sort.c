#include "sort.h"
#include <stdio.h>


/**
 * custom_swap - change two values in ascending or descending order
 * @arr: array
 * @index1: index of the first item
 * @index2: index of the second item
 * @ascending: 1 for ascending order, 0 for descending order
 */

void custom_swap(int arr[], int index1, int index2, int ascending)
{
if (ascending == (arr[index1] > arr[index2]))
{
arr[index1] = arr[index1] ^ arr[index2];
arr[index2] = arr[index1] ^ arr[index2];
arr[index1] = arr[index1] ^ arr[index2];
}
}


/**
 * custom_merge - sort bitonic sequences recursively in both orders
 * @arr: array
 * @start: starting index of the subsequence
 * @size: number of elements in the subsequence
 * @ascending: 1 for ascending order, 0 for descending order
 */
void custom_merge(int arr[], int start, int size, int ascending)
{
int mid;
int i;
if (size > 1)
{
mid = size / 2;
i = start;
while (i < start + mid)
{
custom_swap(arr, i, i + mid, ascending);
i++;
}
custom_merge(arr, start, mid, ascending);
custom_merge(arr, start + mid, mid, ascending);
}

}

/**
 * custom_bitonicsort - bitonic sort algorithm implementation
 * @arr: array
 * @start: starting index of the subsequence
 * @size: number of elements in the subsequence
 * @ascending: 1 for ascending order, 0 for descending order
 * @array_size: array length
 */
void custom_bitonicsort(int arr[], int start, int size,
int ascending, int array_size)
{
int mid;

if (size > 1)
{
if (ascending >= 1)
{
printf("Merging [%i/%i] (UP):\n", size, array_size);
print_array(&arr[start], size);
}
else
{
printf("Merging [%i/%i] (DOWN):\n", size, array_size);
print_array(&arr[start], size);
}

mid = size / 2;
custom_bitonicsort(arr, start, mid, 1, array_size);
custom_bitonicsort(arr, start + mid, mid, 0, array_size);
custom_merge(arr, start, size, ascending);

if (ascending <= 0)
{
printf("Result [%i/%i] (DOWN):\n", size, array_size);
print_array(&arr[start], size);
}
if (ascending >= 1)
{
printf("Result [%i/%i] (UP):\n", size, array_size);
print_array(&arr[start], size);
}
}
}

/**
 * bitonic_sort - prepare the terrain for the custom bitonic
 * sort algorithm
 * @arr: array
 * @array_size: array length
 */
void bitonic_sort(int *arr, size_t array_size)
{
int ascending = 1;

if (arr == NULL || array_size < 2) return;
custom_bitonicsort(arr, 0, array_size, ascending, array_size);
}




