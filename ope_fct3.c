#include "monty.h"

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	node = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(node);
}



/**
 * divs - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void divs(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	node = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(node);
}



/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	node = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(node);
}



/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	node = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(node);
}
