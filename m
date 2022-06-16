#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "monty.h"


stack_t *head = NULL;

int fselector(char **tokens, stack_t **element, int *n, unsigned int *line_number)
{
	int i;
	instruction_t opcode[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; opcode[i].opcode != NULL; i++)
	{
		if (strcmp(opcode[i].opcode, tokens[0]) == 0)
		{
			if (strcmp(tokens[0], "pall") == 0)
				*element = head;
			if (strcmp(tokens[0], "push") == 0)
				(*element)->n = *n;
			opcode[i].f(element, *line_number);
			return (i);
		}
	}
	return (-1);
}

int main(int argc, char **argv)
{
	int n;
	unsigned int line_number = 1;
	char *buf, **tokens;
	size_t bufsize = BUFSIZ;
	FILE *file;
	stack_t *element;

	head = malloc(sizeof(stack_t));
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
		exit(errno);

	while(getline(&buf, &bufsize, file) != -1)
	{
		element = (stack_t *)malloc(sizeof(stack_t));
		tokens = tokenize(&buf);
		n = atoi(tokens[1]);
		fselector(tokens, &element, &n, &line_number);
	}

	return (0);
}

char **tokenize(char **buf)
{
	int argc = 0;
	char *token, **line;
	char *delim = " \n";

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
