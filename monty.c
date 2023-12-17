/*
#include "monty.h"

/**
  * main - entery functions
  *
  * @argc: number of arguments
  *
  * @argv: array of arguments
  *
  * Return: success (0) or error code
  */
  /*
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	read_file(argv[1], &stack);
	freeStack(stack);

	return (EXIT_SUCCESS);
}
   **/
#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        bus.content = content;
        counter++;

        if (read_line > 0)
        {
            execute(content, &stack, counter, file);
        }

        free(content);
    }

    fclose(file);
    freestack(stack);  /

    return (EXIT_SUCCESS);
}
