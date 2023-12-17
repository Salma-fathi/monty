#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 200
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

extern FILE *monty_f;
/* parsing */
void read_file(char *fname, stack_t **stack);
char *parse(char *lineptr);

/* list manuplation */
stack_t *add_node(stack_t **head, const int n);
stack_t *add_node_end(stack_t **head, const int n);
stack_t *get_node_at_index(stack_t *head, unsigned int index);
void delete_node(stack_t **stack);
void freeStack(stack_t *stack);

/*handle error */
void exit_error(stack_t *stack);

/* handle argument */
int is_number(char *arg, unsigned int line_number);

/* runing */
void run(stack_t **stack, char *str, unsigned int line_cnt);
void freeStack(stack_t *stack);


/*      functions    */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
/* math */

#endif
