#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct node *ptr = head;
    while (ptr->next != NULL && ptr->next->data <= value) {
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

int deleteMin() {
    if (head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = head->data;
    struct node *temp = head;
    head = head->next;
    free(temp);

    return value;
}

void display() {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
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
