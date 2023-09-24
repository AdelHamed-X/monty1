#include "monty.h"

/**
  * add_dnodeint - adds a new node at the beginning of a list
  * @head: double pointer
  * @n: the element of a new node
  * Return: the address of the new node
  */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new = NULL;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;

	if (!(*head))
	{
		*head = new;
		return (new);
	}

	if ((*head)->prev)
	{
		*head = (*head)->prev;
	}

	(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end
 * of a dlistint_t list
 *
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the new element
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *temp = *head;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
	{
		temp = temp->next;
	}

	new->prev = temp;
	temp->next = new;

	return (new);
}
