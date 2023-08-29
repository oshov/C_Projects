#include <stdio.h>
#define MAX_SIZE 100

// Stack implementation
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize stack
void init(struct Stack *s) {
    s->top = -1;
}

// Push an element onto the stack
void push(struct Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// Pop an element from the stack
int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Convert decimal to binary using stack
void decimalToBinary(int decimal) {
    struct Stack s;
    init(&s);

    while (decimal > 0) {
        push(&s, decimal % 2);
        decimal /= 2;
    }

    printf("Binary representation: ");
    while (s.top != -1) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}
