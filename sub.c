#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Description: The sub opcode subtracts the top element of the stack from second
 */
void sub(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}
