#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction.
 */

void add(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
if (*stack == NULL || (*stack)->next == NULL) {
printf("L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
temp = *stack;
(*stack)->next->data += (*stack)->data;
   
*stack = (*stack)->next;
free(temp);
}
