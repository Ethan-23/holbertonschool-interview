#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - checks of input is a palindrome
 * @n: unsigned long int input
 * Return: 1 = true | 0 = false
 */
int is_palindrome(unsigned long n)
{
	char buffer[100];
	int i = 0;
	int count = 0;

	snprintf(buffer, 100, "%lu", n);
	for (i = 0; buffer[i] != '\0'; i++)
		count++;
	for (i = 0; buffer[i] != '\0'; i++)
		if (buffer[i] == buffer[count - 1])
			count--;
		else
			return (0);
	return (1);
}
