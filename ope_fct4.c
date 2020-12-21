#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}
	val = (*stack)->n;
	if (isascii(val) == 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		param.lastexit = EXIT_FAILURE;
		return;
	}

	putchar(val);
	putchar('\n');
}




/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head;

	head = *stack;

	while (head != NULL)
	{
		if (head->n == 0 || isascii(head->n) == 0)
		{
			putchar('\n');
			return;
		}

		putchar(head->n);
		head = head->next;
	}

	putchar('\n');
}




/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{

}
