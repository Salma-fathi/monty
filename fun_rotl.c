#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecodes file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;

    (void)line_number; 

    if (*stack != NULL && (*stack)->next != NULL)
    {
        temp = *stack;
        last = *stack;

        while (last->next != NULL)
            last = last->next;

        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        last->next = temp;
        temp->prev = last;
        temp->next = NULL;
    }
}

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty byte-code file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp, *last;

    (void)line_number;  // Unused parameter

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    tmp = *stack;
    last = *stack;

    // Find the last node in the stack
    while (last->next != NULL)
        last = last->next;

    // Update pointers to rotate the stack
    *stack = last;
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = tmp;
    tmp->prev = last;
}
