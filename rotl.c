#include "monty.h"

/**
 * _rotl - Rotates the stack to the top.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Description: The rotl opcode rotates the stack to the top.
 * The top element of the stack becomes the last one, and the second
 * top element becomes the first one.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second = NULL;

	(void)line_number;

	if (top != NULL && top->next != NULL)
	{
		second = top->next;
		while (top->next != NULL)
			top = top->next;

		top->next = *stack;
		(*stack)->prev = top;
		(*stack)->next = NULL;
		*stack = second;
		second->prev = NULL;
	}
}
