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
	stack_t *new_item;
	int number;
	char *arg;

	new_item = malloc(sizeof(stack_t));
	if (!new_item)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_error(*stack);
	}
	arg = strtok(NULL, " \n");
	number = is_number(arg, line_number);
	if (errno == EXIT_FAILURE)
	{
		free(new_item);
		exit_error(*stack);
	}
	new_item->n = number;
	new_item->next = NULL;

	if (*stack == NULL)
		new_item->prev = NULL;
	else
	{
		for (; *stack; stack = &(*stack)->next)
			new_item->prev = *stack;
	}
	*stack = new_item;
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
/**
 * _pop - removes the top element of the stack.
 * @stack: Stack Manager.
 * @line_number: Data for make push
 *
 * Return: Nothing
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *prev, *next;

	(void) line_number;

	if (*stack)
	{
		for (; (*stack)->next; stack = &(*stack)->next)
			;

		prev = (!(*stack)->prev ? NULL : (*stack)->prev);
		next = (!(*stack)->next ? NULL : (*stack)->next);

		free(*stack);

		*stack = !next ? NULL : next;

		if (*stack)
			(*stack)->prev = prev;
	}
}
