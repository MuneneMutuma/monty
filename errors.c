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
 * stack_len_error - error handler for short stack
 *
 * @opcode: opcode with the error
 *
 * Return: void
 */
void stack_len_error(char *opcode)
{
	fprintf(stderr, "L%d: can't %s, stack too short\n", obj->line_number, opcode);
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
 * div_by_zero - error handler for division by zero
 *
 * Return: void
 */
void div_by_zero(void)
{
	fprintf(stderr, "L%u: division by zero\n", obj->line_number);
	exit(EXIT_FAILURE);
}
