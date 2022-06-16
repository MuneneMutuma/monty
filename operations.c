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
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		free(head);
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
