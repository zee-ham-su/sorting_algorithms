#include <stdio.h>
#include <stdlib.h>

/**
 * print_subarray - prints array ina  a range
 * @array: data array
 * @start: start of range
 * @end: end of range
 * Return: None
 */

void print_subarray(int *array, size_t start, size_t end)
{
size_t i;
printf("[left]: ");
for (i = start; i < end; i++)
{
printf("%d", array[i]);
if (i != end - 1)
printf(", ");
}
printf("\n");
}


/**
 * merge - Merges two sorted sub-arrays into a single
 * sorted array.
 * @array: Pointer to the original array.
 * @left: Pointer to the left sub-array.
 * @left_size: Size of the left sub-array.
 * @right: Pointer to the right sub-array.
 * @right_size: Size of the right sub-array.
 **/

void merge(int *array, int *left, size_t left_size,
	   int *right, size_t right_size)
{
size_t i, j, k;
int *tmp = malloc(sizeof(int) * (left_size + right_size));

if (!tmp)
return;

i = j = k = 0;
while (i < left_size && j < right_size)
{
if (left[i] <= right[j])
{
tmp[k] = left[i];
i++;
}
else
{
tmp[k] = right[j];
j++;
}
k++;
}

while (i < left_size)
{
tmp[k] = left[i];
i++;
k++;
}

while (j < right_size)
{
tmp[k] = right[j];
j++;
k++;
}
for (i = 0; i < (left_size + right_size); i++)
array[i] = tmp[i];
free(tmp);
}


/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the Merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 **/

void merge_sort(int *array, size_t size)
{
size_t middle = size / 2;
int *left = array;
int *right = array + middle;
size_t i;

if (size < 2)
return;

merge_sort(left, middle);
merge_sort(right, size - middle);

merge(array, left, middle, right, size - middle);

printf("Merging...\n");
print_subarray(left, 0, middle);
print_subarray(right, 0, size - middle);

merge(array, left, middle, right, size - middle);
printf("[Done]: ");
for (i = 0; i < size; i++)
{
printf("%d", array[i]);
if (i != size - 1)
printf(", ");
}
printf("\n");
}




