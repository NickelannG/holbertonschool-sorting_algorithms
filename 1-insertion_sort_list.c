#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 *
 * @list: a pointer to a pointer to the head of the doubly
 * linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	/* Start from second node */
	current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap the current node with its previous node*/
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;

			/* Update neighbouring nodes for the new temp */
			if (temp->prev->prev != NULL)
				temp->prev->prev->next = temp;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			/* Update head */
			if (temp->prev == NULL)
				*list = temp; /* Update head */
			else
				temp->prev->next = temp;

			/* Print the list after every swap */
			print_list(*list);
		}
		/* Move on to the next node */
		current = current->next;
	}
}
