#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

int isEmpty() {
    if(front == NULL) {
        return 1;
    }
    return 0;
}

int isFull() {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        return 1;  
    }
    free(temp);
    return 0;
}

void enqueue(int data) {
    if (isFull()) {
        printf("The queue is full (no memory).\n");
        return;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d is inserted into the queue.\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("The queue is empty.\n");
        return;
    }
    struct node* temp = front;
    printf("%d is removed from the queue\n", front->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;   
    }
    free(temp);
}

void display() {
    if (isEmpty()) {
        printf("The queue is empty.\n");
        return;
    }
    printf("The queue elements are: ");
    struct node* ptr = front;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void peek() {
    if (isEmpty()) {
        printf("The queue is empty.\n");
        return;
    }
    printf("The front element of the queue is: %d\n", front->data);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
    return 0;
}