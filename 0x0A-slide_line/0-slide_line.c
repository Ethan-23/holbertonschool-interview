#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

#define LINE_SIZE 32
/**
 * right - Prints out an array of integer, followed by a new line
 *
 * @line: Pointer to the array of integers being input
 * @size: Number of elements in @line
 * @direction: direction that the numbers move in (1 = left, 2 = right)
 */
void right(int *line, size_t size)
{
	long int check = 0;
	long int temp = 0;
	long int hold = size;
	long int i = 0;
	long int j = 0;

	for (check = 0; check <= hold - 2; check++)
	{
		for (temp = check + 1; temp <= hold - 1; temp++)
		{
			if (line[check] == line[temp])
			{
				line[temp] = 0;
				line[check] = line[check] * 2;
				break;
			}
		}
	}
	for (i = 0; i < hold - 1; i++)
	{
		j = i;
		while (line[i] == 0)
		{
			if (j <= hold - 1 && line[j] > 0)
			{
				line[i] = line[j];
				line[j] = 0;
			}
			if (j > hold - 1)
				break;
			j++;
		}
	}
}

/**
 * left - Prints out an array of integer, followed by a new line
 *
 * @line: Pointer to the array of integers being input
 * @size: Number of elements in @line
 * @direction: direction that the numbers move in (1 = left, 2 = right)
 */
void left(int *line, size_t size)
{
	long int check = 0;
	long int temp = 0;
	long int hold = size;
	long int i = 0;
	long int j = 0;

	for (check = size - 1; check >= 0; check--)
	{
		for (temp = check - 1; temp >= 0; temp--)
		{
			if (line[check] == line[temp])
			{
				line[temp] = 0;
				line[check] = line[check] * 2;
				break;
			}
		}
	}
	for (i = hold - 1; i >= 0; i--)
	{
		j = i;
		while (line[i] == 0)
		{
			if (j >= 0 && line[j] > 0)
			{
				line[i] = line[j];
				line[j] = 0;
			}
			if (j < 0)
				break;
			j--;
		}
	}
}
/**
 * slide_line - Prints out an array of integer, followed by a new line
 *
 * @line: Pointer to the array of integers being input
 * @size: Number of elements in @line
 * @direction: direction that the numbers move in (1 = left, 2 = right)
 * Return: valid = 1 invalid = 0
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == 1)
		right(line, size);
	else if (direction == 2)
		left(line, size);
	else
		return (0);
	return (1);
}
