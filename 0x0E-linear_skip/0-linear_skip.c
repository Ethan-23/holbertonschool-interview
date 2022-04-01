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
	skiplist_t *temp;

	if (list == NULL)
		return (NULL);
	skip = skip->express;
	while (skip)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   skip->index, skip->n);
		if (skip->n > value || skip->express == NULL)
		{
			if (skip->express == NULL)
			{
				temp = skip;
				while (skip->next)
				{
					skip = skip->next;
					if (skip->n > value)
					{
						skip = temp;
						break;
					}
				}
				if (prev->express->index < skip->index)
					prev = prev->express;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
				   prev->index, skip->index);
			while (prev->n != value)
			{
				printf("Value checked at index [%lu] = [%d]\n",
					   prev->index, prev->n);
				if (prev->next == NULL)
					return (NULL);
				prev = prev->next;
			}
			printf("Value checked at index [%lu] = [%d]\n",
					prev->index, prev->n);
			return (prev);
		}
		else if (skip->n < value)
		{
			prev = skip;
			skip = skip->express;
		}
	}
	return (NULL);
}