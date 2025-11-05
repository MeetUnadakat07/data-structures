#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
};

void preorder(struct node *root) {
    if(root != NULL) {
        printf("%d ", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
};

void postorder(struct node *root) {
    if(root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ", root -> data);
    }
};

void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root -> right);
    }
};

int isBST(struct node *root) {
    static struct node *prev = NULL;
    if(root != NULL) {
        if(!isBST(root -> left)) {
            return 0;
        } 
        if(prev != NULL && root -> data < prev -> data) {
            return 0;
        }
        prev = root;
        return isBST(root -> right);
    } else {
        return 1;
    }
}

struct node *search(struct node *root, int key) {
    if(root == NULL) {
        return NULL;
    } else if (root -> data == key) {
        return root;
    } else if(root -> data > key) {
        return search(root -> left, key);
    } else {
        return search(root -> right, key);
    }
}

struct node *searchIter(struct node *root, int key) {
    while (root != NULL) {
        if(root -> data == key) {
            return root;
        } else if(key < root -> data) {
            root = root -> left;
        } else {
            root = root -> right;
        }
    }
    return NULL;
}

void insert(struct node *root, int key) {
    struct node *prev = NULL;
    while(root != NULL) {
        prev = root;
        if(key == root -> data) {
            printf("Cannot inseert, %d already in tree\n", key);
            return;
        } else if(key < root -> data) {
            root = root -> left;
        } else {
            root = root -> right;
        }
    } 
    struct node *new = createNode(key);
    if(key < prev -> data) {
        prev -> left = new;
    } else {
        prev -> right = new;
    }
}

struct node *inorderPredecessor(struct node *root) {
    root = root -> left;
    while(root -> right != NULL) {
        root = root -> right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value) {
    struct node *iPre;

    if (root == NULL) {
        return NULL;
    }

    // If the node to delete is in the left subtree
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    // If the node to delete is in the right subtree
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    // Node found
    else {
        // Case 1: Node has no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node has only right child
        else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        // Case 3: Node has only left child
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 4: Node has two children
        else {
            iPre = inorderPredecessor(root);
            root->data = iPre->data;
            root->left = deleteNode(root->left, iPre->data);
        }
    }

    return root;
}


int main() {
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(1);
    struct node *p3 = createNode(4);
    struct node *p4 = createNode(6);

    p -> left = p1;
    p -> right = p4;
    p1 -> left = p2;
    p1 -> right = p3;

    /*
        5
       / \
      3   6
     / \
    1   4
    */

    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);
    printf("\n");
    if(isBST(p)) {
        printf("The tree is a BST\n");
    } else {
        printf("The tree is not a BST\n");
    }

    struct node *n = search(p, 4);
    if(n != NULL) {
        printf("Found: %d\n", n -> data);
    } else {
        printf("Element not found\n");
    }

    struct node *n2 = searchIter(p, 4);
    if(n2 != NULL) {
        printf("Found: %d\n", n2 -> data);
    } else {
        printf("Element not found\n");
    }

    inorder(p);
    printf("\n");
    deleteNode(p, 6);
    inorder(p);
}