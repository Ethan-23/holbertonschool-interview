#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Entry point
 * @array: given array
 * @size: - size of given array
 * Return: Always 0
 */
int getMax(int *array, size_t size)
{
	int i, max = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * sort - Entry point
 * @array: given array
 * @size: - size of given array
 * @exp: given exponent
 * Return: Always 0
 */
void sort(int *array, int size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int i, count[10] = { 0 };

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - Entry point
 * @array: given array
 * @size: - size of given array
 * Return: Always 0
 */
void radix_sort(int *array, size_t size)
{
	int exp = 1;
	int max = getMax(array, (int)size);

	if (size < 2)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		sort(array, size, exp);
		print_array(array, size);
	}

}
