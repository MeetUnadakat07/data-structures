#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int index;
    struct node *next;
};

struct node *insert(struct node *head, int coeff, int index) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->coeff = coeff;
    newNode->index = index;
    newNode->next = NULL;

    // Insert at beginning or before head
    if (head == NULL || index > head->index) {
        newNode->next = head;
        return newNode;
    }

    struct node *ptr = head;

    // Traverse to find correct position
    while (ptr->next != NULL && ptr->next->index > index) {
        ptr = ptr->next;
    }

    // If index already exists, add coefficients
    if (ptr->next != NULL && ptr->next->index == index) {
        ptr->next->coeff += coeff;
        free(newNode);
    } else {
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    return head;
}

struct node *create(struct node *head) {
    int n, coeff, index;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &coeff);

        printf("Enter the index for term %d: ", i + 1);
        scanf("%d", &index);

        head = insert(head, coeff, index);
    }

    return head;
}

void print(struct node *head) {
    if (head == NULL) {
        printf("No polynomial.\n");
        return;
    }

    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%dx^%d", ptr->coeff, ptr->index);
        ptr = ptr->next;
        if (ptr != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void polyAdd(struct node *head1, struct node *head2) {
    if(head1 == NULL || head2 == NULL) {
        printf("Enter valid polynomials.\n");
        return;
    }
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 -> index == ptr2 -> index) {
            head3 = insert(head3, ptr1 -> coeff + ptr2 -> coeff, ptr1 -> index);
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        } else if(ptr1 -> index > ptr2 -> index) {
            head3 = insert(head3, ptr1 -> coeff, ptr1 -> index);
            ptr1 = ptr1 -> next;
        } else {
            head3 = insert(head3, ptr2 -> coeff, ptr2 -> index);
            ptr2 = ptr2 -> next;
        }
    }
    while(ptr1 != NULL) {
        head3 = insert(head3, ptr1 -> coeff, ptr1 -> index);
        ptr1 = ptr1 -> next;
    }
    while(ptr2 != NULL) {
        head3 = insert(head3, ptr2 -> coeff, ptr2 -> index);
        ptr2 = ptr2 -> next;
    }
    printf("The added polynomial is: \n");
    print(head3);
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    printf("Enter the polynomial 1\n");
    head1 = create(head1);
    printf("Enter the polynomial 2\n");
    head2 = create(head2);

    printf("Polynomial 1: ");
    print(head1);
    printf("Polynomial 2: ");
    print(head2);

    polyAdd(head1, head2);

    return 0;
}
