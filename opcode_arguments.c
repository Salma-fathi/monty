#include "monty.h"

/**
  * is_number - check if arg is number
  *
  * @arg: argument
  *
  * Return: int
  */
int is_number(char *arg, stack_t *stack)
{
	int isNum = 1, i, number;

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (!isdigit(arg[i]))
		{
			isNum = 0;
			exit_error(stack);
		}
	}
	if (isNum)
	{
		number = atoi(arg);
	}
	return (number);
}
