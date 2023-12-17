#include "monty.h"

/**
  * _pint - print the value at the top
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
	for (; (*stack)->next; stack = &(*stack)->next)
		;
	printf("%d\n", (*stack)->n);
}
/**
  * _pop - delete element at the top
  *
  * @stack: head
  *
  * @line_number: line number
  *
  * Return: nothings
  */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *prev, *next;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		exit_error(*stack);
	}
	for (; (*stack)->next; stack = &(*stack)->next)
		;
	prev = (!(*stack)->prev ? NULL : (*stack)->prev);
	next = (!(*stack)->next ? NULL : (*stack)->next);
	free(*stack);
	*stack = !next ? NULL : next;
	if (*stack)
		(*stack)->prev = prev;
}
