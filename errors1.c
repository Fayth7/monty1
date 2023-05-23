#include "monty.h"
#define STACK_SIZE 1024

/**
 * Main - prints usage error messages
 * Return: EXIT FAILURE always
 */

void push(monty_stack_t *stack, int value);
int pop(monty_stack_t *stack);
void pall(monty_stack_t *stack);

int main(int argc, char *argv[])
{
if (argc != 2)
{
printf("USAGE: monty file\n");
return (EXIT_FAILURE);
}

char *filename = argv[1];
FILE *file = fopen(filename, "r");
if (file == NULL)
{
printf("Error: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}

char line[256];
int line_number = 1;
monty_stack_t stack;
stack.data = malloc(STACK_SIZE * sizeof(int));
stack.top = -1;

while (fgets(line, sizeof(line), file))
{
line[strcspn(line, "\n")] = '\0';

char *opcode = strtok(line, " ");
char *argument = strtok(NULL, " ");

if (opcode == NULL)
{
line_number++;
continue;
}

if (strcmp(opcode, "push") == 0)
{
if (argument == NULL)
{
printf("L%d: usage: push integer\n", line_number);
free(stack.data);
return (EXIT_FAILURE);
}

int value = atoi(argument);
push(&stack, value);
}
else if
(strcmp(opcode, "pall") == 0)
{
pall(&stack);
}
else
{
printf("L%d: unknown instruction %s\n", line_number, opcode);
free(stack.data);
return (EXIT_FAILURE);
}

line_number++;
}
fclose(file);
free(stack.data);
return (EXIT_SUCCESS);
}
/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @value: Value to be pushed.
 *
 * Description: This function pushes an element with the given value to the stack.
 */
void push(monty_stack_t *stack, int value)
{
if (stack->top == STACK_SIZE - 1)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}

stack->data[++stack->top] = value;
}
/**
 * pop - Pops an element from the stack.
 * @stack: Pointer to the stack.
 *
 * Description: This function pops the top element from the stack and returns its value.
 * If the stack is empty, it prints an error message and exits the program.
 *
 * Return: The value of the popped element.
 */
int pop(monty_stack_t *stack)
{
if (stack->top == -1)
{
printf("Error: stack is empty\n");
exit(EXIT_FAILURE);
}
return (stack->data[stack->top--]);
}
/**
 * pall - Prints all elements in the stack.
 * @stack: Pointer to the stack.
 *
 * Description: This function prints all the elements in the stack, starting from the top.
 * If the stack is empty, it does not print anything.
 */
void pall(monty_stack_t *stack)
{
for (int i = stack->top; i >= 0; i--)
{
printf("%d\n", stack->data[i]);
}
}
