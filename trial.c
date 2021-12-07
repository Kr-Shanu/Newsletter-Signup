#include<stdio.h>
#include<stdlib.h>  // header file for exit and return function
#define max 5       

int stack[max],top=-1;          // global variable.
int stack2[max],top2=-1;          // global variable of second stack.

void pushA();
void pushB();
int popA();
int popB();
void disp();

main()
{
    int w,r;        // w stand for your want and r for catch return value
    for(;;)         // for infinite loop 
    {
        printf("\n1. Push in A");
        printf("\n2. Push in B");
        printf("\n3. Pop from A");
        printf("\n4. Pop from B");
        printf("\n5. Display the Stack A ");
        printf("\n6. Display the Stack B ");
        printf("\n7. EXIT");
        printf("\n\nEnter what you want:");
        scanf("%d",&w);
        switch(w)
        {
        case 1:
            pushA();
            break;
        case 2:
            pushB();
            break;
        case 3:
            r=popA();
            break;
        case 4:
            r=popB();
            break;
        case 5:
            dispA();
            break;
        case 6:
            dispB();
            break;
        case 7:
            exit(1);
        default:
            printf("\nInvalid Choice !!\n");
        }
    }
}

void pushA()
{
    int num;
    if(top==max-1)
    {
        printf("\nStack is Full !\n"); 
        return;
    }
    else {
        printf("\nEnter a number for Insert:");
        scanf("%d",&num);
        top++;
        stack[top]=num;
    }
}

void pushB()
{
    int num;
    if(top2==max-1)
    {
        printf("\nStack is Full !\n"); 
        return;
    }
    else {
        printf("\nEnter a number for Insert:");
        scanf("%d",&num);
        top2++;
        stack2[top2]=num;
    }
}

int popA()
{
    int e;
    if(top==-1)
    {
        printf("\nStack is Empty !!\n");
        return;
    }
    else {
        e=stack[top];
        printf("\n%d was Deleted !\n",e);
        top--;
        return e;
    }

}
int popB()
{
    int e;
    if(top2==-1)
    {
        printf("\nStack is Empty !!\n");
        return;
    }
    else {
        e=stack2[top2];
        printf("\n%d was Deleted !\n",e);
        top2--;
        return e;
    }

}

void dispA()
{
    int i;
    if(top==-1){
        printf("\nNothing to Display !!\n");
        return;
    }
    else {
        printf("\n");
        for(i=top;i>=0;i--)
            printf("\n%d",stack[i]);
        printf("\n");
    }
}

void dispB()
{
    int i;
    if(top2==-1){
        printf("\nNothing to Display !!\n");
        return;
    }
    else {
        printf("\n");
        for(i=top2;i>=0;i--)
            printf("\n%d",stack2[i]);
        printf("\n");
    }
}
