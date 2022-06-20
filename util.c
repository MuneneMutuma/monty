#include "monty.h"
#include <stdlib.h>
#include <string.h>


/**
 * opcode_selector - selects the right opcode
 *
 * @opcode: opcode to be selected
 *
 * Return: instruction for the opcode
 */
instruction_t opcode_selector(char **opcode)
{
	int i;
	instruction_t map[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
	};

	for (i = 0; map[i].opcode != NULL; i++)
	{
		if (strcmp(*opcode, map[i].opcode) == 0)
			return (map[i]);
	}

	no_opcode_error(opcode);
	return (map[i]);
}
