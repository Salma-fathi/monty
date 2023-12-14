


int status = EXIT_SUCCESS;

/**
 * The run function executes the specified opcode.
 * It takes a stack, an opcode string, and the line number as parameters.
 */
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
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar",_pchar},
		{"pstr",_pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack",_stack},
		{"queue",_queue},
        {NULL, NULL} /* Terminate the array */
    };

    if (stack == NULL)
    {
        logError(line_cnt, "Attempting to use a NULL stack. Check memory allocation or initialization.");
        status = EXIT_FAILURE;
        return;
    }

    while (op[i].opcode)
    {
        if (strcmp(op[i].opcode, str) == 0)
        {
            op[i].f(stack, line_cnt);
            return;
        }
        i++;
    }

    logError(line_cnt, "Unknown instruction");
    if (status == EXIT_SUCCESS)
    {
        logSuccess("Program executed successfully.");
    }
	int i = 0;
	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
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
 * The freeStack function frees the memory allocated for the stack.
 * It takes a pointer to the top of the stack as a parameter.
 */

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
