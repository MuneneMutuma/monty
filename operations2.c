#include "monty.h"

void add(stack_t **stack)
{
	if (obj->nodes < 2)
		add_error();
	(*stack)->prev->n += (*stack)->n;
	pop(stack);
}
