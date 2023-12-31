#include "monty.h"

/**
  * _pchar - print the char value at the top
  * @stack: head
  * @line_number: line number
  */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit_error(*stack);
	}
	for (; (*stack)->next; stack = &(*stack)->next)
		;
	num = (*stack)->n;
	if (isprint(num))
	{
		putchar(num);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit_error(*stack);
	}
}
/**
 * _pstr - It prints char the stack.
 * @stack: Stack Manager.
 * @line_number: line number
 *
 * Return: Nothing.
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	int num;
	(void)line_number;

	if (*stack == NULL)
		exit_error(*stack);
	for (; (*stack)->next; stack = &(*stack)->next)
		;
	for (; (*stack); stack = &(*stack)->prev)
	{
		num = (*stack)->n;
		if (num == 0 || !isprint(num))
			break;
		putchar(num);
	}
	putchar('\n');
}
