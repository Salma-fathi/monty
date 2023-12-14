#include "monty.h"

/**
  * main - entery functions
  *
  * @argc: number of arguments
  *
  * @argv: array of arguments
  *
  * Return: success (0) or error code
  */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		/* monty file error */
		fileError();
		return (EXIT_FAILURE);
	}
	if (read_file(argv[1], &stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	/* free stack */
	freeStack(stack);
		
	return (EXIT_SUCCESS);
}
