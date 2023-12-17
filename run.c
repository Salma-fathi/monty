#include "monty.h"

/**
  * run - run the opcode
  *
  * @stack: stack
  *
  * @str: opcode string
  *
  * @line_cnt: line counter
  *
  * Return: nothings
  */
void run(stack_t **stack, char *str, unsigned int line_cnt)
{
	int i = 0;
	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_cnt);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_cnt, str);
	exit_error(*stack);
}
/**
  * freeStack - free the stack
  *
  * @stack: the stack
  *
  * Return: nothings
  */
void freeStack(stack_t *stack)
{
	stack_t *mirror = stack;

	while (stack)
	{
		stack = stack->next;
		free(mirror);
		mirror = stack;
	}
}
