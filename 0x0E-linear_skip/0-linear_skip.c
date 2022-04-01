#include <stdio.h>
#include <stdlib.h>

#include "search.h"
/**
 * linear_skip - Entry point
 * @list: Pointer to linked list
 * @value: Target input value
 * Return: Always EXIT_SUCCESS
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skip = list;
	skiplist_t *prev = list;

	if (list == NULL)
		return (NULL);
	skip = skip->express;
	while (skip->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   skip->index, skip->n);
		if (skip->n >= value || skip->express == NULL)
		{
			if (skip->express == NULL && !(skip->n >= value))
			{
				prev = skip;
				while (skip->next)
					skip = skip->next;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
				   prev->index, skip->index);
			while (prev)
			{
				printf("Value checked at index [%lu] = [%d]\n",
					   prev->index, prev->n);
				if (prev->n == value)
					return (prev);
				prev = prev->next;
			}
		}
		else
		{
			prev = skip;
			skip = skip->express;
		}
	}
	return (NULL);
}
