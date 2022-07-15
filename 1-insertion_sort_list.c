#include "sort.h"

/**
 * insertion_sort_array - sort an array of integers
 *    with Insertion sort algorithm
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void insertion_sort_array(int array[], int size)
{
	int i, j, x;

	for (i = 1; i < size; i++)
	{
		j = i - 1;

		x = array[i];

		while (j > -1 && array[j] > x)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = x;
	}
}

/**
 * swap_next - swaps the current node with the next
 *
 * @node: the current node
 * @next_node: the next node
 * @list: double pointer to the list
 *
 * Return: nothing
 */
void swap_next(listint_t *node, listint_t *next_node, listint_t **list)
{
	node->next = next_node->next;

	if (next_node->next)
		next_node->next->prev = node;

	next_node->next = node;
	next_node->prev = NULL;

	if (node->prev)
	{
		node->prev->next = next_node;
		next_node->prev = node->prev;
	}
	node->prev = next_node;
	while ((*list)->prev)
		(*list) = (*list)->prev;
	print_list(*list);
}

/**
 * swap_prev - swaps the current node with the next
 *
 * @node: the current node
 * @prev_node: the next node
 * @list: double pointer to the list
 * Return: nothing
 */
void swap_prev(listint_t *node, listint_t *prev_node, listint_t **list)
{
	prev_node->next = node->next;
	node->next->prev = prev_node;
	node->next = prev_node;
	node->prev = NULL;
	if (prev_node->prev)
	{
		prev_node->prev->next = node;
		node->prev = prev_node->prev;
	}
	prev_node->prev = node;
	while ((*list)->prev)
		(*list) = (*list)->prev;
	print_list(*list);
}

/**
 * insertion_sort_list - sort a double linked list of integers
 *   with Insertion sort algorithm
 *
 * @list: double pointer to the list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *curr, *fwd, *temp = NULL;

	if (head == NULL)
		return;

	curr = head;
	while (curr->next)
	{
		fwd = curr->next;

		if (curr->n > fwd->n)
		{
			swap_next(curr, fwd, list);
			curr = curr->prev ? curr->prev : curr;

			while (curr->prev)
			{
				temp = curr->prev;
				fwd = curr->next;
				if (temp->n > curr->n)
					swap_prev(curr, temp, list);
				curr = curr->prev ? curr->prev : curr;
			}
		}
		else
			curr = curr->next;
	}
}
