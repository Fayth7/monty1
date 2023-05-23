#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 *
 * Description: prints the value at the top of the stack, followed by a new line.
 * If empty, it prints an error message and exits with EXIT_FAILURE.
 */
void pint(stack_t **stack)
{
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
