#include <stdio.h>
#include <stdlib.h>

//Representation of a Node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Creation of a Node
struct node* createnode(int value) {
    // Allocate memory for a new node
    struct node* newNode = malloc(sizeof(struct node));
    // Assign value to the node
    newNode->data = value;
    // Initialize left and right children as NULL
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Insert Node at Left Side
struct node* insertleft(struct node* root, int value) {
    // Create a new node and attach it as the left child of the root
    root->left = createnode(value);
    return root->left;
}

//Insert Node at Right Side
struct node* insertright(struct node* root, int value) {
    // Create a new node and attach it as the right child of the root
    root->right = createnode(value);
    return root->right;
}

//Preorder traversal
struct node* preordertraversal(struct node* root) {
    // Base case: If root is NULL, return
    if(root == NULL) {
        return NULL;
    }
    // Print the data of the current node
    printf("%d ", root->data);
    // Traverse left subtree
    preordertraversal(root->left);
    // Traverse right subtree
    preordertraversal(root->right);
}

//Inorder Traversal
struct node* inordertraversal(struct node* root) {
    // Base case: If root is NULL, return
    if(root == NULL) {
        return NULL;
    }
    // Traverse left subtree
    inordertraversal(root->left);
    // Print the data of the current node
    printf("%d ", root->data);
    // Traverse right subtree
    inordertraversal(root->right);
}

//Postorder Traversal
struct node* postordertraversal(struct node* root) {
    // Base case: If root is NULL, return
    if(root == NULL) {
        return NULL;
    }
    // Traverse left subtree
    postordertraversal(root->left);
    // Traverse right subtree
    postordertraversal(root->right);
    // Print the data of the current node
    printf("%d ", root->data);
}

int main() {
    // Create the root node with value 1
    struct node* root = createnode(1);
    // Insert left child with value 2
    insertleft(root, 2);
    // Insert right child with value 3
    insertright(root, 3);
    // Insert left child of left child with value 4
    insertleft(root->left, 4);
    
    printf("Inorder traversal \n");
    // Print inorder traversal of the tree
    inordertraversal(root);

    printf("\nPreorder traversal \n");
    // Print preorder traversal of the tree
    preordertraversal(root);

    printf("\nPostorder traversal \n");
    // Print postorder traversal of the tree
    postordertraversal(root);
    
    return 0;
}
