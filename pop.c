#include "monty.h"

/**
 * pop  - Removes the top element of the stack.
 * @stack:  points to stack
 * @line_number: Line number where the opcode is encountered.
 */
void pop(stack_t **stack, unsigned int line_number);
{
if ((*stack)->top == -1)
{
printf("Error: stack is empty\n");
exit(EXIT_FAILURE);
}
(*stack)->top--;
}
