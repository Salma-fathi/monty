#include "monty.h"

/**
  * _sub - subs the top two elements of the stack.
  *
  * @stack: head
  *
  * @line_number: line number
  *
  * Return: nothings
  */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit_error(*stack);
	}
	for (; tmp->next->next; tmp = tmp->next)
		;
	tmp->n -= tmp->next->n;
	free(tmp->next);
	tmp->next = NULL;
}
/**
  * _div - divide the top two elements of the stack.
  *
  * @stack: head
  *
  * @line_number: line number
  *
  * Return: nothings
  */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit_error(*stack);
	}
	for (; tmp->next->next; tmp = tmp->next)
		;
	if (tmp->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		exit_error(*stack);
	}
	tmp->n /= tmp->next->n;
	free(tmp->next);
	tmp->next = NULL;
}
