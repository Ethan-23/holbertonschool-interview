#include "list.h"

/**
 * letter_count - counts chars in given word
 * @word: given word to count letters
 * Return: number of chars
 */
unsigned long int letter_count(char *word)
{
	unsigned long int i = 0;

	for (i = 0; word[i]; i++)
		continue;
	return (i);
}

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str:  the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *temp_node = NULL;
	unsigned long int i = 0;

	if (list == NULL)
		return (NULL);

	temp_node = malloc(sizeof(List *));

	if (temp_node == NULL)
		return (NULL);

	temp_node->str = malloc(sizeof(char) * letter_count(str) + 1);

	if (temp_node->str == NULL)
	{
		free(temp_node);
		return (NULL);
	}

	for (i = 0; i < letter_count(str) + 1; i++)
		temp_node->str[i] = str[i];

	temp_node->str[i] = '\0';

	if ((*list) == NULL)
	{
		temp_node->prev = temp_node;
		temp_node->next = temp_node;
		(*list) = temp_node;
	}
	else
	{
		temp_node->prev = (*list)->prev;
		(*list)->prev->next = temp_node;
		(*list)->prev = temp_node;
		temp_node->next = (*list);
	}

	return (temp_node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double
 *  circular linked list
 * @list: the list to modify
 * @str:  the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *temp_node = NULL;
	unsigned long int i = 0;

	if (list == NULL)
		return (NULL);

	temp_node = malloc(sizeof(List *));

	if (temp_node == NULL)
		return (NULL);

	temp_node->str = malloc(sizeof(char) * letter_count(str) + 1);

	if (temp_node->str == NULL)
	{
		free(temp_node);
		return (NULL);
	}

	for (i = 0; i < letter_count(str) + 1; i++)
		temp_node->str[i] = str[i];

	temp_node->str[i] = '\0';

	if ((*list) == NULL)
	{
		temp_node->prev = temp_node;
		temp_node->next = temp_node;
	}
	else
	{
		temp_node->prev = (*list)->prev;
		(*list)->prev->next = temp_node;
		(*list)->prev = temp_node;
		temp_node->next = (*list);
	}
	(*list) = temp_node;
	return (temp_node);
}
