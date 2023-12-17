#include "monty.h"

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
	stack_t *new_item, *tmp = *head;

	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_error(*head);
	}
	new_item->n = n;
	new_item->next = NULL;

	if (*head == NULL)
	{
		new_item->prev = NULL;
		*head = new_item;
		return (new_item);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_item;
	new_item->prev = tmp;
	new_item->next = NULL;
	return (new_item);
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
