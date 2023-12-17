#include "monty.h"

int flag = 1;

/**
  * _stack - set flag to 1
  *
  * @stack: stack head
  *
  * @line_number: line number
  *
  * Return: nothings
  */
void _stack(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	flag = 1;
}
/**
  * _queue - set flag to 0
  *
  * @stack: stack head
  *
  * @line_number: line number
  *
  * Return: nothings
  */
void _queue(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	flag = 0;
}
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
	if (flag == 1)
		add_node_end(stack, number);
	else
		add_node(stack, number);
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
