#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* parsing */
int read_file(char *fname, stack_t **stack);
char *parse(char *lineptr);

/* list manuplation */
size_t print_list(stack_t *head);
size_t list_len(const stack_t *head);
stack_t *add_node(stack_t **head, const int n);
stack_t *add_node_end(stack_t **head, const int n);
stack_t *get_node_at_index(stack_t *head, unsigned int index);

/*handle */
void error_handler(stack_t **stack, FILE *file, int *op, char *opcode);
void logError(unsigned int line_cnt, const char *function, const char *file, const char *message);
void logSuccess(const char *message);

/* runing */
void run(stack_t **stack, char *str, unsigned int line_cnt);
void freeStack(stack_t *stack);

#endif
