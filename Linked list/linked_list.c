#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

void countOfNodes(struct node *head) {
    int count = 0;
    if(head == NULL) {
        printf("The list is empty\n");
    } 
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL) {
        count++;
        ptr = ptr -> link;
    }
    printf("The number of nodes is: %d\n", count);
}

void printData(struct node *head) {
    if(head == NULL) {
        printf("List is empty\n");
    } 
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> link;
    }
}

void insertAtEnd(struct node *head, int data) {
    struct node *ptr, *temp;
    temp = malloc(sizeof(struct node));
    ptr = head;
    temp -> data = data;
    temp -> link = NULL;
    while(ptr -> link != NULL) {
        ptr = ptr -> link;
    }
    ptr -> link = temp;
}

struct node *insertAtBegining(struct node *head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    temp -> data = data;
    temp -> link = head;
    return temp;
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    insertAtEnd(head, 98);
    insertAtEnd(head, 34);

    printf("The elements of the list are: ");
    printData(head);

    printf("\n");

    head = insertAtBegining(head, 56);
    printData(head);
    countOfNodes(head);
    return 0;
}