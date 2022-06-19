#include "monty.h"

/**
 * add - adds the two topmost elements in stack
 *
 * @stack: head of stack (a.k.a obj->head)
 *
 * Return: void
 */
void add(stack_t **stack)
{
	if (obj->nodes < 2)
		add_error();
	(*stack)->prev->n += (*stack)->n;
	pop(stack);
}
