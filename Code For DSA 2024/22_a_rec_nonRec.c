/* 
    Implement following functions for Binary Search Trees
        a. Search a given item (Recursive & Non-Recursive)
*/


#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Search Tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new BST node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into BST
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Recursive function to search for a value in BST
struct TreeNode* searchRecursive(struct TreeNode* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return searchRecursive(root->left, value);
    else
        return searchRecursive(root->right, value);
}

// Non-recursive function to search for a value in BST
struct TreeNode* searchNonRecursive(struct TreeNode* root, int value) {
    while (root != NULL && root->data != value) {
        if (value < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// Function to print inorder traversal of BST
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    
    // Insert values into BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print inorder traversal of BST
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a value in BST (recursive)
    int searchValueRecursive = 40;
    struct TreeNode* resultRecursive = searchRecursive(root, searchValueRecursive);
    if (resultRecursive != NULL)
        printf("%d found in BST (recursive)\n", searchValueRecursive);
    else
        printf("%d not found in BST (recursive)\n", searchValueRecursive);

    // Search for a value in BST (non-recursive)
    int searchValueNonRecursive = 70;
    struct TreeNode* resultNonRecursive = searchNonRecursive(root, searchValueNonRecursive);
    if (resultNonRecursive != NULL)
        printf("%d found in BST (non-recursive)\n", searchValueNonRecursive);
    else
        printf("%d not found in BST (non-recursive)\n", searchValueNonRecursive);

    return 0;
}
