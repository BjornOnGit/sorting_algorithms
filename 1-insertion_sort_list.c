#include "sort.h"

/**
 * swap - swaps 2 nodes ina doubly-linked list
 * @x: address of first node
 * @y: address of second node
 * 
 * Return: void
 */

void swap(listint_t *x, listint_t *y)
{
    if (x->prev)
    {
        x->prev->next = y;
    }
    if (y->next)
    {
        y->next->prev = x;
    }
    x->next = y->next;
    y->prev = x->prev;
    x->prev = y;
    y->next = x;
    
}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 * 
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *a, *b;
    if (!list || !*list || !(*list)->next)
    {
        return;
    }
    a = (*list)->next;
    while (a)
    {
        b = a;
        a = b->next;
        while (b && b->prev)
        {
            if (b->prev->n > b->n)
            {
                swap(b->prev, b);
                if (!b->prev)
                {
                    *list = b;
                }
                print_list((const listint_t *)*list);
            }
            else
            {
                b = b->prev;
            }
        }
        
    }
}    