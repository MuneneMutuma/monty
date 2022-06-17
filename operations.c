#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - performs push operation
 *
 * @stack: new stack element
 * @line_number: line_number in the file
 *
 * Return: void always
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (!head)
	{
		free(head);
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
	}
	else
	{
		(*stack)->prev = head;
		(*stack)->next = NULL;
		head->next = *stack;
	}

	head = *stack;
	line_number++;
}

/**
 * pall - prints a stack
 *
 * @stack: points to stack terminal
 * @line_number: current line number of instruction
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *iter;

	iter = *stack;
	while (iter->prev)
	{
		printf("%d\n", iter->n);
		iter = iter->prev;
	}
	line_number++;
}

/**
 * pint - prints integer at top of stack
 *
 * @stack: pointer to top of stack
 * @line_number: number of line of the present command
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
	line_number++;
}
