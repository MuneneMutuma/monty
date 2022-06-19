#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * push_int_error - error handler for push
 *
 * Return: void
 */
void push_int_error(void)
{
	fprintf(stderr, "L:%d usage: push integer\n", obj->line_number);
	exit(EXIT_FAILURE);
}


/**
 * malloc_error - handles malloc error
 *
 * Return: void
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
