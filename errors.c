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
	fprintf(stderr, "L%d: usage: push integer\n", obj->line_number);
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

/**
 * add_error - error handler for add
 *
 * Return: void
 */
void add_error(void)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", obj->line_number);
	exit(EXIT_FAILURE);
}


/**
 * no_opcode_error - error handler for invalide opcode
 *
 * @opcode: invalid opcode
 *
 * Return: void
 */
void no_opcode_error(char **opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", obj->line_number, *opcode);
	exit(EXIT_FAILURE);
}

/**
 * sub_error - error handler for sub
 *
 * RETURN: void
 */
void sub_error(void)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", obj->line_number);
	exit(EXIT_FAILURE);
}
