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
	new_item->n = number;
	new_item->next = NULL;

	if (stack == NULL)
	{
		new_item->prev = NULL;
		printf("num in list: %d\n", (*stack)->n);
	}
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

	for (; (*stack)->next; stack = &(*stack)->next)
		;
	for (;  (*stack); stack = &(*stack)->prev)
		printf("%d\n",  (*stack)->n);
}
