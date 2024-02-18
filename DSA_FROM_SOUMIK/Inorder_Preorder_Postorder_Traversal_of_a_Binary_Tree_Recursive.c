#include <stdio.h>
#include<stdlib.h>

//Representation of a Node
struct node{
    int data;
    struct node *left;
    struct node *right;
};
// Creation of a Node
struct node* createnode(int value){
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

//Insert Node at Left Side
struct node* insertleft(struct node* root, int value) {
  root->left = createnode(value);
  return root->left;
}
//Insert Node at Right Side
struct node* insertright(struct node* root, int value) {
  root->right = createnode(value);
  return root->right;
}
//Preorder traversal
struct node* preordertraversal(struct node* root){
    if(root==NULL){
        return NULL;
    }
    printf("%d",root->data);
    preordertraversal(root->left);
    preordertraversal(root->right);
}
//Inorder Traversal
struct node* inordertraversal(struct node* root){
    if(root==NULL){
        return NULL;
    }
    inordertraversal(root->left);
    printf("%d",root->data);
    inordertraversal(root->right);
}
//Postorder Traversal
struct node* postordertraversal(struct node* root){
    if(root==NULL){
        return NULL;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    printf("%d",root->data);
}
int main()
{
   struct node* root=createnode(1);
   insertleft(root,2);
   insertright(root,3);
   insertleft(root->left,4);
    printf("Inorder traversal \n");
  inordertraversal(root);

  printf("\nPreorder traversal \n");
  preordertraversal(root);

  printf("\nPostorder traversal \n");
  postordertraversal(root);
    return 0;
}