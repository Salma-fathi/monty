#include "monty.h"

/**
 * _add - sum.
 * @stack: Stack Manager.
 * @line_number: Data for make a push.
 *
 * Return: Nothing.
 */

void _add(stack_t **stack, UNUSED unsigned int line_number)
{
	if (*stack != NULL)
	{
		for (; (*stack)->next->next; stack = &(*stack)->next)
			;
		(*stack)->n += (*stack)->next->n;
		_pop(stack, 0);
	}
}

/**
 * _sub - substract.
 * @stack: Stack Manager.
 * @line_number: Data for make a push.
 *
 * Return: Nothing.
 */

void _sub(stack_t **stack, UNUSED unsigned int line_number)
{
	if (*stack != NULL)
	{
		for (; (*stack)->next->next; stack = &(*stack)->next)
			;
		(*stack)->n -= (*stack)->next->n;
		_pop(stack, 0);
	}
}

/**
 * _mul - multiply.
 * @stack: Stack Manager.
 * @line_number: Data for make a push.
 *
 * Return: Nothing.
 */

void _mul(stack_t **stack, UNUSED unsigned int line_number)
{
	if (*stack != NULL)
	{
		for (; (*stack)->next->next; stack = &(*stack)->next)
			;
		(*stack)->n *= (*stack)->next->n;
		_pop(stack, 0);
	}
}
