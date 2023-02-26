#include "sort.h"
/**
* insertion_sort_list -  sorts a doubly linked list of integers in
* ascending order using the Insertion sort algorithm
* @list: first params, double pointer to the linked list
*
* Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *node_swap;
	listint_t *temp;

	/*not a list we expected or zero elements*/
	if (!list || *list == NULL)
		return;
	current = *list; /*copy of the list head*/
	/*re-validate if only one element in the list*/
	if (current->next == NULL)
		return;
	while (current->next != NULL)
	{
		node_swap = current->next; /*on zero based, represents node 1*/
		/*start your comparisons*/
		if (current->n > node_swap->n)
		{
			temp = current;
			while (temp != NULL && temp->n > node_swap->n)
			{
				temp->next = node_swap->next;
				if (temp->next != NULL)
					temp->next->prev = temp;
				node_swap->prev = temp->prev;
				if (node_swap->prev != NULL)
					node_swap->prev->next = node_swap;
				else
					*list = node_swap;
				temp->prev = node_swap;
				node_swap->next = temp;
				print_list(*list);
				temp = node_swap->prev;
			}
			continue;
		}
		current = current->next;
	}
}
