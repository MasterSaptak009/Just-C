//Video - https://www.youtube.com/watch?v=S4mBBDfvWCE&t=167s
#include <stdio.h>
#define capacity 20
int stack[capacity]; // Define an array to store elements with a capacity of 20
int top1=-1,top2=capacity; // Initialize top pointers for two stacks

// Function to push element into stack 1
void push_stack1(int data){
    if(top2==top1+1){ // Check if there is space in the array for stack 1
        printf("Stack Overflow!!\n"); // Print error message if stack 1 is full
    }
    top1++; // Move the top pointer for stack 1
    stack[top1]=data; // Push the element into stack 1
}

// Function to push element into stack 2
void push_stack2(int data){
     if(top2==top1+1){ // Check if there is space in the array for stack 2
        printf("Stack Overflow!!\n"); // Print error message if stack 2 is full
    }
    top2--; // Move the top pointer for stack 2
    stack[top2]=data; // Push the element into stack 2
}

// Function to pop element from stack 1
void pop_stack1(){
    if(top1==-1){ // Check if stack 1 is empty
        printf("Underflow Condition!!\n"); // Print error message if stack 1 is empty
    }
    top1--; // Move the top pointer for stack 1
    printf("Popped Element is : %d\n",stack[top1]); // Print the popped element
}

// Function to pop element from stack 2
void pop_stack2(){
    if(top2==capacity){ // Check if stack 2 is empty
        printf("Underflow Condition!!\n"); // Print error message if stack 2 is empty
    }
    top2++; // Move the top pointer for stack 2
    printf("Popped element is : %d\n",stack[top2]); // Print the popped element
}

// Function to print elements of stack 1
void print_stack1 (){
    int i;
    for (i = top1; i >= 0; --i){ // Iterate over elements of stack 1
        printf ("%d ", stack[i]); // Print each element
    }
    printf ("\n");
}

// Function to print elements of stack 2
void print_stack2 (){
    int i;
    for (i = top2; i < capacity; ++i){ // Iterate over elements of stack 2
        printf ("%d ", stack[i]); // Print each element
    }
    printf ("\n");
}

// Main function
int main(){
    int ar[capacity];  // Array to store elements
    int i;  // Loop counter
    int num_of_ele;  // Variable to store number of elements
    
    printf ("We can push a total of 20 values\n");  
    
    // Pushing elements into stack 1
    for (i = 1; i <= 10; ++i){  
        push_stack1(i);  
        printf ("Value Pushed in Stack 1 is %d\n", i);  
    }  
    
    // Pushing elements into stack 2
    for (i = 11; i <= 20; ++i){  
        push_stack2(i);  
        printf ("Value Pushed in Stack 2 is %d\n", i);  
    }  
    
    // Print both stacks
    print_stack1 ();  
    print_stack2 ();  
    
    // Pushing into a full stack
    printf ("Pushing Value in Stack 1 is %d\n", 11);  
    push_stack1 (11);  
    
    // Popping all elements from stack 1
    num_of_ele = top1 + 1;  
    while (num_of_ele){  
        pop_stack1 ();  
        --num_of_ele;  
    }  
    
    // Trying to pop from an empty stack
    pop_stack1 ();  
    
    return 0;  
}
