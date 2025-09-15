#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    if(front == -1 && rear == -1) {
        return 1;
    } 
    return 0;
}

int isFull() {
    if((rear + 1) % MAX == front) {
        return 1;
    }
    return 0;
}

void enqueue(int value) {
    if (isFull()) {
        printf("The queue is full.\n");
        return;
    }
     else if(isEmpty()) {
        front = rear = 0;
    }  else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
}

void dequeue() {
    if(isEmpty()) {
        printf("The queue is already empty.\n");
        return;
    }
    printf("%d is removed from the list.\n", queue[front]);
    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if(isEmpty()) {
        printf("The queue is already empty.\n");
        return;
    }
    printf("The elements of the queue are: \n"); 
    if(front < rear) {
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for(int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for(int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
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
    enqueue(40);
    enqueue(50);  
    display();    
    enqueue(60);  
    dequeue();    
    dequeue();     
    display();  
    enqueue(60);   
    enqueue(70);   
    display();     
    peek();        
    dequeue();     
    dequeue();     
    dequeue();     
    dequeue();     
    dequeue();     
    display();
    dequeue();   
    return 0;
}