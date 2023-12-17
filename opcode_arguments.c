#include "monty.h"

/**
  * is_number - check if arg is number
  *
  * @arg: argument
  *
  * @line_number: line number
  *
  * Return: int
  */
int is_number(char *arg, unsigned int line_number)
{
	int isNum = 1, i, number;

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (!isdigit(arg[i]))
		{
			isNum = 0;
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			errno = EXIT_FAILURE;
			return (EXIT_FAILURE);
		}
	}
	if (isNum)
	{
		number = atoi(arg);
	}
	return (number);
}
