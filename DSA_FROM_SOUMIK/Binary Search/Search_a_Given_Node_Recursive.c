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
struct Node *searchKey(struct Node *root,int key){
    if(root==NULL || root->data==key){
        return root;
    }
    if(root->data<key){
        return searchKey(root->right,key);
    }
    return searchKey(root->left,key);
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
    int key;
    printf("Enter the key to be found = ");
    scanf("%d",&key);
    if(searchKey(root,key)==NULL){
        printf("Not Found!");
    }
    else{
        printf("%d found",key);
    }
}