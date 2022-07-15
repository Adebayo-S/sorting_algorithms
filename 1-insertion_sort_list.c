#include "sort.h"

/**
 *insertion_sort_array - sort an array of integers
           with  Insertion sort algorithm
 *@array: the array to sort
 *@size: size of the array
 */
void insertion_sort_array(int array[], int size)
{
	int i, j, x;

	for(i = 1; i < size; i++)
	{
		j = i - 1;

		x = array[i];

		while(j > -1 && array[j] > x)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = x;
	}
}

/**
 *insertion_sort_list - sort a double linked list of integers
		with  Insertion sort algorithm
*@list: double pointer to the list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *curr, *fwd, *temp, *comp = NULL;
	int x = 0;

	if (head == NULL)
		return;

	curr = head;
	while (curr->next)
	{
		fwd = curr->next;
		x = fwd->n;
		if (curr->n > x)
		{
			if (curr && curr->n > x)
			{
				curr->next = fwd->next;
				if (fwd->next)
					fwd->next->prev = curr;
				fwd->next = curr;
				fwd->prev = NULL;
				if (curr->prev)
				{
					curr->prev->next = fwd;
					fwd->prev = curr->prev;
				}
				curr->prev = fwd;
				print_list(*list);
				curr = curr->prev;
				fwd = curr->next;
				x = fwd->n;
			}

			comp = curr;
			while (curr->prev)
			{
				temp = comp->prev;
				fwd = comp->next;
				if (temp->n > comp->n)
				{
					temp->next = fwd;
					fwd->prev = temp;
					comp->next = temp;
					comp->prev = NULL;
					if (temp->prev)
					{
						temp->prev->next = comp;
						comp->prev = temp->prev;
					}
					temp->prev = comp;
					while ((*list)->prev)
						(*list) = (*list)->prev;
					print_list(*list);
				}
				curr = curr->prev ? curr->prev : curr;
			}
		}
		else
			curr = curr->next;
	}
	*list = curr->prev->prev->prev->prev->prev->prev->prev->prev->prev;
}

/**
 *insertion_sort_list - sort a double linked list with  Insertion sort algorithm
 *@list: double pointer to the list
 */
// void insertion_sort_list(listint_t **list)
// {
// 	listint_t *aux;
// 	listint_t *aux2 = *list;
// 	listint_t *i = *list;

// 	if  (aux2 == NULL)
// 		return;

// 	aux2 = aux2->next;

// 	while (aux2 !=NULL)
// 	{
// 		i = aux2;
// 		aux2 = aux2->next;

// 		while (i->prev != NULL && i->n < i->prev->n)
// 		{
// 			if (i->next != NULL)
// 				i->next->prev = i->prev;

// 			if (i->prev->prev != NULL)
// 				i->prev->prev->next = i;
// 			else
// 				*list = i;

// 			i->prev->next = i->next;
// 			i->next = i->prev;
// 			aux = i->prev->prev;
// 			i->prev->prev = i;
// 			i->prev = aux;
// 			print_list(*list);
// 		}
// 	}
// }
