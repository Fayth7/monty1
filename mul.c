#include "monty.h"

/**
 * _mul - Multiplies the second top element with the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Description: The mul opcode multiplies the second top element of the stack
 * with the top element of the stack. The result is stored in the second top
 * element, and the top element is removed.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
