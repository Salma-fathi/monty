#include "monty.h"

/**
  * read_file - read monty file line by line, call parse function
  * send the output op arg to run function.
  *
  * @filename: pointer to a file name.
  *
  * @stack: stack
  *
  * Return: sucess code in success else failure code
  */
int read_file(char *filename, stack_t **stack)
{
	char lineptr[MAX_LINE_LENGTH];
	FILE *monty_f;
	char *opcode;
	unsigned int line_number = 1;

	monty_f = fopen(filename, "r");
	if (monty_f == NULL)
	{
		/* file not exist error */
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(lineptr, sizeof(lineptr), monty_f) != NULL)
	{
		opcode = parse(lineptr);
		if (opcode == NULL || opcode[0] == '#')
		{
			line_number++;
			continue;
		}
		run(stack, opcode, line_number);
		/* increment to next line in monty file */
		line_number++;
	}
	fclose(monty_f);
	return (EXIT_SUCCESS);
}
/**
  * parse - tokenization the line
  *
  * @lineptr: pointer to the line
  *
  * Return: opcode
  */
char *parse(char *lineptr)
{
	char *opcode, *delm = "\n ";

	opcode = strtok(lineptr, delm);
	/* return NULL if the opcode = NULL or opcode not alphabetical*/
	if (opcode == NULL)
		return (NULL);
	return (opcode);
}
/**
  * exit_error - exit wit failure error
  *
  * @stack: stack
  *
  * Return: nothings
  */
void exit_error(stack_t *stack)
{
	if (stack)
		freeStack(stack);
	exit(EXIT_FAILURE);
}
