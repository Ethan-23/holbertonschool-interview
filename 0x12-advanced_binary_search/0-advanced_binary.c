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
	int end = size;

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
	int next = size / 2 + start;

	if (size % 2 != 0)
		next = (size + 1) / 2 + start;
	printf("Searching in array: ");
	print_array(array, start, end);
	if (array[next] <= value)
	{
		start = next;
		size = end - start;
	}
	else
	{
		end = next;
		size = end - start;
	}
	if (size <= 2)
	{
		printf("Searching in array: ");
		print_array(array, start, end);
		if (array[start] == value)
		{
			return (start);
		}
		else if (array[end] == value)
		{
			return (end);
		}
		else
		{
			printf("Searching in array: ");
			print_array(array, start + 1, end);
		}
	}
	else
		return (find_value(array, start, end, value, size));
	return (-1);
}

/**
 * print_array - Entry point
 * @array: array
 * @start: start
 * @end: end
 * Return: Always EXIT_SUCCESS
 */
void print_array(int *array, int start, int end)
{
	int i;

	for (i = start; i < end; i++)
	{
		if (i < end - 1)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
}

