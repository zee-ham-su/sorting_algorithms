#include "sort.h"
#include <stdio.h>


/**
 * _swap - swap two values.
 * @array: The array for swapping values.
 * @i: First index.
 * @j: Second index.
 */
void _swap(int *array, int i, int j)
{
int temp = array[i];
array[i] = array[j];
array[j] = temp;
}


/**
 * shell_sort - sort the array using Shell sort algorithm
 * @array: The array to be sorted.
 * @size: Size of the array.
 */

void shell_sort(int *array, size_t size)
{
size_t interval, i, j;

if (array == NULL || size < 2)
return;
for (interval = 1; interval < size / 3; interval = interval * 3 + 1)
;

while (interval > 0)
{
for (i = interval; i < size; i++)
{
for (j = i; j >= interval && array[j - interval] > array[j]; j -= interval)
_swap(array, j, j - interval);
}
interval /= 3;
print_array(array, size);
}
}
