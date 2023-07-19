#include "sort.h"
#include <stdio.h>


/**
 * insertion_sort_list - Sorts a doubly linked list
 * of integers in ascending order
 * using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list
 *
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{

listint_t *current, *key, *temp;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;


current = (*list)->next;

while (current != NULL)
{
key = current;
temp = key->prev;

while (temp != NULL && temp->n > key->n)
{
temp->next = key->next;
if (key->next != NULL)
key->next->prev = temp;

key->prev = temp->prev;
if (temp->prev != NULL)
temp->prev->next = key;
else
*list = key;

temp->prev = key;
key->next = temp;

temp = key->prev;
print_list(*list);
}

current = current->next;
}
}
