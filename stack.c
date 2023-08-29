#include <stdio.h>
#include <stdbool.h>

// Structure to define the stack
typedef struct {
    char data[100];
    int top;
} Stack;

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack *stack) {
    return stack->top == 99;
}

// Function to push an element onto the stack
void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = item;
    printf("Pushed %c onto the stack.\n", item);
}

// Function to pop an element from the stack
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    char item = stack->data[stack->top--];
    return item;
}

// Function to display the elements in the stack
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%c\n", stack->data[i]);
    }
}

int main() {
    Stack stack;
    stack.top = -1; // Initialize the top of the stack

    int choice;
    char item;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to push onto the stack: ");
                scanf(" %c", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != '\0') {
                    printf("Popped %c from the stack.\n", item);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

