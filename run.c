#include <stdio.h>
#include <stdlib.h>
#include "monty.h"



int status = EXIT_SUCCESS;

void run(stack_t **stack, char *str, unsigned int line_cnt)
{
    int i = 0;

    instruction_t op[] = {
        {"push", push},
        {"pall", pall},
        {"pop", pop},
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
}

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
