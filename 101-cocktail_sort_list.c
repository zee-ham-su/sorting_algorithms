#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Double pointer to the head of the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
listint_t *prev1 = node1->prev;
listint_t *next2 = node2->next;

if (prev1 != NULL)
prev1->next = node2;
else
*list = node2;

if (next2 != NULL)
next2->prev = node1;

node2->prev = prev1;
node1->next = next2;
node1->prev = node2;
node2->next = node1;
}



/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *left;
listint_t *right = NULL;
if (!list || !(*list) || !(*list)->next)
return;
do {
swapped = 0;
left = *list;
while (left->next != right)
{
if (left->n > left->next->n)
{
swap_nodes(list, left, left->next);
print_list(*list);
swapped = 1;
}
else
left = left->next;
}

if (!swapped)
break;

swapped = 0;
right = left;

while (right->prev != NULL)
{
if (right->n < right->prev->n)
{
if (left->n > left->next->n)

swap_nodes(list, right->prev, right);
print_list(*list);
swapped = 1;
}
else
right = right->prev;
}
} while (swapped);
}
