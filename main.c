#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "monty.h"


handler_t *obj = NULL;


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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	init();
	filename = argv[1];
	parsefile(filename);
	free_obj();
	return (0);
}

/**
 * parsefile - opens file and reads through it
 *
 * @filename: filename of file to be opened
 *
 * Return: void
 */
void parsefile(char *filename)
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
			obj->line_number++;
			free(tokens);
			continue;
		}
		if (strcmp(tokens[0], "push") == 0)
		{
			if (tokens[1] != NULL)
				number = _atoi(tokens[1], obj->line_number);
			else
				push_int_error();
		}
		if (tokens[0])
			operate(tokens[0], number);
		obj->line_number++;
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
 *
 * Return: int: void
 */
void operate(char *opcode, int number)
{
	instruction_t map;
	stack_t *element;

	element = malloc(sizeof(stack_t));
	if (element == NULL)
		malloc_error();
	element->n = number;

	map = opcode_selector(&opcode);
	if (map.opcode == NULL)
		no_opcode_error(&opcode);
	if (strcmp(map.opcode, "push") == 0)
		map.f(&element);
	else
	{
		free(element);
		map.f(&(obj->head));
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
