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
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit_error(*stack);
	}
	delete_node(stack);
}
/**
  * _swap - swap values at the top
  *
  * @stack: head
  *
  * @line_number: number of lines
  *
  * Return: nothings
  */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int swap;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit_error(*stack);
	}
	for (; tmp->next; tmp = tmp->next)
		;
	swap = tmp->n;
	tmp->n = tmp->prev->n;
	tmp->prev->n = swap;
}
