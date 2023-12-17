#include "monty.h"

/**
  * _pint: print the value at the top
  * @stack: head
  * @line_number: line number
  */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit_error(*stack);
	}
	printf("%d\n", tmp->n);
}
