#include "sort.h"

/**
 * swap_nodes - Swaps two nodes of a doubly linked list
 *
 * @node: Pointer to the node to be swapped
 * @list: Pointer to the head of the doubly linked list
 *
 * Return: No return value
 */

void swap_nodes(listint_t **node, listint_t **list)
{
listint_t *current = *node, *next_node, *prev_node;
/* Check if the node is the head of the list */
if (!current->prev)
*list = current->next;

current = prev_node = *node;
next_node = current->next;
/* Perform the swap for the doubly linked list */
current->next = next_node->next;
prev_node = current->prev;
current->prev = next_node;
next_node->next = current;
next_node->prev = prev_node;

/* Update the links for the adjacent nodes */
if (next_node->prev)
next_node->prev->next = next_node;

if (current->next)
current->next->prev = current;

*node = next_node;
}






/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 * using the Cocktail shaker sort algorithm
 *@list: Pointer to the head of the list to be sorted
 * (Doubly Linked List)
 * Return: No return value
 */

void cocktail_sort_list(listint_t **list)
{
listint_t *head, *aux;
int forward_pass = 0, backward_pass = -1, total_passes = -1;

if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
return;

head = *list;
while (backward_pass >= total_passes)
{
total_passes++;
while (head->next && forward_pass != backward_pass)
{
if (head->n > head->next->n)
{
aux = head;
swap_nodes(&aux, list);
print_list(*list);
head = aux;
}

forward_pass++;
head = head->next;
}

if (backward_pass == 0)
total_passes = forward_pass;
backward_pass--;
while (head->prev && forward_pass >= backward_pass)
{
if (head->n < head->prev->n)
{
aux = head->prev;
swap_nodes(&aux, list);
print_list(*list);
head = aux->next;
}
forward_pass--;
head = head->prev;
}
}
}
