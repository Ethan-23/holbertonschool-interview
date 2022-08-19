#include <stdlib.h>
#include <stdio.h>

#include "substring.h"

/**
 * find_substring - Finds sub string
 * @s: is the string to scan
 * @words: array of words all substrings
 * @nb_words: number of elements in the array words
 * @n: address at which to store the number of elements
 * Return: 1 for found pattern 0 for different.
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int l = strlen(s);

	if (s == NULL || words == NULL || nb_words == NULL || n == NULL || l == 0)
		return (NULL);
	return (NULL);
}
