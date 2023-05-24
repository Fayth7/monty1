#include "monty.h"

/**
 * _rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Description: The rotr opcode rotates the stack to the bottom.
 * The last element of the stack becomes the top element of the stack.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *last = NULL;

	(void)line_number;

	if (top != NULL && top->next != NULL)
	{
		while (top->next != NULL)
			top = top->next;

		last = top;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
