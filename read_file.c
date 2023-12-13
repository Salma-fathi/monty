#include "monty.h"

/**
  * read_file - read monty file line by line, call parse function
  * send the output op arg to run function.
  *
  * @fname: pointer to a file name.
  *
  * Return: sucess code in success else failure code
  */
int read_file(char *fname, stack_t **stack)
{
	FILE *monty_f;
	char *lineptr = NULL, *opcode;
	size_t n = 0, line_number = 1;
	instruction_t *operation;

	monty_f = fopen(fname, "r");
	if (monty_f == NULL)
	{
		/* file not exist error */
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
			return (EXIT_FAILURE);
		}
		/* call get_opcode function 
		    if sucess: call the operation
		    if not print unknown instruction error
		 */

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
		return (NULL);
	return (opcode);
}
