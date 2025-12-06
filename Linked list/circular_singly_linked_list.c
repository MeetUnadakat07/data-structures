#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printList(struct node *head) {
    if(head == NULL) {
        return;
    }
    struct node *ptr = head;
    while(1) {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
        if(ptr == head) {
            break;
        }
    }
    printf("\n");
}

struct node* addToEmpty(struct node *head, int data) {
    struct node *ptr2 = (struct node *) malloc (sizeof(struct node));
    ptr2 -> data = data;
    ptr2 -> next = ptr2;
    head = ptr2;
    return head;
}

struct node *insertAtBegining(struct node*head, int data) {
    if(head == NULL) {
        return addToEmpty(head, data);
    }
    struct node *ptr2 = (struct node *) malloc (sizeof(struct node));
    ptr2 -> data = data;
    struct node *ptr = head;
    while(ptr -> next != head) {
        ptr = ptr -> next;
    }
    ptr -> next = ptr2;
    ptr2 -> next = head;
    head = ptr2;
    return head;
}

struct node *insertAtEnd(struct node *head, int data) {
    if(head == NULL) {
        return addToEmpty(head, data);
    }
    struct node *ptr2 = (struct node *) malloc (sizeof(struct node));
    ptr2 -> data = data;
    struct node *ptr = head;
    while(ptr -> next != head) {
        ptr = ptr -> next;
    }
    ptr -> next = ptr2;
    ptr2 -> next = head;
    return head;
}

struct node *deleteAtBegining(struct node *head) {
    if(head == NULL) {
        return NULL;
    }
    if(head -> next == head) {
        free(head);
        return NULL;
    }
    struct node *ptr = head;
    while(ptr -> next != head) {
        ptr = ptr -> next;
    }
    struct node *ptr2 = head;
    head = head -> next;
    ptr -> next = head;
    free(ptr2);
    return head;
}

struct node *deleteAtEnd(struct node *head) {
    if(head == NULL) {
        return NULL;
    }
    if(head -> next == head) {
        free(head);
        return NULL;
    }
    struct node *ptr = head;
    struct node *ptr2 = head -> next;

    while(ptr2 -> next != head) {
        ptr = ptr2;
        ptr2 = ptr2 -> next;
    }
    ptr -> next = head;
    free(ptr2);
    return head;
}

int main() {
    struct node *head = addToEmpty(head, 10);
    printList(head);

    head = insertAtBegining(head, 20);
    head = insertAtBegining(head, 30);
    printList(head);

    head = insertAtEnd(head, 50);
    printList(head);
    
    head = deleteAtBegining(head);
    printList(head);
    
    head = deleteAtEnd(head);
    printList(head);
}