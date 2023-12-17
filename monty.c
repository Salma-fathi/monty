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
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	read_file(argv[1], &stack);
	freeStack(stack);

	return (EXIT_SUCCESS);
}
   **/