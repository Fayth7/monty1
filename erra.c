#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1024

typedef struct {
    int *data;
    int top;
} Stack;

void push(Stack *stack, int value);
void pall(Stack *stack);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Can't open file %s\n", filename);
        return EXIT_FAILURE;
    }

    char line[256];
    int line_number = 1;
    Stack stack;
    stack.data = malloc(STACK_SIZE * sizeof(int));
    stack.top = -1;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';  // Remove trailing newline

        char *opcode = strtok(line, " ");
        char *argument = strtok(NULL, " ");

        if (opcode == NULL) {
            line_number++;
            continue;
        }

        if (strcmp(opcode, "push") == 0) {
            if (argument == NULL) {
                printf("L%d: usage: push integer\n", line_number);
                free(stack.data);
                return EXIT_FAILURE;
            }

            int value = atoi(argument);
            push(&stack, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else {
            printf("L%d: unknown instruction %s\n", line_number, opcode);
            free(stack.data);
            return EXIT_FAILURE;
        }

        line_number++;
    }

    fclose(file);
    free(stack.data);

    return EXIT_SUCCESS;
}

void push(Stack *stack, int value) {
    if (stack->top == STACK_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }

    stack->data[++stack->top] = value;
}

void pall(Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}
