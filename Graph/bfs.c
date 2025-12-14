#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int a[MAX][MAX];
int vis[MAX];
int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    if(front == -1) {
        return 1;
    }
    return 0;
}

int isFull() {
    if(rear == MAX - 1) {
        return 1;
    } 
    return 0;
}

void enqueue(int data) {
    if(isFull()) {
        printf("The queue is full\n");
        return;
    } 
    if(isEmpty()) {
        front = 0;
    }
    queue[++rear] = data;
}

int dequeue() {
    if(isEmpty()) {
        return -1;
    }
    int data = queue[front];
    front++;
    if(front > rear) {
        front = rear = -1;
    }
    return data;
}

void bfs(int start, int n) {
    enqueue(start);
    vis[start] = 1;

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for(int i = 1; i <= n; i++) {
            if(a[node][i] == 1 && vis[i] == 0) {
                enqueue(i);
                vis[i] = 1;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("Enter 1 if %d has a node with %d else 0: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("The adjacency matrix is\n");
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
    } 

    int s;
    printf("Enter the source vertex: ");
    scanf("%d", &s);

    printf("The bfs traversal is:\n");
    bfs(s, n);
    return 0;
}