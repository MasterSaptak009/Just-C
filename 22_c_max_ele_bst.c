/*
Implement following functions for Binary Search Trees

    c. Maximum element of the BST

*/


#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with the given data into the BST
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the maximum element in the BST
int findMax(struct TreeNode* root) {
    if (root == NULL) {
        printf("BST is empty\n");
        return -1; // Assuming -1 as an invalid value for an empty tree
    }

    // Traverse to the rightmost node
    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}

// Function to free the memory allocated for the tree nodes
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    // Example usage
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int maxElement = findMax(root);

    if (maxElement != -1) {
        printf("Maximum element in the BST: %d\n", maxElement);
    }

    // Free the allocated memory
    freeTree(root);

    return 0;
}
