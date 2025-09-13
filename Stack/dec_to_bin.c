#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack_arr[MAX];
int top = -1;

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

void printStack() {
    while(top != -1) {
        printf("%d", pop());
    }
}

void prime_fact(int num) {
    int i = 2;
    while(num != 1) {
        while(num % i == 0) {
            push(i);
            num /= i;
        }
        i++;
    }
    printStack();
}

void emptyStack() {
    for (int i = 0; i < MAX; i++) {
        stack_arr[i] = 0;  
    }
    top = -1;
    printf("Stack has been emptied.\n");
}

void decToBin(int dec) {
    while(dec != 0) {
        push(dec % 2);
        dec = dec / 2;
    }
    printStack();
}

int main() {
    int dec;
    printf("Enter a decimal number: ");
    scanf("%d", &dec);
    decToBin(dec);
}