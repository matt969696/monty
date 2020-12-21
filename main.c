#include "monty.h"

/**
 * main - main function
 * @ac: number of arguments
 * @av: list of arguments
 * Return: 0 on success, EXIT_FAILURE on error
 */
int main(int ac, char **av)
{
	char *token = NULL, ope[1024];
	size_t len = 0;
	ssize_t read;
	unsigned int ln = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	param.file = fopen(av[1], "r");
	if (param.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	param.lastexit = 0;
	param.stacktype = 0;
	while ((read = getline(&param.line, &len, param.file)) != -1)
	{
		ln++;
		token = strtok(param.line, "\n\t\r ");
		if (token == '\0')
			continue;
		if (token == NULL || token[0] == '#' || strcmp(token, "nop") == 0)
			continue;
		strcpy(ope, token);
		if (strcmp(ope, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			push(&stack, token, ln);
		}
		else
			exec_func(ope, &stack, ln);
		if (param.lastexit != 0)
			break;
	}
	properexit(stack);
	return (param.lastexit);
}


/**
 * properexit - exit the stack program
 * @stack: stack to free
 * Return: Void
 */
void properexit(stack_t *stack)
{
	stack_t *hnext;

	while (stack != NULL)
	{
		hnext = stack->next;
		free(stack);
		stack = hnext;
	}

	free(param.line);
	fclose(param.file);
}





/**
 * exec_func - execute a simple function
 * @ope: name of the command
 * @stack: current stack
 * @ln: line number
 * Return: 0 on success, EXIT_FAILURE on error
 */

void exec_func(char *ope, stack_t **stack, unsigned int ln)
{
	int i = 0;

	instruction_t inst[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"sub", sub}, {"div", divs}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
		{NULL, NULL}
	};

	if (strcmp(ope, "stack") == 0)
	{
		param.stacktype = 0;
		return;
	}
	if (strcmp(ope, "queue") == 0)
	{
		param.stacktype = 1;
		return;
	}
	while (inst[i].opcode)
	{
		if (strcmp(ope, inst[i].opcode) == 0)
		{
			inst[i].f(stack, ln);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", ln, ope);
	param.lastexit = EXIT_FAILURE;
}




/**
 * pall - prints all the values on the stack, starting with the top
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
