#include "monty.h"

/**
 * push - push an element onto the stack/queue
 * @stack: pointer to the head of the stack
 * @val: value token
 * @ln: line number
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
void push(stack_t **stack, char *val, unsigned int ln)
{
	unsigned int i = 0;

	if (val == NULL || val[0] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	i = 0;
	if (val[i] == '-')
		i++;
	for (; i < strlen(val); i++)
	{
		if (isdigit(val[i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", ln);
			param.lastexit = EXIT_FAILURE;
			return;
		}
	}
	if (param.stacktype == 0)
		add_node(stack, atoi(val));
	else
		add_node_end(stack, atoi(val));

}



/**
 * add_node - add a new node
 * @head: head of stack
 * @val: value
 *
 * Return: the address of new element, or NULL if fail
 */
stack_t *add_node(stack_t **head, const int val)
{
	stack_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		param.lastexit = EXIT_FAILURE;
		return (NULL);
	}
	new->n = val;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;

	return (*head);
}



/**
 * add_node_end - add a new node
 * @head: head of stack
 * @val: value
 *
 * Return: the address of new element, or NULL if fail
 */
stack_t *add_node_end(stack_t **head, const int val)
{
	stack_t *new;
	stack_t *nextadr;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		param.lastexit = EXIT_FAILURE;
		return (NULL);
	}

	new->n = val;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	nextadr = *head;
	while (nextadr->next != NULL)
		nextadr = nextadr->next;

	nextadr->next = new;
	new->prev = nextadr;

	return (new);
}
