#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *addToEmpty(struct node *head, int data) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    head = temp;
    return head;
}

void printList(struct node *head) {
    struct node *ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
    return;
}

struct node *insertAtBegining(struct node *head, int data) {
    if(head == NULL) {
        return addToEmpty(head, data);
    }
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    return head;
}

struct node *insertAtEnd(struct node *head, int data) {
    if(head == NULL) {
        return addToEmpty(head, data);
    }
    struct node *ptr = head;
    while(ptr -> next != NULL) {
        ptr = ptr -> next;
    }
    struct node *temp = (struct node *) malloc (sizeof(struct node));
    temp -> prev = ptr;
    temp -> data = data;
    temp -> next = NULL;
    ptr -> next = temp;
    return head;
}

struct node *insertAfterPosition(struct node *head, int data, int position) {

    if (position < 1) {
        printf("Invalid position number.\n");
        return head;
    }

    // Case 1: Empty list
    if (head == NULL) {
        if (position == 1) {
            return addToEmpty(head, data);
        } else {
            printf("Cannot insert. List is empty.\n");
            return head;
        }
    }

    // Traverse to given position
    struct node *ptr = head;
    int count = 1;

    while (count < position && ptr != NULL) {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    // Case 2: Insert after last node
    if (ptr->next == NULL) {
        return insertAtEnd(head, data);
    }

    // Case 3: Insert in middle
    struct node *ptr2 = ptr->next;

    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;

    temp->prev = ptr;
    temp->next = ptr2;

    ptr->next = temp;
    ptr2->prev = temp;

    return head;
}

struct node *deleteAtBegining(struct node *head) {
    // If the list is empty 
    if(head == NULL) {
        printf("The list is already empty.\n");
        return head;
    } 
    struct node *ptr = head -> next;
    // If there is only one node in the list 
    if(ptr == NULL) {
        free(head);
        return NULL;
    }
    // For more than one nodes
    ptr -> prev = NULL;
    head -> next = NULL;
    free(head);
    return ptr;
}

struct node* deleteAtEnd(struct node *head) {
    // If the list is empty 
    if(head == NULL) {
        printf("The list is already empty.\n");
        return head;
    }
    struct node *ptr = head;
    // If we have only one node in the list
    if(ptr -> next == NULL) {
        free(head);
        return NULL;
    }
    // If we have more than two nodes in the list 
    while(ptr -> next != NULL) {
        ptr = ptr -> next;
    }
    struct node *temp = ptr -> prev;
    temp -> next = NULL;
    free(ptr);
    return head;
}

struct node *deleteAtPosition(struct node *head, int position) {
    // If the list is empty 
    if(head == NULL) {
        printf("The list is already empty.\n");
        return head;
    }
    // If the position is <= 1 
    if(position < 1) {
        printf("Invalid position.\n");
        return NULL;
    }
    // Delete the first node 
    if(position == 1) {
        return deleteAtBegining(head);
    }
    struct node *ptr = head;
    // Get the node at the position 
    while(position != 1 && ptr != NULL) {
        ptr = ptr -> next;
        position--;
    }
    // Posotion out of range 
    if(ptr == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }
    // Delete the last node 
    if(ptr -> next == NULL) {
        ptr -> prev -> next = NULL;
        free(ptr);
        return head;
    }
    // Delete the required node 
    ptr -> prev -> next = ptr -> next;
    ptr -> next -> prev = ptr -> prev;
    free(ptr);
    return head;
}

struct node *reverse(struct node *head) {
    if(head == NULL) {
        return NULL;
    }
    struct node *curr = head;
    struct node *temp = NULL;
    while(curr != NULL) {
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }
    if(temp != NULL) {
        head = temp -> prev;
    }
    return head;
}

int main() {
    struct node *head = NULL;
    head = addToEmpty(head, 10);
    printList(head);

    head = insertAtBegining(head, 20);
    head = insertAtBegining(head, 30);
    printList(head);

    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    printList(head);

    head = insertAfterPosition(head, 70, 2);
    printList(head);

    head = deleteAtBegining(head);
    head = deleteAtBegining(head);
    printList(head);

    head = deleteAtEnd(head);
    printList(head);

    head = deleteAtPosition(head, 2);
    printList(head);
    
    head = reverse(head);
    printList(head);
    return 0;
}