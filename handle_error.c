#include "monty.h"

/**
 * file_error - Prints the error message on error argc.
 *
 *
 * Return: Nothing.
 */

void fileError(void)
{
	fputs("USAGE: monty file\n", stderr);
	exit(EXIT_FAILURE);
}

/**
 * open_error - Prints the error message on error open.
 * @filename: Name of the file.
 *
 * Return: Nothing.
 */

void openError(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * line_error_code - Prints the error message on error with Monty.
 * @line: The line of the current error.
 * @opcode: The code that gives an error.
 *
 * Return: Nothing.
 */

void line_error_code(int *line, char *opcode)
{
	char *code = strtok(opcode, DELIMITER);

	fprintf(stderr, "L%i: unknown instruction %s\n", line[1], code);
	free(line);
	free(opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Prints the error message on error mallocating.
 *
 *
 * Return: Nothing.
 */

void malloc_error(void)
{
	fputs("Error: malloc failed\n", stderr);
	exit(EXIT_FAILURE);
}
/**
 * error_handler - It manages the error flow.
 * @stack: It's the stack data structure.
 * @file: It's the given file for closing.
 * @op: Array with datas.
 * @opcode: Given opcode.
 *
 * Return: Nothing.
 */

void error_handler(stack_t **stack, FILE *file, int *op, char *opcode)
{
	if (op[0] == FILE_ERROR)
		return;
	freeStack(*stack);
	fclose(file);
	switch (op[0])
	{
	case -1:
		zero_error(op, opcode);
		break;
	case 1:
		line_error_code(op, opcode);
		break;
	case 2:
		push_error(op, opcode);
		break;
	case 3:
		pop_error(op, opcode);
		break;
	case 4:
		pint_error(op, opcode);
		break;
	case 5:
		swap_error(op, opcode);
		break;
	case 6:
		math_errors(op, opcode, "add");
		break;
	case 7:
		math_errors(op, opcode, "sub");
		break;
	case 8:
		math_errors(op, opcode, "div");
		break;
	case 9:
		math_errors(op, opcode, "mul");
		break;
	case 10:
		math_errors(op, opcode, "mod");
		break;
	}
}
