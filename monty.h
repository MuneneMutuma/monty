#ifndef MONTY_H
#define MONTY_H


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



/* STRUCTURES */


/**
 * struct stack_s - doubly linked list representation fo a stack (or queue)
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
	struct stack_s *next;
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
	void (*f)(stack_t **stack);
} instruction_t;



typedef struct handler_s
{
	stack_t *head;
	unsigned int line_number;
	unsigned int nodes;
} handler_t;



/* VARIABLES */
extern handler_t *obj;



/*------- FUNCTIONS ------*/
/* main.c */
char **tokenize(char **buf);
void parsefile(char *filename);
void operate(char *opcode, int number);
void free_stack(stack_t *head);

/* operations.c */
void push(stack_t **stack);
void pall(stack_t **stack);
void pint(stack_t **stack);
void pop(stack_t **stack);
void swap(stack_t **stack);

/* operations2.c */
void add(stack_t **stack);

/* _atoi.c */
int _atoi(char *str, unsigned int line_number);

/* errors.c */
void push_int_error(void);
void malloc_error(void);
void add_error(void);

/* init.c */
void init(void);
void free_obj(void);

#endif /* MONTY_H */
