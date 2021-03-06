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
	listint_t *temp;
	int loopNum = 0;
	int count = 0;
	int space = 0;
	int max = 2;

	if (list == NULL)
		return (0);
	temp = list;
	if (temp == NULL)
		return (0);
	loopNum = temp->n;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (loopNum == temp->n)
			count++;
		if (count > max)
			return (1);
		if (space > max)
			loopNum = temp->n;
		space++;
	}
	return (0);
}
