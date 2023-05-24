#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Description: The nop opcode doesn't perform any operation
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
