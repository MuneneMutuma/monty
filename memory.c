#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - frees stack
 *
 * @head: points to stack top
 *
 * Return: void
 */
void free_stack(stack_t **head)
{
	stack_t *iter;

	iter = *head;
	while (iter != NULL)
	{
		*head = iter->prev;
		free(iter);
		iter = *head;
	}
	free(iter);
}
