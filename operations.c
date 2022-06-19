#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - performs push operation
 *
 * @stack: new stack element
 *
 * Return: void always
 */
void push(stack_t **stack)
{
	if (!obj->head)
	{
		free(obj->head);
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
	}
	else
	{
		(*stack)->prev = obj->head;
		(*stack)->next = NULL;
		obj->head->next = *stack;
	}

	obj->head = *stack;
	obj->nodes++;
}

/**
 * pall - prints a stack
 *
 * @stack: points to stack terminal
 *
 * Return: void
 */
void pall(stack_t **stack)
{
	stack_t *iter;

	iter = *stack;
	while (iter->prev)
	{
		printf("%d\n", iter->n);
		iter = iter->prev;
	}
}

/**
 * pint - prints integer at top of stack
 *
 * @stack: pointer to top of stack
 *
 * Return: void
 */
void pint(stack_t **stack)
{
	if (obj->nodes == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", obj->line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes top element of stack
 *
 * @stack: points to stack
 *
 * Return: void
 */
void pop(stack_t **stack)
{
	if (obj->nodes == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", obj->line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->prev;
	free((*stack)->next);
	(*stack)->next = NULL;
	obj->nodes--;
}

/**
 * swap - swaps topmost elements in stack
 *
 * @stack: points to top of stack
 *
 * Return: void
 */
void swap(stack_t **stack)
{
	stack_t *tmp;

	if (obj->nodes < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", obj->line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->prev;
	(*stack)->prev = tmp->prev;
	(*stack)->next = tmp;
	tmp->next = NULL;
	tmp->prev = *stack;
	*stack = tmp;
}
