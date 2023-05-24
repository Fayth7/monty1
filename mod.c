#include "monty.h"

/**
 * _mod - Computes the remainder of the division of the second top element
 *        by the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Description: The mod opcode computes the remainder of the division of the
 * second top element by the top element of the stack. The result is stored in
 * the second top element, and the top element is removed. If the stack contains
 * less than two elements or if the top element is 0, appropriate error messages
 * are printed.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
