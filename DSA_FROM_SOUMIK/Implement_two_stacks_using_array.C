//Video - https://www.youtube.com/watch?v=S4mBBDfvWCE&t=167s

#include <stdio.h>
#define capacity 20
int stack[capacity];
int top1=-1,top2=capacity;
void push_stack1(int data){
    if(top2==top1+1){
        printf("Stack Overflow!!\n");
    }
    top1++;
    stack[top1]=data;
}
void push_stack2(int data){
     if(top2==top1+1){
        printf("Stack Overflow!!\n");
    }
    top2--;
    stack[top2]=data;
}
void pop_stack1(){
    if(top1==-1){
        printf("Underflow Condition!!\n");
    }
    top1--;
    printf("Popped Element is : %d\n",stack[top1]);
}
void pop_stack2(){
  if(top2==capacity){
    printf("Underflow Condition!!\n");
}
top2++;
printf("Popped element is : %d\n",stack[top2]);
}
void print_stack1 ()
{
  int i;
  for (i = top1; i >= 0; --i)
  {
    printf ("%d ", stack[i]);
  }
  printf ("\n");
}
void print_stack2 ()
{
  int i;
  for (i = top2; i < capacity; ++i)
  {
    printf ("%d ", stack[i]);
  }
  printf ("\n");
}
int main()
{
  int ar[capacity];  
  int i;  
  int num_of_ele;  
   
  printf ("We can push a total of 20 values\n");  
   
  //Number of elements pushed in stack 1 is 10  
  //Number of elements pushed in stack 2 is 10  
   
// loop to insert the elements into Stack1    
for (i = 1; i <= 10; ++i)  
  {  
    push_stack1(i);  
    printf ("Value Pushed in Stack 1 is %d\n", i);  
  }  
// loop to insert the elements into Stack2.    
for (i = 11; i <= 20; ++i)  
  {  
    push_stack2(i);  
    printf ("Value Pushed in Stack 2 is %d\n", i);  
  }  
   
  //Print Both Stacks  
  print_stack1 ();  
 print_stack2 ();  
   
  //Pushing on Stack Full  
  printf ("Pushing Value in Stack 1 is %d\n", 11);  
  push_stack1 (11);  
   
  //Popping All Elements from Stack 1  
  num_of_ele = top1 + 1;  
  while (num_of_ele)  
  {  
    pop_stack1 ();  
    --num_of_ele;  
  }  
   
  // Trying to Pop the element From the Empty Stack  
  pop_stack1 ();  
   
  return 0;  
}