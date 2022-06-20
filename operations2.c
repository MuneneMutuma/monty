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
		stack_len_error("add");

	(*stack)->prev->n += (*stack)->n;
	pop(stack);
}

/**
 * sub - subtracts two topmost element on the stack
 *
 * @stack: head of the stack (a.k.a obj->head)
 *
 * Return: void
 */
void sub(stack_t **stack)
{
	if (obj->nodes < 2)
		stack_len_error("sub");

	(*stack)->prev->n -= (*stack)->n;
	pop(stack);
}

/**
 * divide - divides two topmost elements in stack
 *
 * @stack: head of stack
 *
 * Return: void
 */
void divide(stack_t **stack)
{
	if (obj->nodes < 2)
		stack_len_error("div");
	if ((*stack)->n == 0)
		div_by_zero();

	(*stack)->prev->n /= (*stack)->n;
	pop(stack);
}

/**
 * multiply - multiplies two topmost elements in stack
 *
 * @stack: head of stack
 *
 * Return: void
 */
void multiply(stack_t **stack)
{
	if (obj->nodes < 2)
		stack_len_error("mul");

	(*stack)->prev->n *= (*stack)->n;
	pop(stack);
}

/**
 * modulus - finds modulo two topmost elements in stack
 *
 * @stack: head of stack
 *
 * Return: void
 */
void modulus(stack_t **stack)
{
	if (obj->nodes < 2)
		stack_len_error("mod");
	if ((*stack)->n == 0)
		div_by_zero();

	(*stack)->prev->n %= (*stack)->n;
	pop(stack);
}
