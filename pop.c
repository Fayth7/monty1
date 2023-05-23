#include "monty.h"

/**
 * f_pop - Removes the top element of the stack.
 * @head: Double pointer to the stack (top of the stack).
 * @counter: Line number where the opcode is encountered.
 */
void f_pop(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}
