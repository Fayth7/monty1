#include "monty.h"

/**
 * _pchar - Prints the character at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Description: The pchar opcode prints the character at the top of the stack.
 * The integer stored at the top of the stack is treated as the ASCII value of
 * the character to be printed. If the value is not in the ASCII table, or if
 * the stack is empty, appropriate error messages are printed.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
