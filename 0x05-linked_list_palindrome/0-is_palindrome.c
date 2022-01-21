#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - desides if list is a palindrome
 * @head: pointer to head of list
 * Return: 1/0 for palindrome or not
 */
int is_palindrome(listint_t **head)
{
	listint_t *temp = *head;
	int len = 0;
	int *list = NULL;

	if (head == NULL || (*head) == NULL)
		return (1);

	while (temp != NULL)
	{
	temp = temp->next;
	len += 1;
	}

	list = malloc(sizeof(int) * len + 1);
	if (list == NULL)
	return (0);

	temp = *head;

	while (temp != NULL)
	{
	list[len - 1] = temp->n;
	temp = temp->next;
	len -= 1;
	}

	temp = *head;

	while (temp != NULL)
	{
	if (temp->n != list[len])
	{
	free(list);
	return (0);
	}
	temp = temp->next;
	len++;
	}
	free(list);
	return (1);
}
