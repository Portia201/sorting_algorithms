#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Double linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *back;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current)
    {
        while (current->prev && current->prev->n > current->n)
        {
            back = current->prev;
            current->prev = back->prev;
            back->next = current->next;

            if (current->next)
                current->next->prev = back;

            current->next = back;
            back->prev = current;

            if (current->prev)
                current->prev->next = current;
            else
		*list = current;

            print_list(*list);
        }

        current = current->next;
    }
}
