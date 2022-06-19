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
	free(obj->head);
	free(obj);
}
