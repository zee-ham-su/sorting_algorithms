#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


/**
 * get_max - Returns the maximum element from the array
 *
 * @array: The array to find the maximum element from
 * @size: The size of the array
 * Return: The maximum element
 */
int get_max(const int *array, size_t size)
{
int max = array[0];
size_t i = 0;
while (i < size)
{
if (array[i] > max)
max = array[i];
i++;
}
return (max);
}

/**
 * count_sort - Performs counting sort based on a
 * specific digit
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The exponent, 10^i, representing the digit's
 * place value
 */

void count_sort(int *array, size_t size, int exp)
{
int *output = malloc(size * sizeof(int));
int count[10] = {0};
size_t i;

if (!output)
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}

i = 0;
while (i < size)
{
count[(array[i] / exp) % 10]++;
i++;
}
printf("Before update count array: ");
print_array(count, 10);

for (i = 1; i < 10; i++)
count[i] += count[i - 1];
printf("After update count array: ");
print_array(count, 10); 
for (i = size - 1; i < SIZE_MAX; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
if (i == 0)
break;
count[(array[i] / exp) % 10]--;
}

printf("Intermediate sorted array: ");
print_array(output, size);
for (i = 0; i < size; i++)
{
*(array + i) = *(output + i);
}
free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * order using Radix sort
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
int max = get_max(array, size);
size_t exp;

exp = 1;
while (max / exp > 0)
{

printf("Sorting for exp = %lu\n", exp);
count_sort(array, size, exp);
print_array(array, size);
exp *= 10;
}

}
