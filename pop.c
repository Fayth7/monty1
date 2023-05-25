#include "monty.h"

/**
 * pop  - Removes the top element of the stack.
 * @stack:  points to stack
 * @line_number: Line number where the opcode is encountered.
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL)
{
printf("Error: stack is empty\n");
exit(EXIT_FAILURE);
}

temp = *stack;
*stack = (*stack)->next;
if (*stack)
(*stack)->prev = NULL;
free(temp);
(void)line_number;
}
