#include <stdio.h>
#include <string.h>

#include "regex.h"

/**
 * checker - checks to see if the given string is
 * in the given pattern at the given index.
 * @str: given string
 * @pattern: given pattern
 * @index: given index to start with
 * Return: 1 for same 0 for different.
 */

int checker(char const *str, char const *pattern, int index)
{
	int len1 = strlen(str);
	int i = 0;

	for (i = 0; i < len1; i++)
	{
		if (str[i] != pattern[index] && pattern[index]
			!= '.' && pattern[index] != '*')
			return (0);
		while (pattern[index] == '*')
		{
			if (len1 - 1 == i || pattern[index + 1] == str[i])
			{
				i--;
				break;
			}
			i++;
		}
		index++;
	}
	if (i != len1)
		return (0);
	return (1);
}

/**
 * regex_match - Checks if pattern is in given string.
 * @str: given string
 * @pattern: give pattern to look for
 * Return: 1 for found pattern 0 for different.
 */
int regex_match(char const *str, char const *pattern)
{
	int len1 = strlen(str);
	int len2 = strlen(pattern);
	int i = 0;

	if (len1 == '\0' && len2 == '\0')
		return (1);
	for (i = 0; i < len1; i++)
	{
		if (i == len2 - 1 && pattern[i] == '*')
			return (1);
		if (checker(str, pattern, i) == 1)
			return (1);
	}
	return (0);
}
