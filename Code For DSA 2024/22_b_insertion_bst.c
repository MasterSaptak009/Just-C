/*
    Implement following functions for Binary Search Trees
        b. Insertion of a new node

*/


#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    // If the tree is empty, create a new node and return it as the new root
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recursively insert the node in the appropriate subtree
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    // Return the root of the modified tree
    return root;
}

// Function to perform an in-order traversal of the BST
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the memory allocated for the tree nodes
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Driver program to test the implementation
int main() {
    struct TreeNode* root = NULL;

    // Inserting nodes into the BST
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Displaying the in-order traversal of the BST
    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Freeing the memory allocated for the tree nodes
    freeTree(root);

    return 0;
}
