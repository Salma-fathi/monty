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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit_error(*stack);
	}
	for (; tmp->next; tmp = tmp->next)
		;
	swap = tmp->n;
	tmp->n = tmp->prev->n;
	tmp->prev->n = swap;
}
/**
  * _add - adds the top two elements of the stack.
  *
  * @stack: head
  *
  * @line_number: line number
  *
  * Return: nothings
  */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit_error(*stack);
	}
	for (; tmp->next->next; tmp = tmp->next)
		;
	tmp->n += tmp->next->n;
	free(tmp->next);
	tmp->next = NULL;
}
/**
  * _nop - do nothings 
  *
  * @stack: head
  *
  * @line_number: line number
  *
  * Return: nothings
  */
void _nop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	;
}
