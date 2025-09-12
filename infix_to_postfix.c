#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack_arr[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

// Stack operations
int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(char c) {
    if (isFull()) {
        printf("Stack overflow\n");
        return;
    }
    stack_arr[++top] = c;
}

char pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack_arr[top--];
}

char peep() {
    if (!isEmpty())
        return stack_arr[top];
    return '\0';
}

int precedence(char opr) {
    switch (opr) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isSpace(char c) {
    return c == ' ' || c == '\t';
}

void infixToPostfix() {
    int j = 0;
    char symbol;

    for (int i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        if (isSpace(symbol))
            continue;

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (!isEmpty() && peep() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peep() == '(')
                pop();  // Discard the '('
            else
                printf("Error: Mismatched parentheses\n");
        }
        else { // operator
            while (!isEmpty() && precedence(peep()) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    while (!isEmpty()) {
        if (peep() == '(' || peep() == ')') {
            printf("Error: Mismatched parentheses\n");
            pop(); // discard
        } else {
            postfix[j++] = pop();
        }
    }

    postfix[j] = '\0';
}

int main() {
    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove newline
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n')
        infix[len - 1] = '\0';

    infixToPostfix();

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
