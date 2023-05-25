#include <stdio.h>
#include "monty.h"

/**
 * _stack - Prints the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction (unused).
 */
void _stack(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (*stack == NULL)
	{
		printf("Stack is empty\n");
		return;
	}

	printf("Top element: %d\n", (*stack)->data);
}
