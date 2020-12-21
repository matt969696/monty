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


/**
 * struct param_s - contains parameters infos
 * @file: name of the file
 * @line: read line
 * @stacktype: 0 for stack, 1 for queue
 * @lastexit: 0 for ok, EXIT_FAILURE if error
 *
 * Description: global parameter struct
 */
typedef struct param_s
{
	FILE *file;
	char *line;
	int stacktype;
	int lastexit;
} param_t;

param_t param;


/* main.c */
int main(int ac, char **av);
void properexit(stack_t *stack);
void exec_func(char *ope, stack_t **stack, unsigned int ln);
void pall(stack_t **stack, unsigned int line_number);

/* ope_fct1.c */
void push(stack_t **stack, char *val, unsigned int ln);
stack_t *add_node(stack_t **head, const int val);
stack_t *add_node_end(stack_t **head, const int val);

/* ope_fct2.c */
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

/* ope_fct3.c */
void sub(stack_t **stack, unsigned int line_number);
void divs(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* ope-fct4.c */
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number);

#endif
