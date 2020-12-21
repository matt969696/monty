#ifndef _HOLB
#define _HOLB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/* main.c */
int main(int ac, char **av);
void properexit(stack_t *stack, FILE *file, char *line);
int exec_func(char *ope, stack_t **stack, unsigned int ln, int *stacktype);
void pall(stack_t **stack, unsigned int line_number);

/* ope_fct1.c */
int push(stack_t **stack, char *val, unsigned int ln, int stacktype);
stack_t *add_node(stack_t **head, const int val);
stack_t *add_node_end(stack_t **head, const int val);




#endif
