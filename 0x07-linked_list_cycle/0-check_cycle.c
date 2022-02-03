#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if list has a cycle in it
 * @list: pointer to head of list
 * Return: number of nodes
 */

int check_cycle(listint_t *list)
{
	listint_t *temp = list;
	int loopNum = temp->n;
	int count = 0;

	while (temp->next != NULL)
	{
		temp = temp->next;
		if (loopNum == temp->n)
			count++;
		if (count > 5)
			return (1);
	}
	return (0);
}
