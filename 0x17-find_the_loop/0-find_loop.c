#include "lists.h"
#include <stdio.h>
/**
 * find_listint_loop - check the code for Holberton School students.
 * @head: head of given linked list
 * Return: Address of looped link.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *one = head, *two = head;

    if(head == NULL || head->next == NULL)
        return(NULL);
    while(one->next != NULL && two->next->next != NULL)
    {
        one = one->next;
        two = two->next->next;
        if(one == two)
        {
            return(one);
        }
    }
    return(NULL);
}