#include "monty.h"

/**
 * _push - It make a push to the stack.
 * @stack: Stack Manager.
 * @line_number: Data for make a push.
 *
 * Return: Nothing.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int number;
	char *arg;

	arg = strtok(NULL, " \n");
	number = is_number(arg, line_number);
	if (errno == EXIT_FAILURE)
	{
		exit_error(*stack);
	}
	*stack = add_node_end(stack, number);
}

/**
 * _pall - It prints the stack.
 * @stack: Stack Manager.
 * @line_number: Data for make a push.
 *
 * Return: Nothing.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
		exit_error(*stack);
	for (; (*stack)->next; stack = &(*stack)->next)
		;
	for (;  (*stack); stack = &(*stack)->prev)
		printf("%d\n",  (*stack)->n);
}
