#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int ele) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = ele;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack.\n", ele);
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return -1;
    }
    struct node *ptr = top;
    int value = ptr->data;
    top = top->next;
    free(ptr);
    printf("%d popped from stack.\n", value);
    return value;
}

int peek() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return -1;
    }
    printf("Top element: %d\n", top->data);
    return top->data;
}

void display() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    struct node *ptr = top;
    printf("Stack elements (top to bottom): ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isEmpty() {
    return top == NULL;
}

int main() {
    push(1);
    push(2);
    push(3);
    display();
    peek();
    pop();
    display();
    return 0;
}
