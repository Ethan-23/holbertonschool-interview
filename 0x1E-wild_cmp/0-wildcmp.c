#include "holberton.h"
#include <stdio.h>
#include <string.h>

/**
 * passastr - check the code for Holberton School students.
 * @string: give string
 * @index: index to start at
 * Return: index of char after last *.
 */
int passastr(char *string, int index)
{
	int len = strlen(string);

	if (index < len - 1 && string[index] == '*')
		return (passastr(string, index + 1));
	return (index);
}

/**
 * checktopletter - check the code for Holberton School students.
 * @string: given string
 * @index: starting index for string
 * @letter: letter to check
 * @top: top index of given letter
 * Return: highest index of letter.
 */
int checktopletter(char *string, int index, char letter, int top)
{
	int len = strlen(string);

	if (string[index] == letter)
		top = index;
	if (index == len - 1)
		return (top);
	return (checktopletter(string, index + 1, letter, top));
}

/**
 * compare_string - check the code for Holberton School students.
 * @s1: string1
 * @s2: string2
 * @i: s1 index
 * @j: s2 index
 * Return: Always 1 for same 0 for not.
 */
int compare_string(char *s1, char *s2, int i, int j)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if (s2[j] == '*')
	{
		if (len2 - 1 != j)
			j = passastr(s2, j);

		if (j == len2 - 1 && s2[j] == '*')
			return (1);
		if (i < len1 - 1)
			i = checktopletter(s1, i, s2[j], i);
	}

	if (s1[i] != s2[j])
		return (0);

	if (i < len1 - 1)
		return (compare_string(s1, s2, i + 1, j + 1));

	if (j < len2 - 1 && s2[passastr(s2, j + 1)] != '*')
		return (0);

	return (1);
}

/**
 * wildcmp - check the code for Holberton School students.
 * @s1: string1
 * @s2: string2
 * Return: 1 for same 0 for different.
 */
int wildcmp(char *s1, char *s2)
{
	int result = compare_string(s1, s2, 0, 0);

	return (result);
}
