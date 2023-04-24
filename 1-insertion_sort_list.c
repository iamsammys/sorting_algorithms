#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list to be sorted
 *
 * return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *node;

	if (!list || !*list)
		return;

	node = (*list)->next;
	
	while(node)
	{
		temp = node->prev;
		while(temp && node->n < temp->n)
		{
			temp->next = node->next;
			if (node->next)
				node->next->prev = temp;
			node->prev = temp->prev;
			if(temp->prev)
				temp->prev->next = node;
			temp->prev = node;
			node->next = temp;
			if (!(node->prev))
				*list = node;
			temp = node->prev;
			print_list(*list);
		}
		node = node->next;
	}
}
