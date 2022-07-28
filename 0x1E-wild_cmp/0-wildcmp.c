#include "holberton.h"
#include <stdio.h>
#include <string.h>

/**
 * wildcmp - check the code for Holberton School students.
 * @s1: string1
 * @s2: string2
 * Return: Always 0.
 */
int wildcmp(char *s1, char *s2)
{
	int i, j = 0;
	int top = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	for (i = 0; i <= len1; i++)
	{
		if (s2[j] == '*')
		{
			while (s2[j] == '*')
			{
				if (j == len2 - 1)
					return (1);
				j++;
			}
			top = i;
			while (i < len1)
			{
				if (s1[i] == s2[j])
				{
					if (top < i)
						top = i;
				}
				i++;
			}
			i = top;
		}
		if (s1[i] != s2[j])
			return (0);
		j++;
	}
	return (1);
}
