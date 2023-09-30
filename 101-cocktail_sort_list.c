#include "sort.h"
/**
*swap - swaps 2 nodes in a doubly-linked list
*@i: address of first node
*@j: address of second node
*
*Return: void
*/
void swap(listint_t *i, listint_t *j)
{
	if (i->prev)
		i->prev->next = j;
	if (j->next)
		j->next->prev = i;
	i->next = j->next;
	j->prev = i->prev;
	i->prev = j;
	j->next = i;
}
/**
*tail_traverse- function that sorts from the tail back
*
*@head: head of list
*@tail: tail of the list
*@list: original head of the list
*
*Return: new head of the list
*/
listint_t *tail_traverse(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}

/**
*cocktail_sort_list - sorts linked list using cocktail shaker sort
*
*@list: doubly linked list to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *head, *len;
	int a = 0, b = 0, swapped = 1;

	if (!list || !*list)
		return;
	len = *list;
	for (a = 0; len; a++)
	{
		len = len->next;
	}
	if (a < 2)
		return;
	head = *list;
	while (b < a)
	{
		swapped = 0;
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swap(head, head->next);
				swapped++;
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
			}
			else
				head = head->next;
			if (head->next == NULL)
				tail = head;
		}
		head = tail_traverse(head, tail, *list);
		*list = head;
		b++;
	}
}
