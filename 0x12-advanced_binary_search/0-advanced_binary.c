#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - Entry point
 * @array: array
 * @value: value
 * @size: size
 * Return: Always EXIT_SUCCESS
 */
int advanced_binary(int *array, size_t size, int value)
{
	int start = 0;
	int end = size - 1;

	if (!array)
		return (-1);

	return (find_value(array, start, end, value, size));
}


/**
 * find_value - Entry point
 * @array: array
 * @start: start
 * @end: end
 * @value: value
 * @size: size
 * Return: Always EXIT_SUCCESS
 */
int find_value(int *array, int start, int end, int value, size_t size)
{
	int next;

	print_array(array, start, size);
	if (size > 2)
	{
		next = size / 2 + start;
		if (size % 2 != 0)
			next = (size + 1) / 2 + start;
		if (array[next] <= value)
		{
			start = next;
			size = end - start + 1;
		}
		else
		{
			end = next - 1;
			size = end - start + 1;
		}
		return (find_value(array, start, end, value, size));
	}
	if (array[start] == value)
		return (start);
	else if (array[end] == value)
		return (end);
	print_array(array, start + 1, size - 1);
	return (-1);
}

/**
 * print_array - Entry point
 * @array: array
 * @start: start
 * @size: end
 * Return: Always EXIT_SUCCESS
 */
void print_array(int *array, int start, int size)
{
	int i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i < size - 1)
			printf("%d, ", array[start + i]);
		else
			printf("%d\n", array[start + i]);
	}
}

