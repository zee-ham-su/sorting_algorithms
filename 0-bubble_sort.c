#include <stdbool.h>
#include <stdio.h>
#include "sort.h"


/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_ints(int *a, int *b)
{
int tmp;
tmp = *a;
*a = *b;
*b = tmp;
}


/**
 * bubble_sort - Sorts an integer array in ascending order using
 * the Bubble sort algorithm
 * @array: Integer array
 * @size: Number of elements in the array
 *
 * Return: None
 */

void bubble_sort(int *array, size_t size)
{
size_t i, len = size;
size_t new_len = 0;
if (array == NULL || size < 2)
return;
while (len > 1)
{
for (i = 0; i < len - 1; i++)
{
if (array[i] > array[i + 1])
{
swap_ints(array + i, array + i + 1);
print_array(array, size);
new_len = i + 1;
}
}
len = new_len;
}
}
