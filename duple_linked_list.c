#include "monty.h"

/**
  * print_list - print the element in the list
  *
  * @head: head
  *
  * Return: number of the node
  */
size_t print_list(stack_t *head)
{
	size_t size = 0;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		size += 1;
	}
	return (size);
}
/**
  * list_len - find the length of the linked list
  * @head: the head
  * Return: the length
  */
size_t list_len(stack_t *head)
{
	size_t size = 0;

	while (head != NULL)
	{
		head = head->next;
		size++;
	}
	return (size);
}
/**
  * add_node - add new node
  * @head: head
  * @n: int
  * Return: the address of the new node
  */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new, *h;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	h = *head;
	new->n = n;
	new->next = h;
	new->prev = NULL;
	if (h != NULL)
		h->prev = new;
	*head = new;

	return (new);
}
/**
  * add_node_end - add to the end
  * @head: list head
  * @n: value
  * Return: address of new node
  */
stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new_item;

	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_error(*head);
	}
	new_item->n = n;
	new_item->next = NULL;

	if (*head == NULL)
		new_item->prev = NULL;
	else
	{
		for (; *head; head = &(*head)->next)
			new_item->prev = *head;
	}
	*head = new_item;
	return (*head);
}
/**
  * get_node_at_index - get node at the index
  * @head: head
  * @index: index of the node
  * Return: address of the node
  */
stack_t *get_node_at_index(stack_t *head, unsigned int index)
{
	size_t i = 0;

	while (head && i != index)
	{
		head = head->next;
		i++;
	}
	if (!head)
		return (NULL);
	return (head);
}
