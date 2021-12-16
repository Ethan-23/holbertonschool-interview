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

    if (new_node == NULL || new_list == NULL)
        return NULL
    new_node->n = number;
    while(new_list->next != NULL)
    {
        new_list = new_list->next;
        if (number <= new_list->next->n)
        {
            new_node->next = new_list->next;
            new_list->next = new_node;
            break;
        }
    }
    return (*head);
}