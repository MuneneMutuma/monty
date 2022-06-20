#include "monty.h"
#include <stdlib.h>


/**
 * init - initiailizes obj handler
 *
 * Return: void
 */
void init(void)
{
	obj = malloc(sizeof(handler_t));
	if (!obj)
		malloc_error();

	obj->head = malloc(sizeof(stack_t));
	if (!(obj->head))
		malloc_error();

	obj->line_number = 1;
	obj->nodes = 0;
}

/**
 * free_obj - free obj handler
 *
 * Return: void
 */
void free_obj(void)
{
	stack_t *iter;

	iter = obj->head;

	while (iter->prev)
	{
		obj->head = iter->prev;
		free(iter);
		iter = obj->head;
	}
	free(iter);
	free(obj);
}
