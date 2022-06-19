#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * _atoi - converts string to int
 *
 *
 * @str: pointer to string
 * @line_number: line number of current operation command
 *
 * Return: converted int or exit on failure
 */
int _atoi(char *str, unsigned int line_number)
{
	int i, num;

	num = 0;

	for (i = 0; str[i]; i++)
	{
		if (i == 0 && str[i] == '-')
			continue;

		if (str[i] > 58 || str[i] < 48)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		num = num * 10 + (str[i] - '0');
	}
	if (str[0] == '-')
		num *= -1;
	return (num);
}
