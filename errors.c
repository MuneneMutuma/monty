#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * push_int_error - error handler for push
 *
 * @line_number: current line number of opcode
 *
 * Return: void
 */
void push_int_error(unsigned int line_number)
{
	fprintf(stderr, "L:%d usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
