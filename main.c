#include "monty.h"

/**
 * main - main function
 * @ac: number of arguments
 * @av: list of arguments
 * Return: 0 on success, EXIT_FAILURE on error
 */
int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL, *token = NULL, ope[1024];
	size_t len = 0;
	ssize_t read;
	unsigned int ln = 0;
	stack_t *stack = NULL;
	int stacktype = 0, ret;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		ln++;
		token = strtok(line, "\n\t\r ");
		if (token == '\0')
			continue;
		if (token == NULL || token[0] == '#' || strcmp(token, "nop") == 0)
			continue;
		strcpy(ope, token);
		if (strcmp(ope, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			ret = push(&stack, token, ln, stacktype);
		}
		else
			ret = exec_func(ope, &stack, ln, &stacktype);
		if (ret != 0)
			break;
	}
	properexit(stack, file, line);
	return (ret);
}


/**
 * properexit - exit the stack program
 * @stack: stack to free
 * @file: file to close
 * @line: line to free
 * Return: Void
 */
void properexit(stack_t *stack, FILE *file, char *line)
{
	stack_t *hnext;

	while (stack != NULL)
	{
		hnext = stack->next;
		free(stack);
		stack = hnext;
	}

	free(line);
	fclose(file);
}





/**
 * exec_func - execute a simple function
 * @ope: name of the command
 * @stack: current stack
 * @ln: line number
 * @stacktype: type of stack
 * Return: 0 on success, EXIT_FAILURE on error
 */

int exec_func(char *ope, stack_t **stack, unsigned int ln, int *stacktype)
{
	int i = 0;

	instruction_t inst[] = {
		{"pall", pall},
		{NULL, NULL}
	};

	if (strcmp(ope, "stack") == 0)
	{
		*stacktype = 0;
		return (0);
	}

	if (strcmp(ope, "queue") == 0)
	{
		*stacktype = 1;
		return (0);
	}


	while (inst[i].opcode)
	{
		if (strcmp(ope, inst[i].opcode) == 0)
		{
			inst[i].f(stack, ln);
			return (0);
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", ln, ope);
	return (EXIT_FAILURE);
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
