#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @top - stack head
 * line_number - line number in bytecode
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *top = *stack;
    int temp;

    if (top == NULL || top->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = top->n;
    top->n = top->next->n;
    top->next->n = temp;
}
