#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heapify - Entry point
 * @array: array
 * @size: size
 * @index: index
 * @size_p: printsize
 * Return: Void
 */

void heapify(int *array, size_t size, int index, size_t size_p)
{
	int max = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int temp;

	if (left < (int)size && array[left] > array[max])
		max = left;

	if (right < (int)size && array[right] > array[max])
		max = right;

	if (max != index)
	{
		temp = array[index];
		array[index] = array[max];
		array[max] = temp;
		print_array(array, size_p);
		heapify(array, size, max, size_p);
	}
}

/**
 * heap_sort - Entry point
 * @array: array
 * @size: size
 * Return: Void
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = (int)size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, (size_t)i, 0, size);
	}
}
