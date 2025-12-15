#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    if(front == -1) {
        return 1;
    }
    return 0;
}

int isFull() {
    if(rear == MAX -1) {
        return 1;
    }
    return 0;
}

void enqueue(int data) {
    if(isFull()) {
        printf("The queue is full.\n");
        return;
    } else if(isEmpty()) {
        front++; 
    }
    rear++;
    queue[rear] = data;
}

void dequeue() {
    if(isEmpty()) {
        printf("The queue is empty.\n");
        return;
    }
    printf("%d is removed from the queue\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if(isEmpty()) {
        printf("The list is empty.\n");
    } else {
        printf("The queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek() {
    if(isEmpty()) {
        printf("The queue is empty.\n");
        return;
    }
    printf("The front element of the queue is: %d\n", queue[front]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
}