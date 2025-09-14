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
    printf("\n");
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

void *insertAtPosition(struct node *head, int data, int position) {
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    if(position == 1) {
        temp -> link = head;
        head = temp;
        return head;
    } else if(head == NULL) {
        insertAtBegining(head, data);
    } else {
        while(position != 2) {
            ptr = ptr -> link;
            position--;
        }
        temp -> link = ptr -> link;
        ptr -> link = temp;
    }
}

struct node *deleteAtBegining(struct node *head) {
    if(head == NULL) {
        printf("List is already empty.\n");
    } else {
        struct node *temp = head;
        head = head -> link;
        free(temp);
        temp = NULL;
    }
    return head;
}

struct node *deleteAtEnd(struct node *head) {
    if(head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    } else if(head -> link == NULL) {
        free(head);
        return NULL;
    } else {
        struct node *temp = head;
        while(temp -> link -> link != NULL) {
            temp = temp -> link;
        }
        free(temp -> link);
        temp -> link = NULL;
        return head;
    }
}

struct node *deleteAtPosition(struct node *head, int position) {
    struct node *prev = head;
    struct node *curr = head;
    if(head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    } else if(position == 1) {
        return deleteAtBegining(head);
    } else {
        while(position != 1) {
            prev = curr;
            curr = curr -> link;
            position--;
        }
        prev -> link = curr -> link;
        free(curr);
        return head;
    }
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    insertAtEnd(head, 98);
    insertAtEnd(head, 34);

    printf("The elements of the list are: ");
    printData(head);

    head = insertAtBegining(head, 56);
    printData(head);
    countOfNodes(head);

    head = insertAtPosition(head, 48, 1);
    printData(head);

    head = deleteAtBegining(head);
    printData(head);

    head = deleteAtEnd(head);
    printData(head);

    head = deleteAtPosition(head, 2);
    printData(head);
    return 0;
}