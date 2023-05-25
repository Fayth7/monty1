#include "monty.h"
#include <ctype.h>

int isascii(int c);

/**
 * _pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Description: prints the string starting at the top of the stack.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

(void)line_number;

while (current != NULL && current->n != 0 && isascii(current->n))
{
printf("%c", current->n);
current = current->next;
}

printf("\n");
}
