#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "monty.h"


stack_t *head = NULL;


/**
 * main - entry point of the program
 *
 * @argc: number of command line arguements
 * @argv: argument vector
 *
 * Return: int
 */
int main(int argc, char **argv)
{
	char *filename;
	unsigned int line_number = 1;

	head = malloc(sizeof(stack_t *));
	if (!head)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	parsefile(filename, line_number);
	free_stack(head);
	return (argc);
}

/**
 * parsefile - opens file and reads through it
 *
 * @filename: filename of file to be opened
 * @line_number: line number of current instruction
 *
 * Return: void
 */
void parsefile(char *filename, unsigned int line_number)
{
	size_t bufsize = BUFSIZ;
	char *buf, **tokens;
	FILE *file;
	int number;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	buf = NULL;
	while (getline(&buf, &bufsize, file) != -1)
	{
		tokens = tokenize(&buf);
		if (!*tokens)
		{
			line_number++;
			continue;
		}
		if (tokens[1] != NULL)
		{
			number = _atoi(tokens[1], line_number);
		}
		if (strcmp(tokens[0], "push") == 0 && tokens[1] == NULL)
			push_int_error(line_number);
		if (tokens[0])
			operate(tokens[0], number, line_number);
		line_number++;
		free(tokens);
	}
	free(buf);
	fclose(file);
}

/**
 * operate - chooses opcode and operates
 *
 * @opcode: opcode to be implemented
 * @number: value to be implemented
 * @line_number: number of line with the current instruction
 *
 * Return: int: void
 */
void operate(char *opcode, int number, unsigned int line_number)
{
	int i, flag = 0;
	instruction_t map[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};
	stack_t *element;

	element = malloc(sizeof(stack_t));
	if (element == NULL)
	{
		free(element);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	element->n = number;
	for (i = 0; map[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, map[i].opcode) == 0)
		{
			if (i != 0)
			{
				free(element);
				element = head;
			}
			map[i].f(&element, line_number);
			flag = 1;
		}
	}

	if (flag == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * tokenize - makes tokens
 *
 * @buf: buffer to make tokens
 *
 * Return: a list of string tokens
 */
char **tokenize(char **buf)
{
	int argc = 0;
	char *token, **line;
	char *delim = " \n\t";

	line = (char **)malloc((strlen(*buf) + 1) * sizeof(char *));
	if (!line)
	{
		fprintf(stderr, "Error: malloc failedi\n");
		exit(EXIT_FAILURE);
	}
	token = NULL;

	token = strtok(*buf, delim);
	while (token != NULL)
	{
		line[argc] = token;
		token = strtok(NULL, delim);
		argc++;
	}
	line[argc] = NULL;

	return (line);
}
