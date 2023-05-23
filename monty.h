#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define QUEUE 1
#define STAACK 0
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct monty_stack_s {
    int *data;
    int top;
} monty_stack_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void monty_push(stack_t *stack, int value);
int monty_pop(stack_t *stack);
void monty_pall(stack_t *stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
/* Opcode instruction table */
extern instruction_t opcodes[];
instruction_t opcodes[] = {
        {"push", monty_push},
        {"pop", monty_pop},
        {"pall", monty_pall},
        {"pint", pint}, /* Add the pint opcode here */
        {NULL, NULL}
};
#endif /* _MONTY_H_ */
