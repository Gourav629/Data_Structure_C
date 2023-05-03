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
    int n=1,*stack,z;
    printf("Insert the size of Stack");
    scanf("%d",&size);
    stack = (int*)malloc(size*sizeof(int));
    push(stack,24);
    push(stack,22);
    push(stack,20);
    display(stack);
    z = pop(stack);
    printf("%d is poped ", z);
    display(stack);
    return 0;
}