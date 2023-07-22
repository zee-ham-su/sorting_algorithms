#include "sort.h"

/**
 * counting_sort - sorts integers arrays in ascending
 * order with the use of the Counting sort algorithm
 * @array: pointer to array
 * @size: array size
 **/

void counting_sort(int *array, size_t size)
{
int max_value, i, *count_array, *sorted_array;
size_t j;

if (array == NULL || size < 2)
return;

max_value = array[0];
for (j = 0; j < size; j++)
{
max_value = (array[j] > max_value) ? array[j] : max_value;
}
count_array = calloc((max_value + 1), sizeof(int));
for (j = 0; j < size; j++)
{
count_array[array[j]]++;
}
for (i = 1; i <= max_value; i++)
{
count_array[i] += count_array[i - 1];
}
print_array(count_array, max_value + 1);
sorted_array = malloc(sizeof(int) * size);
for (j = 0; j < size; j++)
{
count_array[array[j]]--;
sorted_array[count_array[array[j]]] = array[j];
}

for (j = 0; j < size; j++)
{
array[j] = sorted_array[j];
}

free(sorted_array);
free(count_array);
}
