#include "monty.h"

/**
 * f_pint - Prints the value at the top of the stack.
 * @head: Double pointer to the stack (top of the stack).
 * @counter: Line number where the opcode is encountered.
 */
void f_pint(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*head)->n);
}
