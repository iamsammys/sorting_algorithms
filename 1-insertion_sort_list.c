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
	listint_t *temp, *head, *node, *temp_2;

	if (!list || !*list)
		return;

	head = *list;
	node = head->next;
	
	while(node)
	{
		while(node->prev && node->n < (node->prev)->n)
		{
			head = node->prev;
			temp = node->next;
			temp_2 = head->prev;
			node->prev = temp_2;
			node->next = head;
			head->next = temp;
			head->prev = node;
			if (temp_2)
				temp_2->next = node;
			if (temp)
				temp->prev = head;
			node = node->prev;
		}
		node = node->next;
	}
}
