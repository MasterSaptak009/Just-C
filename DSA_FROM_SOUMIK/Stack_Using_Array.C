#include <stdio.h>
#define capacity 5
int stack[capacity],top,choice,n,x,i;
void push(){
    if(top==capacity-1){
        printf("Overflow Condition");
    }
    else{
        printf("Enter the value to be pushed = ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("Underflow Condition");
    }
    else{
        printf("The popped element is = %d",stack[top]);
        top--;
    }
}
void display(){
    if(top==-1){
        printf("The stack is empty!!");
    }
    else{
        for(i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}
int main()
{
    top=-1;
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
     do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);

    return 0;
}