#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100

// Stack implementation
struct Stack {
    char arr[MAX_SIZE];
    int top;
};

// Initialize stack
void init(struct Stack *s) {
    s->top = -1;
}

// Push a character onto the stack
void push(struct Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// Pop a character from the stack
char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty. Cannot pop element.\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

// Check if a given string is palindrome using stack
bool isPalindrome(char *str) {
    int length = strlen(str);
    struct Stack s;
    init(&s);

    for (int i = 0; i < length; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < length; i++) {
        if (pop(&s) != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
