#include "monty.h"

/**
  * _pchar - print the char value at the top
  * @stack: head
  * @line_number: line number
  */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		putchar('\n');
		exit_error(*stack);
	}
	for (; (*stack)->next; stack = &(*stack)->next)
		;
	num = (*stack)->n;
	if (isprint(num))
	{
		printf("%c\n", (char)num);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit_error(*stack);
	}
}
