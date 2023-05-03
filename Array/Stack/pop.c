#include<stdio.h>
#include<stdlib.h>

int top =-1,size;
void display(int a[]) {
   for (int i=top; i>=0; i--)
   {
      if(i == top)
        printf("\n ======\n");
      printf("|| %d ||\n", a[i]);
      printf(" ======\n");
    }
    printf("\n");
}

void push(int a[],int data){
    if (top == size-1)
        printf("Stack Overflow");
    top++;
    a[top] = data;
}

int pop(int a[]){
    int item;
    if (top == -1)
        printf("Stack Underflow");
    item = a[top];
    top--;
    return item;
}

int main(){
    int *stack,x,y,z;
    printf("Insert the size of Stack");
    scanf("%d",&size);
    stack = (int*)malloc(size*sizeof(int));
    printf("Enter the first value you want to insert : ");
    scanf("%d",&x);
    printf("Enter the second value you want to insert : ");
    scanf("%d",&y);
    printf("Enter the third value you want to insert : ");
    scanf("%d",&z);
    push(stack,x);
    push(stack,y);
    push(stack,z);
    display(stack);
   int a = pop(stack);
    printf("%d is removed from stack \n",a);
    display(stack);
    return 0;
}