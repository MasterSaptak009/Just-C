#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

//A function to create a new Node

struct Node *newNode(int data){
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}
struct Node *insert(struct Node *root,int data){
    if(root==NULL){
        return newNode(data);
    }
    if(data<root->data){
       root->left = insert(root->left,data);
    }
    else if(data>root->data){
    root->right=insert(root->right,data);
    }
    return root;
}
int minValue(struct Node* root)
{   
    /* loop down to find the rightmost leaf */
    struct Node* current = root;
    while (current->left != NULL) 
        current = current->left;
     
    return (current->data);
}
int main()
{
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Minimum value in this bst is = %d",minValue(root));
}