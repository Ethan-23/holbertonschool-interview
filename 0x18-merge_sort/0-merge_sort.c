#include "sort.h"

/**
 * merge - sorts the given array
 * @array_copy: Copy of Given array
 * @size: size of split arrays
 * @middle: middle of split
 * @array: given array
 * Return: void
 */

void merge(int *array_copy, int size, int middle, int *array)
{
	int i, j = middle, l = 0;

	for (i = 0; i < size; i++)
	{
		if (l < middle && (j >= size || array_copy[l] <= array_copy[j]))
			array[i] = array_copy[l], l++;
		else
			array[i] = array_copy[j], j++;
	}
}

/**
 * merge_split - sorts the given array
 * @array_copy: Copy of Given array
 * @size: size of split arrays
 * @array: Given array
 * Return: void
 */

void merge_split(int *array_copy, int size, int *array)
{
	int middle = size / 2;

	if (size <= 1)
		return;

	merge_split(array, middle, array_copy);
	merge_split((array + middle), size - middle, (array_copy + middle));

	printf("Merging...\n[left]: ");
	print_array(array_copy, middle);
	printf("[right]: ");
	print_array((array_copy + middle), size - middle);

	merge(array_copy, size, middle, array);

	printf("[Done]: ");
	print_array(array, size);
}


/**
 * merge_sort - sorts the given array
 * @array: Given array
 * @size: size of split arrays
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int i, *array_copy;

	array_copy = malloc(sizeof(int) * size);
	for (i = 0; i < (int)size; i++)
		array_copy[i] = array[i];
	merge_split(array_copy, (int)size, array);
	free(array_copy);
}
