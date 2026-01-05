#include <stdio.h>

#define MAX 10

int pq[MAX];
int size = 0;

void insert(int value) {
    if (size == MAX) {
        printf("Queue is full\n");
        return;
    }
    pq[size++] = value;
}

int deleteMin() {
    if (size == 0) {
        printf("Queue is empty\n");
        return -1;
    }

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    int min = pq[minIndex];
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
    return min;
}

void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    insert(30);
    insert(10);
    insert(20);

    display();
    printf("Deleted: %d\n", deleteMin());
    display();

    return 0;
}
