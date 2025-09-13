#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int top = -1;
int first = -1;

void push(int ele) {
    if(top == MAX - 1) {
        printf("Stack overflow");
        return;
    }
    top++;
    stack_arr[top] = ele;
}

int pop() {
    if(top == -1) {
        printf("Stack is empty");
        return -1;
    }
    int value = stack_arr[top];
    top--;
    return value;
}

// More efficient way to use push and pop  
void push_two(int ele) {
    first++;
    for(int i = first; i > 0; i--) {
        stack_arr[i] = stack_arr[i - 1];
    }
    stack_arr[0] = ele;
}

int pop_two() {
    int value = stack_arr[0];
    for (int i = 0; i < first; i++) {
        stack_arr[i] = stack_arr[i + 1];
    }
    first--;
    return value;
}

void printStack() {
    for(int i = 0; i <= top; i++) {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

void printStack_two() {
    for(int i = 0; i <= first; i++) {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

int main() {
    // push(5);
    // push(7);
    // push(9);
    // printStack();
    // pop();
    // pop();
    // printStack();
    push_two(30);
    push_two(90);
    push_two(40);
    printStack_two();
    printf("%d is popped", pop_two());
    printf("\n");
    printStack_two();
}