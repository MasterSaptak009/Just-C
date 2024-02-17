/* Write a program using functions for binary tree traversals Pre-order, In-order and
Post-order using both Recursive and Non-recursive approach.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Recursive Pre-order traversal
void recursivePreOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        recursivePreOrder(root->left);
        recursivePreOrder(root->right);
    }
}

// Non-recursive Pre-order traversal
void nonRecursivePreOrder(struct Node* root) {
    // Use a stack for non-recursive traversal
    struct Node* stack[100]; // Assuming a maximum of 100 nodes
    int top = -1;

    while (root != NULL || top != -1) {
        while (root != NULL) {
            printf("%d ", root->data);
            stack[++top] = root;
            root = root->left;
        }

        root = stack[top--];
        root = root->right;
    }
}

// Recursive In-order traversal
void recursiveInOrder(struct Node* root) {
    if (root != NULL) {
        recursiveInOrder(root->left);
        printf("%d ", root->data);
        recursiveInOrder(root->right);
    }
}

// Non-recursive In-order traversal
void nonRecursiveInOrder(struct Node* root) {
    // Use a stack for non-recursive traversal
    struct Node* stack[100]; // Assuming a maximum of 100 nodes
    int top = -1;

    while (root != NULL || top != -1) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }

        root = stack[top--];
        printf("%d ", root->data);
        root = root->right;
    }
}

// Recursive Post-order traversal
void recursivePostOrder(struct Node* root) {
    if (root != NULL) {
        recursivePostOrder(root->left);
        recursivePostOrder(root->right);
        printf("%d ", root->data);
    }
}

// Non-recursive Post-order traversal
void nonRecursivePostOrder(struct Node* root) {
    // Use two stacks for non-recursive traversal
    struct Node* stack1[100]; // For storing nodes
    struct Node* stack2[100]; // For printing nodes in reverse post-order
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        root = stack1[top1--];
        stack2[++top2] = root;

        if (root->left != NULL) {
            stack1[++top1] = root->left;
        }

        if (root->right != NULL) {
            stack1[++top1] = root->right;
        }
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes into the binary tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Recursive Pre-order: ");
    recursivePreOrder(root);
    printf("\n");

    printf("Non-Recursive Pre-order: ");
    nonRecursivePreOrder(root);
    printf("\n");

    printf("Recursive In-order: ");
    recursiveInOrder(root);
    printf("\n");

    printf("Non-Recursive In-order: ");
    nonRecursiveInOrder(root);
    printf("\n");

    printf("Recursive Post-order: ");
    recursivePostOrder(root);
    printf("\n");

    printf("Non-Recursive Post-order: ");
    nonRecursivePostOrder(root);
    printf("\n");

    return 0;
}
