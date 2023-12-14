#include "monty.h"

/**
  * read_file - read monty file line by line, call parse function
  * send the output op arg to run function.
  *
  * @fname: pointer to a file name.
  *
  * Return: sucess code in success else failure code
  */
int read_file(char *filename, stack_t **stack)
{
	FILE *monty_f;
	char *lineptr = NULL, *opcode;
	size_t n = 0, line_number = 1;
	instruction_t *operation;

	monty_f = fopen(filename, "r");
	if (monty_f == NULL)
	{
		/* file not exist error */
		openError(filename);
		return (EXIT_FAILURE);
	}
	while (getline(&lineptr, &n, monty_f) != EOF)
	{
		/* check if the line is empty or begin with # */
		if (strcmp(lineptr, '\n') == 0 || strncmp(lineptr, '#', 1) == 0)
			continue;
		opcode = parse(lineptr);
		if (opcode == NULL)
		{
			/* unknown instruction error */
			line_error_code(&line_number, opcode);
			return (EXIT_FAILURE);
		}
		/* call get_opcode function 
		    if sucess: call the operation
		    if not print unknown instruction error
		 */
		run(stack, opcode, line_number);
		/* increment to next line in monty file */
		line_number++;		
	}
	return (EXIT_SUCCESS);
}
/**
  * parse - tokenization the line
  *
  * @line: pointer to the line
  *
  * Return: opcode
  */
char *parse(char *lineptr)
{
	char *opcode, delm = "\n ";

	opcode = strtok(lineptr, delm);
	/* return NULL if the opcode = NULL or opcode not alphabetical*/
	if (opcode == NULL || isalpha(opcode) == 0)
		return (opcode);
	return (opcode);
}
