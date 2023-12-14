#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * run - Execute Monty opcodes based on the input string.
 * @stack: Pointer to the stack data structure.
 * @str: Opcode string to compare.
 * @line_cnt: Line number in the Monty script.
 *
 * Return: Nothing.
 */
void run(stack_t **stack, char *str, unsigned int line_cnt)
{
    int i = 0;

    instruction_t op[] = {
        {"push", push},
        {"pall", pall},
        {"pop", pop},
        // Add more opcode-function pairs as needed
        {NULL, NULL} // Terminate the array
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

    fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
    status = EXIT_FAILURE; /* not declared */
}


/**
 * freeStack - Free the memory allocated for a stack linked list.
 * @stack: Pointer to the stack data structure.
 *
 * Return: Nothing.
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
