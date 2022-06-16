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
	if (head == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	parsefile(filename, line_number);
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
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&buf, &bufsize, file) != -1)
	{
		tokens = tokenize(&buf);
		if (tokens[1])
		{
			number = atoi(tokens[1]);
			if (number == 0 && (tokens[1] - '0') != 0)
			{
				dprintf(2, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		if (tokens[0])
			operate(tokens[0], number, line_number);
		line_number++;
	}
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
		{NULL, NULL}
	};
	stack_t *element;

	element = malloc(sizeof(stack_t));
	if (element == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	element->n = number;
	for (i = 0; map[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, map[i].opcode) == 0)
		{
			if (strcmp(opcode, "pall") == 0)
				element = head;
			map[i].f(&element, line_number);
			flag = 1;
		}
	}

	if (flag == 0)
	{
		dprintf(2, "L%u: unkown instruction %s\n", line_number, opcode);
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
