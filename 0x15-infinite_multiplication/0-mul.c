#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"

/**
 * print_sum - prints sum
 * @sum: array of sum
 * @length: length of sum array
 */

void print_sum(int *sum, int length)
{
	int i, j = 0;

	for (i = 0; i < length - 1; i++)
	{
		if (sum[i] != 0)
		{
			j = 1;
			break;
		}
	}
	for (; i < length; i++)
		_putchar(sum[i] + '0');
	if (j == 0)
		_putchar('0');
	_putchar('\n');
}

/**
 * more_mult - multiplication process
 * @num1: first input number
 * @len1: length of input number
 * @num2int: single number from num2
 * @sum: sum array to fill
 * @length: length of sum array
 * Return: list of zeros
 */

int *more_mult(int *num1, int len1, int num2int, int *sum, int length)
{
	int i, j;

	j = length - 1;
	for (i = len1 - 1; i >= 0; i--)
	{
		sum[j] += num1[i] * num2int;
		j--;
	}
	for (i = length - 1; i > 0; i--)
	{
		if (sum[i] > 9)
		{
			sum[i - 1] += sum[i] / 10;
			sum[i] = sum[i] % 10;
		}
	}
	return (sum);
}

/**
 * mult - multiplication process
 * @num1: first input number
 * @num2: second input number
 * @len1: length of num1
 * @len2: length of num2
 * Return: list after mult
 */

int *mult(int *num1, int *num2, int len1, int len2)
{
	int *sum, *zeros, length, i, j = 0;

	length = (len1 + len2) * 1.5;

	zeros = malloc(length * sizeof(int));
	if (!zeros)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 0; i < length; i++)
		zeros[i] = 0;

	sum = zeros;

	for (i = len2 - 1; i >= 0; i--)
	{
		sum = more_mult(num1, len1, num2[i], sum, length - j);
		j++;
	}
	return (sum);
}

/**
 * strarr - multiplication process
 * @length: length of given string
 * @num: given string to convert
 * Return: array from string: list after mult
 */

int *strarr(int length, char *num)
{
	int *newnum, i;

	newnum = malloc(length * sizeof(int));
	if (!newnum)
	{
		printf("Error\n");
		exit(98);
	}
	i = length - 1;
	while (i >= 0)
	{
		if (num[i] < '0' || num[i] > '9')
		{
			free(newnum);
			printf("Error\n");
			exit(98);
		}
		else
		{
			newnum[i] = num[i] - 48;
		}
		i--;
	}
	return (newnum);
}

/**
 * main - main
 * @argc: number of input words
 * @argv: list of input words
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int *num1, *num2, *sum;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	if (!atoi(argv[1]) || !atoi(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}
	if (strchr(argv[1], '.') || strchr(argv[2], '.'))
	{
		printf("Error\n");
		exit(98);
	}

	num1 = strarr(strlen(argv[1]), argv[1]);
	num2 = strarr(strlen(argv[2]), argv[2]);
	sum = mult(num1, num2, strlen(argv[1]), strlen(argv[2]));

	print_sum(sum, (strlen(argv[1]) + strlen(argv[2])) * 1.5);
	free(num1);
	free(num2);
	free(sum);
	exit(0);
	return (0);
}
