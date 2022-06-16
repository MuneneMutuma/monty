#ifndef MONTY_H
#define MONTY_H


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



/* STRUCTURES */


/**
 * struct stact_s - doubly linked list representation fo a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of teh stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s * next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/* VARIABLES */
extern stack_t *head;



/* FUNCTIONS */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
char **tokenize(char **buf);

#endif /* MONTY_H */
