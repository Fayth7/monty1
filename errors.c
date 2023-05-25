#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define STACK_SIZE 1024

void push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

int main(int argc, char *argv[])
{
    char *filename;
    char line[256];
    int line_number = 1;
    stack_t *stack = NULL;
    char *opcode;
    char *argument;
    FILE *file;
    int value = 0;
    
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    filename = argv[1];
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", filename);
        return (EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = '\0';

        opcode = strtok(line, " ");
        if (opcode == NULL)
        {
            line_number++;
            continue;
        }

        argument = strtok(NULL, " ");

        if (strcmp(opcode, "push") == 0)
        {
            if (argument == NULL)
            {
                printf("L%d: usage: push integer\n", line_number);
                fclose(file);
                _stack(&stack, line_number);
                return (EXIT_FAILURE);
            }
	    value = atoi(argument);
    push(&stack, value);
    }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(&stack, line_number);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(&stack, line_number);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap(&stack, line_number);
        }
        else
        {
            printf("L%d: unknown instruction %s\n", line_number, opcode);
            _stack(&stack, line_number);
            fclose(file);
            return (EXIT_FAILURE);
        }

        line_number++;
    }

    _stack(&stack, line_number);
    fclose(file);
    return (EXIT_SUCCESS);
}
void push(stack_t **stack, int value)
{
stack_t *new_node;
if (*stack == NULL)
{
*stack = malloc(sizeof(stack_t));
if (*stack == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}
(*stack)->n = value;
(*stack)->next = NULL;
return;
}
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->next = *stack;
*stack = new_node;
}

void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
if (*stack == NULL)
{
printf("L%d: can't pop, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
*stack = (*stack)->next;
free(temp);
}
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current;
current = *stack;

(void)line_number;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
printf("L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}
void swap(stack_t **stack, unsigned int line_number)
{
int temp;
if (*stack == NULL || (*stack)->next == NULL)
{
printf("L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}
