#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	printf("%d\n", (*stack)->n);
}



/**
 * pop - removes the top element of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	node = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(node);
}



/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;
	int val1;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	node1 = *stack;
	node2 = (*stack)->next;
	val1 = node1->n;
	node1->n = node2->n;
	node2->n = val1;
}



/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	node = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(node);
}
