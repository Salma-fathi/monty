#include "monty.h"
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
/**
 * Log an error message.
 * @line_cnt: Line number.
 * @message: Error message.
 */
void logError(unsigned int line_cnt, const char *function, const char *file, const char *message)
{
    if (message != NULL)
        fprintf(stderr, "L%d: Error in %s (%s) - %s\n", line_cnt, function, file, message);
    else
        fprintf(stderr, "L%d: Error in %s (%s) - Unknown error\n", line_cnt, function, file);
}

/**
 * Log a success message.
 * @message: Success message.
 */
void logSuccess(const char *message)
{
    printf("%s\n", message);
}
