#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - check the code for Holberton School students.
 * @head: Head of linked list
 * @number: Given number
 * Return: Always 0.
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    listint_t *new_list = *head;

    if (head == NULL)
        return NULL;
    if (new_list == NULL)
        return NULL;
    if (new_node == NULL)
        return NULL;
    new_node->n = number;
    new_node->next = NULL;
    if (number <= new_list->n)
    {
        new_node->next = *head;
        *head = new_node;
        return (*head);
    }
    while(new_list->next != NULL)
    {
        if (number <= new_list->next->n)
        {
            new_node->next = new_list->next;
            new_list->next = new_node;
            return (*head);
        }
        new_list = new_list->next;
    }
    if (new_list->n <= number)
    {
        new_list->next = new_node;
    }
    return (*head);
}